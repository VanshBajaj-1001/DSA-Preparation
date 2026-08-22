#include <iostream>
using namespace std;
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;
        int x=n;
        while(x>0){
            int a=x%10;
            sum+=a;
            prod*=a;
            x=x/10;
        }
        return n%(sum+prod)==0;
    }
};
int main(){
    Solution obj;
    int n;
    int ans;
    cin>>n;
    ans=obj.checkDivisibility(n);
    cout<<ans<<endl;
    return 0;
    
}