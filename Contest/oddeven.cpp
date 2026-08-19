#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int odd=0;
    int even=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x%2==0){
            even++;
        }
        else{
            odd++;
        }
    }
    int ans=2*min(odd,even);
    if(odd!=even){
        ans++;
    }
    cout<<ans<<endl;
}
return 0;
}
