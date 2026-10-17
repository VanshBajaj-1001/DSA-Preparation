#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt=count(s.begin(),s.end(),'1');
        if(cnt==1){
            cout<<0<<endl;
        }
        else if(cnt==2){
cout<<1<<endl;
        }
        else{
        int first=s.find('1');
        int last=s.rfind('1');
        cout<<last-first<<endl;
        }
    }
    return 0;
}