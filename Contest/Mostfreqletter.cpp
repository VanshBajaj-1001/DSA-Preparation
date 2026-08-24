#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here
    string s;
    getline(cin, s);
    int freq[26] = {};
    for(char ch:s){
        if(isalpha(ch)){
            ch=tolower(ch);
            freq[ch-'a']++;
        }
    }
    char ans='a';
    int maxfeq=0;
    for(int i=0;i<26;i++){
        if(freq[i]>maxfeq){
            maxfeq=freq[i];
            ans='a'+i;
        }
    }
    cout<<ans<<endl;
    return 0;
}