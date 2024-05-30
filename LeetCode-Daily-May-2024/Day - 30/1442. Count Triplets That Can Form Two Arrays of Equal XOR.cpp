class Solution {
public:
    int countTriplets(vector<int>& A) {
        // Insert a 0 at the beginning of the vector A to handle prefix XOR calculations
        A.insert(A.begin(), 0);

        // Get the size of the modified vector A
        int n = A.size(), res = 0;

        // Compute prefix XOR for each element in the vector
        // A[i] now represents the XOR of all elements from the beginning to index i-1 in the original array
        for (int i = 1; i < n; ++i)
            A[i] ^= A[i - 1];

        // Iterate over all pairs (i, j) with i < j
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                // If the prefix XOR values are the same, it means the XOR of the subarray from i to j-1 is 0
                // Therefore, we can form triplets (i, k, j) with i < k < j
                // There are j - i - 1 possible values for k
                if (A[i] == A[j])
                    res += j - i - 1;

        // Return the total count of triplets
        return res;
    }
};
