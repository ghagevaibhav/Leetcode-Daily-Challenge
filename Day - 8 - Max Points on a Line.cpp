✅ [C++]Easy|| BEATS Approx 100% ||Explanation ✅
✅ [C++]Easy|| BEATS Approx 100% ||Explanation ✅
10.2K
VIEWS
114
Last Edit: 5 hours ago

vishnoi29
vishnoi29
 671
Intuition
Here we will calculate the slope
Approach
Idea is very simple

We will select point and for every selected point we will calculate the slope wr.t to another point and store into the map
In map we will store <slope,that selected point>
for example we have point :-[[1,1],[2,2],[3,3]......
we pick point [1,1]and for that [1,1] we will calculate the slope
w.r.t [2,2] ,[3,3]....... and store like this-
for understanding purpose i'm writing
mp[slope1,[1,1]]
mp[slope2,[1,1]]
mp[slope1,[1,1]].........
This type we will store the slope for [2,2] , [3,3],....
Ater storing the slope into map we will calculate the max point for that slope
For example after storing the slope map can look like this
[2/3,3]
[INF,1]//for perpendicular case
[1/3,2]...
find the max number of points having the same slope w.r.t. that selected point :-means which slope have maximum point
:- here 2/3 have 3 point so our answer will be 3+1(we are adding that point as well)
maxpointupdate.png
Code
class Solution {
public:
    int maxPoints(vector<vector<int>>& pt) {
        int ans=1; 
        int n=pt.size();
       
        for(int i=0;i<n-1;i++){
            map<double,int> mp;
            for(int j=i+1;j<n;j++){
            
                double x = (double)(pt[j][1]-pt[i][1])/(double)(pt[j][0]-pt[i][0]);
                if(pt[j][1]-pt[i][1]<0 &&(pt[j][0]-pt[i][0])==0 ) //infinite slop for Perpendicular line
                mp[abs(x)]++; 
                else
                    mp[x]++;
            }
            int temp = 0;
            for(auto it:mp)
                temp = max(temp, it.second+1);    // +1 for the current point(point itself)
            ans = max(temp, ans);
        }
        return ans;
    }
};
