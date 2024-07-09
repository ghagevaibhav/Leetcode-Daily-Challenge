# Algorithm and Complexity Explanation

## Algorithm

The algorithm calculates the average waiting time for customers at a restaurant. Here's how it works:

1. Initialize variables:
   - `n`: number of customers
   - `total`: sum of all waiting times
   - `av`: time when the chef is available to start a new order

2. Iterate through each customer:
   - Extract `arrival` time and food preparation time `t`
   - Update `av`:
     - If `av` < `arrival`, set `av = arrival` (chef was idle)
     - If `av` >= `arrival`, keep `av` (chef was busy)
   - Add food preparation time `t` to `av`
   - Calculate waiting time: `av - arrival`
   - Add this waiting time to `total`

3. Calculate and return the average waiting time: `total / n`

## Time Complexity

- The algorithm iterates through the customer list once: O(n)
- All operations inside the loop are O(1)
- Therefore, the overall time complexity is O(n), where n is the number of customers

## Space Complexity

- The algorithm uses a constant amount of extra space (variables `n`, `total`, `av`)
- It doesn't create any data structures that grow with input size
- Thus, the space complexity is O(1) (constant space)

## Correctness

The algorithm correctly calculates waiting times by:
1. Ensuring the chef doesn't start cooking before a customer arrives
2. Accounting for busy periods where customers might have to wait for the chef to finish previous orders
3. Summing up all individual waiting times and dividing by the number of customers for the average

This approach handles various scenarios like immediate service, waiting due to the chef being busy, and idle periods between customers.
