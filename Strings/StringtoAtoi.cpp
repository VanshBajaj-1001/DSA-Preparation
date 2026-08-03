#include <iostream>
#include <string>
#include <climits>
#include <cctype>
using namespace std;


class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        while(i<n && s[i]==' '){
            i++;
        }
        long long ans=0;
        int sign=1;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        while(i<n && isdigit(s[i])){
            int digit=s[i]-'0';
            if(sign==1 && (ans>INT_MAX/10 ||(ans==INT_MAX/10 && digit>7))){
                return INT_MAX;
            }
             if(sign==-1 && (ans>INT_MAX/10 ||(ans==INT_MAX/10 && digit>8))){
                return INT_MIN;
            }
            ans=ans*10+digit;
            i++;
        }
        return sign*ans;
    }
};
int main(){
    Solution obj;
    string s;
    cout<<"Enter a string"<<endl;
    getline(cin,s);
    cout<<" Output "<<obj.myAtoi(s)<<endl;
    return 0;
}