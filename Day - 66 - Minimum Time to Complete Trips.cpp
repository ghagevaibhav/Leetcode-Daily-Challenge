class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans=-1;
        
        long long l=1, r= 100000000000001;          
		
        while(l<=r){
            long long mid= l+ (r-l)/2;  
            long long curr_trips=0;
            for(int t: time){
                curr_trips+= mid/t;
            }
            
            if(curr_trips>=totalTrips){ 
                ans=mid;
                r=mid-1;
            }
            
            else{
                l=mid+1;
            }
        }
        
        return ans;
    }
};
