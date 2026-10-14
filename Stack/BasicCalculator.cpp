#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        long long result=0;
        long long  number=0;
       int sign=1;
       for(int i=0;i<s.size();i++){
        char c=s[i];
        if(isdigit(c)){
            number=number*10 + (c-'0');
        }
        else if(c=='+'){
            result+=sign*number;
            number=0;
            sign=1;
        }
        else if(c=='-'){
            result+=sign*number;
            sign=-1;
            number=0;
        }
        else if(c=='('){
            st.push(result);
            st.push(sign);
            result=0;
            sign=1;

        }
        else if(c==')'){
            result+=sign*number;
            number=0;
            result*=st.top();
            st.pop();
            result+=st.top();
            st.pop();

        }
       }
       result+=sign*number;
       return result;
    }
};
int main(){
    Solution obj;
    string s;
    getline(cin,s);
    cout<<obj.calculate(s);
    return 0;
}