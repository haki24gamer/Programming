import d
import time

# Set up the screen
wn = turtle.Screen()
wn.title("Snake Game")
wn.bgcolor("green")
wn.setup(width=600, height=600)

# Draw the snake
snake = turtle.Turtle()
snake.color("white")
snake.speed(0)
snake.shape("square")
snake.penup()

# Initialize variables for the game
delay = 0.1

# Move the snake
while True:
    snake.forward(10)
    time.sleep(delay)

turtle.done()