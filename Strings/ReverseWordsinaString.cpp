#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result;
        int i=s.size()-1;
        while(i>=0){
            while(i>=0 && s[i]==' '){ // if there is space at current position then remove/skip it
                i--;
            }
            if(i<0){   // ends if no word are left
                break;
            }
            int end=i;
            while(i>=0 &&s[i]!=' '){
                i--;
            }
            string word=s.substr(i+1,end-i);
            if(!result.empty()){
               result+=" ";
            }
            result+=word;

        }
        return result;
    }
};
int main(){
Solution obj;
string S;
cout<<"Enter a string"<<endl;
getline(cin,S);
string ans=obj.reverseWords(S);
cout<<"Output "<<ans<<endl;
return 0;

}