# Question
Calculate the probability when rolling 12d12. that the second highest roll will be 9.

```python
from math import comb

# Recalculate the favorable outcomes with the corrected code
favorable_outcomes = 0

for higher_than_target in range(10, sides_per_die + 1):  # Loop through values higher than 9 (10, 11, 12)
    # Count how many ways at least one die is exactly 9, and at least one die is higher
    for dice_with_9 in range(1, total_dice):  # At least one die, up to total_dice - 1, can be 9
        # Calculate the number of combinations for selecting dice to be 9 and higher than target
        combinations_for_9_and_higher = comb(total_dice, dice_with_9) * comb(total_dice - dice_with_9, 1)
        # Calculate the permutations for the rest of the dice (values 1 through 8)
        permutations_for_rest = 8 ** (total_dice - dice_with_9 - 1)
        
        # Add to favorable outcomes
        favorable_outcomes += combinations_for_9_and_higher * permutations_for_rest * 3  # Multiply by 3 for the three higher options

# Calculate the probability
probability = favorable_outcomes / total_outcomes
```