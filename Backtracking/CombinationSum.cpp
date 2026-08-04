#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
   void solve(int index,vector<int> &candidates,int target,vector<vector<int>> &ans,vector<int> &curr){
     if(target==0){
        ans.push_back(curr);
        return;
     }
     if(target<0 || index==candidates.size()){
        return;
     }
     curr.push_back(candidates[index]);
     solve(index,candidates,target-candidates[index],ans,curr);
     curr.pop_back();
     solve(index+1,candidates,target,ans,curr);
   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0,candidates,target,ans,curr);
        return ans;
    }
};
int  main(){
    Solution obj;
    int n;
    cout<<"Enter no of elements"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter Elements in the array"<<endl;
    for(int i=0;i<n;i++){
  cin>>arr[i];
    }
    int target;
    cout<<"Enter the Target sum"<<endl;
    cin>>target;
    cout<<"Output "<<endl;
    vector<vector<int>> ans=obj.combinationSum(arr,target);
    for(auto i: ans){
        cout << "[ ";
        for(int j: i){
            cout<<j<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}