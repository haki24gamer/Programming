import datetime
import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    infos = db.execute("SELECT symbol, SUM(shares) as shares, price, SUM(shares*price) as total FROM transactions WHERE user_id = ? GROUP BY symbol", session["user_id"])
    
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]
    
    total = cash+sum([info["total"] for info in infos])
    for info in infos:
        info["total"] = usd(info["total"])
        info["price"] = usd(info["price"])
        # add the name of the stock to the info
        info["name"] = lookup(info["symbol"])["name"]
        


    return render_template("index.html", infos=infos, Cash=usd(cash), Total=usd(total))

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")
    else:
        quote = lookup(request.form.get("symbol"))
        if not quote:
            return apology("Invalid stock symbol", 403)
        
        shares = request.form.get("shares")
        if not shares:
            return apology("Please enter a shares number", 403)
        elif int(shares) < 0:
            return apology("Please enter a positive shares number", 403)
        
        stock_price = quote["price"]
        user_wealth = db.execute("SELECT cash FROM users")

        # Check if the user has enough money to buy the stock
        if user_wealth[0]["cash"] < stock_price * int(shares):
            return apology("You don't have enough money to buy this stock", 403)
        
        # Update the user's cash
        if user_wealth[0]["cash"] - stock_price * int(shares) >= 0:
            db.execute("UPDATE users SET cash = ? WHERE id = ?", user_wealth[0]["cash"] - stock_price * int(shares), session["user_id"])
        else:
            return apology("You don't have enough money to buy this stock", 403)

        # Keep track of who bought what at what price and when in a table called transactions
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES (?, ?, ?, ?, ?)", session["user_id"], quote["symbol"], shares, stock_price, datetime.datetime.now())

        return redirect("/")
    


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    transactions = db.execute("SELECT symbol, shares, price, date FROM transactions WHERE user_id = ?", session["user_id"])
    # Add the type of the transaction to the transactions
    for transaction in transactions:
        if transaction["shares"] > 0:
            transaction["type"] = "Bought"
        else:
            transaction["type"] = "Sold"
            transaction["shares"] = -transaction["shares"]
        
    # Add the price in USD to the transactions
    for transaction in transactions:
        transaction["price"] = usd(transaction["price"])
    return render_template("history.html", transactions=transactions)
    


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    
    else:
        quote = lookup(request.form.get("symbol"))
        if quote:
            return render_template("quoted.html", name=quote["name"], price=usd(quote["price"]), symbol=quote["symbol"])
        else:
            return apology("Invalid stock symbol", 403)


    


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # User reached route via GET (as by clicking a link or via redirect)
    if request.method == "GET":
        return render_template("register.html")
    # User reached route via POST (as by submitting a form via POST)
    else:
        username = request.form.get("username")
        # Ensure a valid username was submitted
        if not username:
            return apology("must provide username", 403)
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))
        if len(rows) != 0:
            return apology("username already exists", 403)
        
        password = request.form.get("password")
        # Ensure a valid password was submitted
        if not password:
            return apology("must provide password", 403)
        confirmation = request.form.get("confirmation")
        # Ensure password and confirmation match
        if password != confirmation:
            return apology("passwords do not match", 403)
        
        # Insert the new user into users, storing the hash of the user's password
        db.execute("INSERT INTO users(username, hash) VALUES (?, ?)", request.form.get("username"), generate_password_hash(request.form.get("password")))
        return redirect("/")
        


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "GET":
        return render_template("sell.html")
    else:
        quote = lookup(request.form.get("symbol"))
        if not quote:
            return apology("Invalid stock symbol", 403)
        
        shares = request.form.get("shares")
        if not shares:
            return apology("Please enter a shares number", 403)
        elif int(shares) < 0:
            return apology("Please enter a positive shares number", 403)
        
        stock_price = quote["price"]
        user_shares = db.execute("SELECT SUM(shares) as shares FROM transactions WHERE user_id = ? AND symbol = ?", session["user_id"], quote["symbol"])[0]["shares"]
        if not user_shares or int(shares) > int(user_shares):
            return apology("You don't have enough shares to sell", 403)
        
        # Update the user's cash
        user_wealth = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        db.execute("UPDATE users SET cash = ? WHERE id = ?", user_wealth[0]["cash"] + stock_price * int(shares), session["user_id"])
        
        # Keep track of who bought what at what price and when in a table called transactions
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES (?, ?, ?, ?, ?)", session["user_id"], quote["symbol"], -int(shares), stock_price, datetime.datetime.now())
        
        return redirect("/")

@app.route("/add_cash", methods=["GET", "POST"])
@login_required
def add_cash():
    """Add cash to the user's account"""
    if request.method == "GET":
        return render_template("add_cash.html")
    else:
        cash = request.form.get("cash")
        if not cash:
            return apology("Please enter a cash amount", 403)
        elif float(cash) < 0:
            return apology("Please enter a positive cash amount", 403)
        
        # Verify the credit card number and it's code
        if not request.form.get("credit_card_number") or not request.form.get("credit_card_code"):
            return apology("Please enter a credit card number and its code", 403)
        
        # Update the user's cash
        user_wealth = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        db.execute("UPDATE users SET cash = ? WHERE id = ?", user_wealth[0]["cash"] + float(cash), session["user_id"])
        
        return redirect("/")