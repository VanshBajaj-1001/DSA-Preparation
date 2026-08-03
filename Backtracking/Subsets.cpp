#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
vector<vector<int>> ans;
void solve(int index,vector<int> nums,vector<int> curr){
    if(index==nums.size()){
        ans.push_back(curr);
        return;
    }
    curr.push_back(nums[index]);
    solve(index+1,nums,curr);
    curr.pop_back();
    solve(index+1,nums,curr);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        solve(0,nums,curr);
        return ans;
    }
};
int main(){
    Solution obj;
    int n;
    cout<<"Enter number of elements in array"<<endl;
    cin>>n;
    vector<int> curr(n);
    cout<<"Enter Elements in the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>curr[i];
    }
    vector<vector<int>> result=obj.subsets(curr);
    for(auto i: result){
        cout<<"{";
        for(int j: i){
            cout<<j<<" ";
        }
        cout<<"}"<<endl;
    }
return 0;
}