#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int l=0;
        int zeroes=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]==0){
                zeroes++;
            }
            while(zeroes>k){
                if(nums[l]==0){
                    zeroes--;
                }
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
     vector<int> nums(n);
     for(int i=0;i<n;i++){
        cin>>nums[i];
     }
     int k;
     cin>>k;
     cout<<obj.longestOnes(nums,k)<<endl;
     return 0;
}