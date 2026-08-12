#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int plus1=(3-n%3)%3;
    
    int jump5=(n/5 +1)*5;
    int jump=1+(3-jump5%3)%3;
    int ans=min(plus1,jump);
    cout<<ans<<endl;
    
}
return 0;
}
