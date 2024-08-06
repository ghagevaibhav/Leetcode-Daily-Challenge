# Algorithm and Complexity Explanation

## Algorithm

1. **Initialize Frequency Array**:
   - Create a vector `letterFreq` of size 26 initialized to zero to count the frequency of each letter in the given word.
   - This ensures that we can count the occurrence of each letter efficiently.

2. **Calculate Frequencies**:
   - Iterate through each character `c` in the string `word`.
   - For each character, increment the corresponding index in `letterFreq` using `letterFreq[c - 'a']++`.

3. **Sort Frequencies**:
   - Sort the `letterFreq` vector in descending order using `sort(letterFreq.rbegin(), letterFreq.rend())`.
   - This step helps in allocating the most frequent letters to positions with the least key presses required.

4. **Calculate Total Key Presses**:
   - Initialize a variable `totalPresses` to zero to accumulate the total number of key presses needed.
   - Iterate over the sorted frequency array using a for loop.
     - For each frequency `letterFreq[i]`, if it is zero, break the loop as there are no more letters to process.
     - Calculate the key presses required for each letter using the formula `(i / 8 + 1) * letterFreq[i]`:
       - `i / 8` gives the row number (0-indexed) in the 3x8 grid.
       - `+1` adjusts it to 1-indexed for the number of key presses.
       - Multiply by `letterFreq[i]` to account for the frequency of the letter.

5. **Return Result**:
   - Return the accumulated value of `totalPresses` which represents the minimum number of key presses needed to type the given word.

## Complexity

### Time Complexity

1. **Frequency Calculation**:
   - Iterating through the string `word` takes O(n) time, where n is the length of the word.

2. **Sorting Frequencies**:
   - Sorting the frequency array takes O(26 log 26) time, which simplifies to O(1) since the size of the array is constant (26).

3. **Calculating Total Key Presses**:
   - Iterating over the frequency array and calculating the total key presses takes O(26), which simplifies to O(1) due to the constant size of the array.

Overall, the time complexity is O(n) due to the linear pass through the input string.

### Space Complexity

1. **Frequency Array**:
   - The `letterFreq` array requires O(26) space, which simplifies to O(1) as it is a constant size.
   
2. **Input Storage**:
   - The input string `word` requires O(n) space, where n is the length of the word.

Overall, the space complexity is O(n) due to the input string storage.
