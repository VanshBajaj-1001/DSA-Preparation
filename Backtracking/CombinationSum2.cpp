#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
void solve(int index,vector<int> &candidates,int target,vector<int> &curr,vector<vector<int>> &ans){
    if(target==0){
        ans.push_back(curr);
        return;
    }
    for(int i=index;i<candidates.size();i++){
        if(i>index && candidates[i]==candidates[i-1]){
            continue;
        }
        if(candidates[i]>target){
            break;
        }
        curr.push_back(candidates[i]);
        solve(i+1,candidates,target-candidates[i],curr,ans);
        curr.pop_back();
    }
     
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0,candidates,target,curr,ans);
        return ans;
    }
};
int main(){
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
     vector<vector<int>> ans=obj.combinationSum2(arr,target);
      for(auto i: ans){
        cout << "[ ";
        for(int j: i){
            cout<<j<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}