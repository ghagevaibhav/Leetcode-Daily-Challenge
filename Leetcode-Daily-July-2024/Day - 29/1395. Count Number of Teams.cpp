class Solution {
public:
    int numTeams(std::vector<int>& arr) {
        int n = arr.size(); // Get the size of the input array
        int result = 0; // Initialize the result to store the number of teams

        // Loop through each element in the array except the first and last one
        for(int i = 1 ; i < n-1 ; i++){
            int leftSmall = 0, leftLarge = 0; // Counters for elements on the left of arr[i]
            int rightSmall = 0, rightLarge = 0; // Counters for elements on the right of arr[i]

            // Count elements on the left side of arr[i]
            for(int j = 0 ; j < i ; j++){
                if(arr[j] < arr[i]){
                    leftSmall++; // Increment leftSmall if arr[j] is smaller than arr[i]
                }
                if(arr[j] > arr[i]){
                    leftLarge++; // Increment leftLarge if arr[j] is larger than arr[i]
                }
            }

            // Count elements on the right side of arr[i]
            for(int j = i+1 ; j < n ; j++){
                if(arr[j] < arr[i]){
                    rightSmall++; // Increment rightSmall if arr[j] is smaller than arr[i]
                }
                if(arr[j] > arr[i]){
                    rightLarge++; // Increment rightLarge if arr[j] is larger than arr[i]
                }
            }

            // Calculate the number of teams that can be formed with arr[i] as the middle element
            result += leftSmall * rightLarge + leftLarge * rightSmall;
        }

        return result; // Return the total number of teams
    }
};
