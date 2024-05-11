## Algorithm Steps

1. **Find Character Index**:
   - Find the index of the character `ch` in the input string `word`.

2. **Reverse Prefix**:
   - If the character `ch` is found in the word:
     - Reverse the prefix of the word until the character `ch` using the `reverse` function.

3. **Return Modified Word**:
   - Return the modified word after reversing the prefix (if `ch` is found), or return the original word if `ch` is not found.

## Time Complexity

- Finding the index of character `ch` using `find`: O(n), where n is the length of the word.
- Reversing the prefix using `reverse`: O(n), where n is the length of the prefix.
- Overall time complexity: O(n)

## Space Complexity

- Additional space used for variables: O(1)
- Overall space complexity: O(1)
