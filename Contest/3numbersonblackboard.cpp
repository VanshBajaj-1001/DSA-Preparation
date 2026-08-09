#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a;
       long long b;
       long long c;
       cin>>a;
       cin>>b;
       cin>>c;
       vector<long long> ans={a,b,c};
       sort(ans.begin(),ans.end());
       long long x=ans[0];
       long long y=ans[1];
       long long z=ans[2];
       cout<<min(z-x,y)<<'\n';
       
    }
    return 0;
}