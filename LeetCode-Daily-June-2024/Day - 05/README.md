# Algorithm

1. **Initialization**:
   - Create a vector `min_freq` of size 26, initialized to `INT_MAX`. This will store the minimum frequency of each character across all words.

2. **Iterate Over Each Word**:
   - For each word in the input list `words`:
     - Create a frequency vector `freq` of size 26, initialized to 0. This will store the frequency of each character in the current word.
     - For each character `c` in the word, increment the corresponding index in the `freq` vector (`freq[c - 'a']++`).

3. **Update Minimum Frequency Vector**:
   - For each character (from 'a' to 'z'), update `min_freq[i]` to be the minimum of its current value and `freq[i]`. This ensures `min_freq` will hold the smallest count of each character found in any word.

4. **Build Result Vector**:
   - Initialize an empty result vector `result`.
   - For each index `i` in `min_freq` (from 0 to 25), if the frequency is greater than 0, add the character (`i + 'a'`) to the result vector as many times as its frequency.

5. **Return Result**:
   - Return the `result` vector, which contains the common characters across all input words.

# Complexity Analysis

**Time Complexity**:
- Let `n` be the number of words and `k` be the average length of the words.
- The outer loop iterates over each of the `n` words.
- For each word, we count the frequency of characters, which takes `O(k)` time.
- Updating the `min_freq` vector for each word takes `O(26) = O(1)` time, as it has a fixed size of 26.
- Thus, the total time complexity is `O(n * k)`.

**Space Complexity**:
- The `min_freq` vector takes `O(26) = O(1)` space.
- The `freq` vector for each word also takes `O(26) = O(1)` space.
- The result vector can contain at most `n * k` characters in the worst case.
- Therefore, the overall space complexity is `O(n * k)`.
