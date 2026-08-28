#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int l=0;
        int ans=INT_MAX;
     for(int r=0;r<nums.size();r++){
        sum+=nums[r];
        while(sum>=target){
            ans=min(ans,r-l+1);
            sum-=nums[l];
            l++;
        }
     }
     if(ans==INT_MAX){
        return 0;
     }
     return ans;
    }
};
int main(){
    Solution obj;
    int target;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>target;
    cout<<obj.minSubArrayLen(target,nums)<<endl;
    return 0;
    
}