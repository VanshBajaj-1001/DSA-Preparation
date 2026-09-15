#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string w="";
        for(char c:s){
            if(c==' '){
                words.push_back(w);
                w="";
            }
            else{
                w+=c;
            }
        }
        words.push_back(w);
        if(pattern.size()!=words.size()){
            return false;
        }
        map<char,string> mp1;
        map<string,char> mp2;
        for(int i=0;i<pattern.size();i++){
            char c=pattern[i];
            string a=words[i];
            if(mp1.count(c)&&mp1[c]!=a){
                return false;
            }
            if(mp2.count(a)&&mp2[a]!=c){
                return false;
            }
            mp1[c]=a;
            mp2[a]=c;
        }
        return true;
    }
};
int main(){
    Solution obj;
    string s;
    string pattern;
    cin>>pattern;
    cin.ignore();
    getline(cin,s);
    bool ans=obj.wordPattern(pattern,s);
    if(ans){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}