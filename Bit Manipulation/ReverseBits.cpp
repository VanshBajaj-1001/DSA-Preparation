#include <iostream>
using namespace std;
class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        for(int i=0;i<32;i++){
            int  bit=n&1;
            ans=(ans<<1)|bit;
            n=n>>1;
        }
        return ans;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    int ans=obj.reverseBits(n);
    cout<<ans;
    return 0;
}