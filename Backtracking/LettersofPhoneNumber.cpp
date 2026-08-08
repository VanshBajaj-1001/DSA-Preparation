#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
     void solve(string digits,int index,string s,vector<string> &ans,string combination[]){
        if(index==digits.size()){
            ans.push_back(s);
            return;
        }
        int digit=digits[index]-'0';
        for(int i=0;i<combination[digit].size();i++){
            solve(digits,index+1,s+combination[digit][i],ans,combination);
        }
     }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
      vector<string> ans;
      string s="";
      string combination[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
      solve(digits,0,s,ans,combination);
      return ans;
    }
};
int main(){
    Solution obj;
    string n;
    cout<<"Enter the number"<<endl;
    getline(cin,n);
    vector<string> ans=obj.letterCombinations(n);
    cout<<"output ";
    for(string i: ans){
        cout<<i<<" ";
    }
    return 0;
}