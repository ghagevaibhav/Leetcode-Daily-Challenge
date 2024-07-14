## Algorithm Explanation and Complexity Analysis

### Algorithm Explanation

1. **Initialization:**
   - Initialize `n` to the length of the formula string.
   - Create an empty unordered map `result_counter` to store the final counts of each atom.
   - Create a stack `parenthesis_stack` to handle nested parentheses.
   - Initialize `cur_ind` to 0 to keep track of the current index in the formula string.

2. **Processing the Formula String:**
   - Iterate through the formula string using a while loop until `cur_ind` is less than `n`.

3. **Handling Opening Parentheses '(' :**
   - If the current character is '(', increment `cur_ind`.
   - Push a new empty unordered map onto the `parenthesis_stack`.

4. **Handling Closing Parentheses ')' :**
   - If the current character is ')', initialize an empty string `mult_str` and increment `cur_ind`.
   - Extract the multiplier after the closing parenthesis if it exists.
   - Convert the multiplier string to an integer (`mult`). If `mult_str` is empty, default the multiplier to 1.
   - Pop the top map from the `parenthesis_stack` and multiply each element's count by the multiplier.
   - Add the multiplied counts to the target map, which is either the `result_counter` or the map on top of the `parenthesis_stack` if it exists.

5. **Handling Element Names and Counts:**
   - Initialize `cur_elem` as an empty string to store the current element name.
   - Initialize `cur_counter_str` as an empty string to store the current element's count as a string.
   - Determine the target map (`result_counter` or the map on top of the `parenthesis_stack` if it exists).
   - Parse the element names and their counts.
   - If an uppercase letter is encountered and `cur_elem` is not empty, update the target map with the current element and its count, then reset `cur_elem` and `cur_counter_str`.
   - Add the last parsed element and its count to the target map.

6. **Generating the Result:**
   - Create a vector `parts` to store the result parts.
   - Convert each entry in the `result_counter` to a string and add it to the `parts` vector.
   - Sort the `parts` vector lexicographically.
   - Concatenate the sorted parts into the final result string.

7. **Return the Result:**
   - Return the final result string.

### Complexity Analysis

- **Time Complexity:**
  - The algorithm processes each character of the formula string exactly once, resulting in a time complexity of O(n), where n is the length of the formula string.
  - Sorting the elements in the result map takes O(m log m) time, where m is the number of unique elements.

- **Space Complexity:**
  - The space complexity is O(m) for storing the counts of the unique elements in the result map.
  - The stack used for handling nested parentheses can grow up to O(p), where p is the maximum depth of nested parentheses in the formula.
  - Overall, the space complexity is O(m + p).
