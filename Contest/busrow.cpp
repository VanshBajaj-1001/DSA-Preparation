#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int t;
cin>>t;
while(t--){
    int n;
    int m;
    int x;
    cin>>n;
    cin>>m;
    cin>>x;
    int rowno=(x-1)/m+1;
    int ans=min(rowno,n-rowno+1);
    cout<<ans<<endl;
    
}
return 0;
}
