# Abhimanyu in Chakravyuha - Problem

## Problem Statement

Abhimanyu is trapped in a Chakravyuha consisting of 11 concentric circles, each guarded by an enemy with specific power levels. Abhimanyu must cross all 11 circles to reach the Pandavas' army. The task is to determine if Abhimanyu can successfully navigate through all circles given his initial power and certain abilities.

### Problem Details

- **Input:**
  - An array representing the power levels of enemies in the 11 circles: `[k1, k2, ..., k11]`.
  - Abhimanyu's initial power: `p`.
  - The number of times Abhimanyu can skip battles: `a`.
  - The number of times Abhimanyu can recharge his power: `b`.

- **Conditions:**
  - Abhimanyu loses power equal to the enemy's power level when battling.
  - If Abhimanyu's power is less than the enemy's power, he loses the battle unless he skips it.
  - Enemies in circles 3 and 7 can regenerate with half their initial power and attack from behind while Abhimanyu is in the next circle.

- **Goal:**
  - Determine if Abhimanyu can cross all 11 circles and reach the Pandavas' army.

## Solution Overview

The algorithm simulates Abhimanyu's journey through the Chakravyuha, taking into account his initial power, the number of skips, and recharges available. It also handles the special regeneration ability of enemies in circles 3 and 7.

### Steps:
1. Traverse each circle and evaluate if Abhimanyu has sufficient power to battle.
2. Apply skips (`a`) to avoid battles when necessary.
3. Recharge (`b`) when Abhimanyu's power is low.
4. Handle the regeneration and back attack of enemies in circles 3 and 7.

## Test Cases

The solution is tested with the following cases:

### Test Case 1:
- **Initial Power (`p`):** 200
- **Skips (`a`):** 5
- **Recharges (`b`):** 3
- **Enemy Powers (`k`):** `[150, 80, 170, 100, 90, 110, 180, 130, 120, 140, 160]`
- **Expected Output:** Abhimanyu can cross the Chakravyuh: **WON**

### Test Case 2:
- **Initial Power (`p`):** 100
- **Skips (`a`):** 2
- **Recharges (`b`):** 2
- **Enemy Powers (`k`):** `[4, 12, 24, 32, 36, 42, 52, 60, 66, 76, 84]`
- **Expected Output:** Abhimanyu cannot cross the Chakravyuh: **LOST**
