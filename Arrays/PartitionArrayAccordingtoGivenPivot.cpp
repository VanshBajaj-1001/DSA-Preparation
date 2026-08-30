#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> equal;
        vector<int> greater;
        for(int i:nums){
            if(i<pivot){
                less.push_back(i);
            }
            else if(i==pivot){
                equal.push_back(i);
            }
            else{
                greater.push_back(i);
            }
        }
        vector<int> ans;
        for(int i:less){
            ans.push_back(i);
        }
        for(int i:equal){
            ans.push_back(i);
        }
        for(int i:greater){
            ans.push_back(i);
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
    int pivot;
    cin>>pivot;
    vector<int> ans=obj.pivotArray(nums,pivot);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}