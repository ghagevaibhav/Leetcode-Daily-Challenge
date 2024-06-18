# Maximum Profit Assignment Algorithm

## Algorithm Explanation

1. **Initialization**:
    - Create a vector of pairs `jobs` where each pair consists of a job's difficulty and its profit.
    - Sort `jobs` based on difficulty.
    - Sort the `worker` array based on workers' abilities.

2. **Assigning Jobs to Workers**:
    - Initialize three variables: `job` to track the current job index, `curProfit` to keep track of the maximum profit available up to the current job, and `totalProfit` to accumulate the total profit.
    - Iterate through each worker in the sorted `worker` array:
        - While there are jobs available and the current worker can handle the job's difficulty, update `curProfit` to the maximum profit seen so far for the current job index, and move to the next job.
        - Add `curProfit` to `totalProfit`.

3. **Return the Result**:
    - Return `totalProfit` which represents the maximum total profit all workers can achieve.

## Complexity Analysis

- **Time Complexity**:
    - Sorting the `jobs` vector takes \(O(n \log n)\).
    - Sorting the `worker` array takes \(O(m \log m)\).
    - The main loop that matches workers to jobs takes \(O(n + m)\) in the worst case because each job and each worker is processed at most once.
    - Overall, the time complexity is \(O(n \log n + m \log m)\).

- **Space Complexity**:
    - The space complexity is \(O(n)\) for storing the `jobs` vector.

## Step-by-Step Example

Consider the following example:
- `difficulty = [2, 4, 6, 8, 10]`
- `profit = [10, 20, 30, 40, 50]`
- `worker = [4, 5, 6, 7]`

1. **Initialization**:
    - Create `jobs = [(2, 10), (4, 20), (6, 30), (8, 40), (10, 50)]`.
    - Sort `jobs` (already sorted in this case).
    - Sort `worker = [4, 5, 6, 7]`.

2. **Assigning Jobs to Workers**:
    - Initialize `job = 0`, `curProfit = 0`, `totalProfit = 0`.
    - Iterate through each worker:
        - For `worker[0] = 4`:
            - `worker[0] >= jobs[0].first (2)`: update `curProfit = max(0, 10) = 10`, increment `job`.
            - `worker[0] >= jobs[1].first (4)`: update `curProfit = max(10, 20) = 20`, increment `job`.
            - Add `curProfit (20)` to `totalProfit = 20`.
        - For `worker[1] = 5`:
            - No new jobs can be handled (since `job` is already at a higher difficulty than the worker).
            - Add `curProfit (20)` to `totalProfit = 40`.
        - For `worker[2] = 6`:
            - `worker[2] >= jobs[2].first (6)`: update `curProfit = max(20, 30) = 30`, increment `job`.
            - Add `curProfit (30)` to `totalProfit = 70`.
        - For `worker[3] = 7`:
            - No new jobs can be handled (since `job` is already at a higher difficulty than the worker).
            - Add `curProfit (30)` to `totalProfit = 100`.

3. **Result**:
    - Return `totalProfit = 100`.
