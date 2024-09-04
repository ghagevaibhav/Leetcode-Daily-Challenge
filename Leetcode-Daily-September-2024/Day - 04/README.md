# Algorithm and Complexity Explanation

## Problem Overview
The problem involves simulating a robot's movement on a 2D grid. The robot starts at position (0, 0) and can move based on a series of commands. The commands include turning left, turning right, and moving forward by a specified number of steps. The grid also contains obstacles, which the robot must avoid. The objective is to determine the maximum Euclidean distance squared that the robot achieves from the origin during its movement.

## Algorithm Explanation

### Step 1: Initialize Variables
- Start by initializing the robot's position at `(i, j) = (0, 0)`.
- Set the initial direction of the robot to `1` (North).
- Initialize a variable `res` to store the maximum Euclidean distance squared from the origin.

### Step 2: Store Obstacles in a Set
- Convert the list of obstacle coordinates into a set `st` for fast lookup. This allows checking whether a cell is an obstacle in constant time.

### Step 3: Process Each Command
- Loop through each command in the `commands` vector:
  - **Turning Right (`-1`)**: Increase the direction by 1 (modulo 4) to simulate a right turn. Adjust if necessary to stay within the range 1 to 4.
  - **Turning Left (`-2`)**: Decrease the direction by 1 to simulate a left turn. Adjust if necessary to stay within the range 1 to 4.
  - **Moving Forward**:
    - Move the robot in the current direction by the number of steps specified in the command.
    - For each step, check if the next position contains an obstacle by looking it up in the set. If an obstacle is encountered, stop moving in that direction.
    - After each move, update the maximum Euclidean distance squared from the origin.

### Step 4: Return the Result
- After processing all commands, return the maximum Euclidean distance squared that the robot achieved.

## Complexity Analysis

### Time Complexity
- **Initialization**: Initializing variables and converting the obstacle list to a set takes `O(k)` time, where `k` is the number of obstacles.
- **Processing Commands**: Each command is processed in `O(1)` time. Moving forward involves at most `O(n)` operations, where `n` is the sum of all forward movement commands. Checking for obstacles takes `O(1)` time due to the set data structure.
- **Overall Time Complexity**: `O(k + n)` where `k` is the number of obstacles and `n` is the total number of forward movement steps.

### Space Complexity
- **Set for Obstacles**: The set `st` takes `O(k)` space, where `k` is the number of obstacles.
- **Other Variables**: The other variables use `O(1)` space.
- **Overall Space Complexity**: `O(k)`.

The algorithm efficiently handles the robot's movement and obstacle avoidance while ensuring the maximum distance calculation is accurate.
