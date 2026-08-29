#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int bit=0;bit<32;bit++){
            int ones=0;
            for(int i:nums){
                ones+=(i>>bit)&1;
            }
            int zeroes=n-ones;
            ans+=ones*zeroes;
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
    cout<<obj.totalHammingDistance(nums)<<endl;
    return 0;
}