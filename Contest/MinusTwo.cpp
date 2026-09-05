#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int odd=0;
        int even0=0;
        int even2=0;
        for(int i=0;i<n;i++){
            long long x;
            cin>>x;
            if(x%2==1){
                odd++;
            }
            else if(x%4==0){
                even0++;
            }
            else{
                even2++;
            }
        }
        cout<<max(even0,max(odd,even2))<<endl;
    }
    return 0;
}