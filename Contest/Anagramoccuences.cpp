#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
string s;
string p;
cin>>s;
cin>>p;

int n=s.size();
int m=p.size();
vector<int> f1(26,0);
vector<int> f2(26,0);
for(char ch:p){
    f1[ch-'a']++;
}
for(int i=0;i<m;i++){
    f2[s[i]-'a']++;
}
bool found=false;
if(f1==f2){
    found=true;
    cout<<0<<" ";
}
for(int i=m;i<n;i++){
    f2[s[i]-'a']++;
    f2[s[i-m]-'a']--;
    if(f1==f2){
        found=true;
        cout<<i-m+1<<" ";
    }
}
if(!found){
    cout<<"-1";
    return 0;
}

}
