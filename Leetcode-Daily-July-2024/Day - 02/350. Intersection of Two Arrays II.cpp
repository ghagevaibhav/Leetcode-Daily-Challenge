class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;  // Vector to store the intersection result
        
        // Sort both input vectors
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0;  // Pointers for nums1 and nums2 respectively
        int m = nums1.size(), n = nums2.size();  // Sizes of nums1 and nums2
        
        // Two-pointer approach to find intersection
        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                i++;  // Move pointer in nums1 if its element is smaller
            }
            else if(nums2[j] < nums1[i]){
                j++;  // Move pointer in nums2 if its element is smaller
            }
            else{
                ans.push_back(nums1[i]);  // Add to result if elements are equal
                i++, j++;  // Move both pointers
            }
        }
        
        return ans;  // Return the intersection result
    }
};
