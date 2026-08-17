#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int n;
string s;
cin>>n;
cin>>s;
int noofgroups=0;
for(int i=0;i<n;i++){
    if(s[i]=='1' &&(i==0 ||s[i-1]=='0')){
        noofgroups++;
    }
}
cout<<noofgroups<<endl;
return 0;
}
