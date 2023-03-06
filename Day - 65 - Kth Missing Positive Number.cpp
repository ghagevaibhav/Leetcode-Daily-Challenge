#include <vector>
class Solution 
{
public:
     int findKthPositive(vector<int>& A, int k) 
    {
       int low = 0;
       int high = A.size()-1 ;
       int mid;
       while (low <= high) 
       {
            mid = (low + high) / 2;
            if (A[mid] - (1 + mid) < k)  
                low = mid + 1;
            else
                high = mid-1;
        }
        return low + k;
    }
};
