#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int end=intervals[0][1];
        int cnt=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<end){
                cnt++;
            }
            else{
                end=intervals[i][1];
            }
        }
        return cnt;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
      vector<vector<int>> intervals(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>intervals[i][0]>>intervals[i][1];
    }
    cout<<obj.eraseOverlapIntervals(intervals);
    return 0;
}