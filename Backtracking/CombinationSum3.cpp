#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void solve(int index,int sum,vector<int> &curr,vector<vector<int>> &ans,int k){
        if(sum==0 && curr.size()==k){
            ans.push_back(curr);
            return ;
        }
        if(sum<=0 || curr.size()>k){
            return ;
        }
        for(int i=index;i<=9;i++){
            if(i<=sum){
                curr.push_back(i);
            solve(i+1,sum-i,curr,ans,k);
            curr.pop_back();
            }
            else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(1,n,curr,ans,k);
        return ans;
    }
};
int main(){
    Solution obj;
    int n;
    int k;
    cout<<"Enter value for k and n"<<endl;
    cin>>n;
    cin>>k;
    vector<vector<int>> ans=obj.combinationSum3(k,n);
    cout<<"Output "<<endl;
    for(auto i: ans){
        cout<<"[";
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"]"<<endl;
    }
return 0;
}