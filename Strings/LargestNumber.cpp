#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;for(int i:nums){
            temp.push_back(to_string(i));
        }
        sort(temp.begin(),temp.end(),[](string a,string b){
            return a+b>b+a;
        });
        if(temp[0]=="0"){
            return "0";
        }
        string ans="";
        for(string i:temp){
            ans+=i;
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
    cout<<"Largest Number is "<<obj.largestNumber(nums)<<endl;
    return 0;
}