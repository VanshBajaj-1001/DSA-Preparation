#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currmax=0;
        int currmin=0;
        int maxsum=0;
        int minsum=0;
        for(int i:nums){
            currmax=max(i,i+currmax);
            maxsum=max(maxsum,currmax);
            currmin=min(i,i+currmin);
            minsum=min(minsum,currmin);
        }
        return max(maxsum,abs(minsum));
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
    cout<<obj.maxAbsoluteSum(nums);
    return 0;
}