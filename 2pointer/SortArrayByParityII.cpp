#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even=0;
        int odd=1;
        int n=nums.size();
        while(even<n && odd<n){
            while(even<n && nums[even]%2==0){
                even+=2;
            }
            while(odd<n && nums[odd]%2!=0){
                odd+=2;
            }
            if(even<n && odd<n){
                swap(nums[even],nums[odd]);
                even+=2;
                odd+=2;
            }
        }
        return nums;
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
    vector<int> ans=obj.sortArrayByParityII(nums);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}