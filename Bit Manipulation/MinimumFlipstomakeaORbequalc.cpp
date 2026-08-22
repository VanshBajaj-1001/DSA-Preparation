#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(a ||b ||c){
            int x=a&1;
            int y=b&1;
            int z=c&1;
            if(z==1){
                if(x==0 && y==0){
                    ans++;
                }
            }
            else{//when z is zero
               if(x==1){
                ans++;
               }
               if(y==1){
                ans++;
               }
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return ans;
    }
};
int main(){
    Solution obj;
    int a;
    int b;
    int c;
    cin>>a;
    cin>>b;
    cin>>c;
    int ans=obj.minFlips(a,b,c);
    cout<<"Output "<<ans<<endl;
    return 0;
}