#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
 int root(int x){
    if(x<2){
        return x;

    }
    int l=1;
    int r=x/2;
    int ans=0;
while(l<=r){
    long long mid=l+(r-l)/2;
    if(mid*mid<=x){
   ans=mid;
   l=mid+1;
    }
    else{
r=mid-1;
    }
}
return ans;
 }
};
int main(){
    Solution obj;
    int x;
    cin>>x;
    int ans=obj.root(x);
    cout<<ans<<endl;
    return 0;
}