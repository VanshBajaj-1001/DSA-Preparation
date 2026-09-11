#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0"){
            return "0";
        }
        int m=num1.size();
        int n=num2.size();
        vector<int> result(m+n,0);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int dig1=num1[i]-'0';
                int dig2=num2[j]-'0';
                int prod=dig1*dig2;
                int pos1=i+j;
                int pos2=i+j+1;
                int sum=prod+result[pos2];
                result[pos2]=sum%10;
                result[pos1]+=sum/10;
            }
        }
        string ans="";
        for(int i:result){
            if(ans.empty()&&i==0){
                continue;
            }
            ans+=to_string(i);
        }
        return ans;
    }
};
int main(){
    Solution obj;
    
    string num1;
    string num2;
    cin>>num1;
    cin>>num2;
    string ans=obj.multiply(num1,num2);
    cout<<ans<<endl;
    return 0;
}