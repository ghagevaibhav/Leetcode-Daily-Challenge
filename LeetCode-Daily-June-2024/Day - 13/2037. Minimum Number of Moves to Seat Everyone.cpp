class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // Sort the seats and students vectors
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int ans = 0; // Initialize the answer to 0

        // Iterate over the sorted vectors and calculate the total minimum moves
        for(int i = 0; i < seats.size(); i++) {
            // Add the absolute difference between the current seat and student positions to the answer
            ans += abs(seats[i] - students[i]);
        }

        return ans; // Return the total minimum moves
    }
};
