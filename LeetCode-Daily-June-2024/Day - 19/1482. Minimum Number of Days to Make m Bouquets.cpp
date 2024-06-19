class Solution {
public:
    // Function to check if it's possible to make 'm' bouquets with 'k' consecutive flowers blooming 
    // on or before the 'mid' day.
    bool isOkay(int mid, vector<int>& b, int m, int k) {
        int consec = 0; // Counter for consecutive flowers that are ready to bloom
        int num = 0;    // Counter for number of bouquets
        int n = b.size(); // Total number of flowers

        // Iterate through each flower's bloom day
        for(int i = 0; i < n; i++) {
            // If the current flower blooms on or before 'mid' day, increase the consecutive counter
            if(b[i] <= mid) consec++;
            else consec = 0; // Reset consecutive counter if the current flower blooms after 'mid' day

            // If we have 'k' consecutive flowers, we've made one bouquet
            if(consec == k) {
                num++;
                consec = 0; // Reset consecutive counter after making a bouquet
            }
        }
        // Return true if we can make at least 'm' bouquets, otherwise false
        return (num >= m);
    }

    // Main function to find the minimum number of days needed to make 'm' bouquets
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(); // Total number of flowers

        // If it's impossible to make 'm' bouquets, return -1
        if((long)m * k > n) return -1;

        // Initialize binary search bounds
        int l = 1; // Minimum possible day
        int r = *max_element(bloomDay.begin(), bloomDay.end()); // Maximum possible day
        int ans = -1; // Variable to store the answer

        // Binary search to find the minimum number of days
        while(l <= r) {
            int mid = (l + r) / 2; // Middle day
            // If it's possible to make 'm' bouquets by 'mid' day
            if(isOkay(mid, bloomDay, m, k)) {
                ans = mid; // Update answer
                r = mid - 1; // Try to find a smaller possible day
            } else {
                l = mid + 1; // Increase the day if it's not possible by 'mid' day
            }
        }
        return ans; // Return the minimum number of days needed
    }
};
