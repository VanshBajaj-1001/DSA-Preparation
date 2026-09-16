#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum=0;
        for(int a: nums){
            totalSum+=a;
        }
        int leftSum=0;
        for(int i=0;i<nums.size();i++){
            int rightSum=totalSum-leftSum-nums[i];
            if(rightSum==leftSum){
                return i;
            }
            leftSum+=nums[i];
        }
        return -1;
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
    int i=obj.pivotIndex(nums);
    cout<<i<<"th Index";
    return 0;
}