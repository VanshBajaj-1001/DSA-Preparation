#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry=0;
        string ans="";
        while(i>=0||j>=0||carry){
            int dig1=0;
            int dig2=0;
            if(i>=0){
                dig1=num1[i]-'0';
            }
            if(j>=0){
                dig2=num2[j]-'0';
            }
            int sum=dig1+dig2+carry;
            ans+=char((sum%10)+'0');
            carry=sum/10;
            i--;
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main(){
    Solution obj;
    string num1;
    string num2;
    cin>>num1;
    cin>>num2;
    string ans=obj.addStrings(num1,num2);
    cout<<ans<<endl;
    return 0;
}