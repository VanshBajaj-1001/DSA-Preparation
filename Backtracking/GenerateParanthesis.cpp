#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
vector<string> ans;
void solve(int open,int close,int n,string curr){
    if(open==n && close==n){
        ans.push_back(curr);
        return;
    }
    if(open<n){
        solve(open+1,close,n,curr+"(");
    }
    if(open>close){
        solve(open,close+1,n,curr+")");
    }
}
    vector<string> generateParenthesis(int n) {
        solve(0,0,n,"");
        return ans;
    }
};
int main(){
    Solution obj;
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;
   vector<string> result=obj.generateParenthesis(n);
   for(string s:result){
    cout<<s<<" ";
   }
   return 0;
}