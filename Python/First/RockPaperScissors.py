import random

def who_wins(pc,me):
    result = ''
    if pc == me:
        result = 'draw'
    elif pc=='rock' or me=='rock':
        if pc=='paper' or me=='paper':
            result = 'paper'
        else:
            result = 'rock'
    elif pc=='paper' or me=='paper':
        if pc=='scissors' or me=='scissors':
            result = 'scissors'
        else:
            result = 'paper'
    elif pc=='scissors' or me=='scissors':
        if pc=='rock' or me=='rock':
            result = 'rock'
        else:
            result = 'scissors'
    return result

List = ['rock', 'paper', 'scissors']
pc = random.choice(List)
print(pc)
me = input("Choose:\n 1-rock\n 2-paper\n 3-scissors\n")

print(who_wins(pc,me))

