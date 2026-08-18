#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long binary=n;
        double ans=1;
        if(n<0){
            x=1/x;
            binary=-binary;
        }
        while(binary>0){
            if(binary%2==1){
                ans=ans*x;
            }
            x=x*x;
            binary=binary/2;
        }
        return ans;
    }
};
int main(){
    Solution obj;
    double x;
    cin>>x;
    int n;
    cin>>n;
    double ans=obj.myPow(x,n);
    cout<<"Output "<<ans<<endl;
    return 0;
}