#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum%k;
            if(mp.count(rem)){
                if(i-mp[rem]>=2){
                    return true;
                }
            }
            else{
                mp[rem]=i;
            }
        }
        return false;
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
if(obj.checkSubarraySum(nums,k)){
    cout<<"True";
}
else{
    cout<<"False";
}
return 0;
}