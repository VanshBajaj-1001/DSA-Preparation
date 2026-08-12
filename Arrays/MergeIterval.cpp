#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> newinterval;
        for(int i=0;i<intervals.size();i++){
            if(newinterval.empty() || newinterval.back()[1]<intervals[i][0]){
                newinterval.push_back(intervals[i]);
            }
            else{
                newinterval.back()[1]=max(newinterval.back()[1],intervals[i][1]);
            }
        }
        return newinterval;
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
    vector<vector<int>> ans=obj.merge(intervals);
    for(auto i:ans){
        cout<<"["<<i[0]<<","<<i[1]<<"]";
    }
    return 0;
}