#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total=0;
        int currmax=0;
        int maxsum=nums[0];
        int currmin=0;
        int minsum=nums[0];
        for(int i:nums){
            currmax=max(i,currmax+i);
            maxsum=max(maxsum,currmax);
            currmin=min(currmin+i,i);
            minsum=min(currmin,minsum);
            total+=i;
        }
        if(maxsum<0){
            //all nos are negative
            return maxsum;
        }
        return max(maxsum,total-minsum);
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
    cout<<obj.maxSubarraySumCircular(nums)<<endl;
    return 0;
}