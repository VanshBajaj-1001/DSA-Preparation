#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            while(l<r && nums[l]%2==0){
            l++;
            }
            while(l<r && nums[r]%2!=0){
                r--;
            }
            if(l<r){
                swap(nums[l],nums[r]);
                l++;
                r--;
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
    vector<int> ans=obj.sortArrayByParity(nums);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}