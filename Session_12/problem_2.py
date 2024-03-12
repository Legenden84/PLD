import random

DICE = 12
PERMUTATION = DICE ** DICE

def roll_dice(DICE):
    return random.randrange(1, DICE+1)

rolls = []

for i in range(12):
    rolls.append(roll_dice(DICE))

