#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
vector<vector<int>> ans;
   void solve(vector<int> &nums,int index,vector<int> &curr){

    ans.push_back(curr);//we store every possible subset no need of base case
   for(int i=index;i<nums.size();i++){
    if(i>index && nums[i]==nums[i-1]){
        continue;
    }
    curr.push_back(nums[i]);
    solve(nums,i+1,curr);
    curr.pop_back();
   }
   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> curr;
        solve(nums,0,curr);
        return ans;
    }
};
int main(){
    Solution obj;
    int n;
    cout<<"Enter the no of elements in the array"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements in the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> res=obj.subsetsWithDup(arr);
    cout<<"Output "<<endl;
    for(auto i:res){
        cout<<"{";
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"}"<<endl;
    }
    return 0;
}