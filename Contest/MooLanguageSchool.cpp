#include <bits/stdc++.h>
using namespace std;
int main(){
 int ans=0;
 int t;
 cin>>t;
 while(t--){
    int n;
    cin>>n;
    int k;
    cin>>k;
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<n;i+=k){
        bool allone=true;
        for(int j=i;j<i+k;j++){
        if(s[j]=='0'){
            allone=false;
            break;
        }
        }
        if(allone){
            ans++;
        }
    }
    cout<<ans<<endl;

 }
 return 0;
}