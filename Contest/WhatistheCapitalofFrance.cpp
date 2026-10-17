#include <bits/stdc++.h>
using namespace std;
int rangeOr(int l,int r){
    int shift=0;
    while(l<r){
        l>>=1;
        r>>=1;
        shift++;
    }
    return (l<<shift)|((1<<shift)-1);
}
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int mn=INT_MAX;
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mn=min(mn,x);
        mx=max(mx,x);
    }
    cout<<rangeOr(mn,mx)<<endl;
}
return 0;
}