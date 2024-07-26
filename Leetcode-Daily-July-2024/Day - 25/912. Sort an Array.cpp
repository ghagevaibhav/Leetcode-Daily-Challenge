class Solution {
public:
    // This function inserts an element 'temp' into its correct position
    // within the sorted part of the 'nums' vector.
    // void insert(vector<int>& nums, int temp){
    //     if(nums.size() == 0 || nums.back() <= temp){
    //         // If the vector is empty or the last element is less than or equal to 'temp',
    //         // append 'temp' to the end of the vector.
    //         nums.push_back(temp);
    //         return;
    //     }
    //     // Otherwise, pop the last element from the vector and recursively insert 'temp'.
    //     int val = nums.back();
    //     nums.pop_back();
    //     insert(nums, temp);
    //     // After inserting 'temp', push 'val' back into the vector.
    //     nums.push_back(val);
    // }
    
    // This function sorts the 'nums' vector using the 'insert' function.
    // void sort(vector<int>& nums){
    //     int n = nums.size();
    //     // If the vector has only one element, it is already sorted.
    //     if(n == 1){
    //         return;
    //     }
    //     // Remove the last element and store it in 'temp'.
    //     int temp = nums[n-1];
    //     nums.pop_back();
    //     // Recursively sort the remaining elements.
    //     sort(nums);
    //     // Insert the removed element 'temp' back into its correct position.
    //     insert(nums, temp);
    // }
    
    // This function sorts the 'nums' vector using the built-in sort function.
    vector<int> sortArray(vector<int>& nums) {
        // The built-in sort function from the standard library is used to sort the vector.
        sort(nums.begin(), nums.end());
        // Return the sorted vector.
        return nums;
    }
};
