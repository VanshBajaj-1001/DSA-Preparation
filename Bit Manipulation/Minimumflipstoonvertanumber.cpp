#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x=start^goal;
        int count=0;
        while(x>0){
            if(x&1){
                count++;
            }
            x=x>>1;
        }
        return count;
    }
};
int main(){
    Solution obj;
    int start;
    int goal;
    cin>>start;
    cin>>goal;
    int ans=obj.minBitFlips(start,goal);
    cout<<ans<<endl;
    return 0;
}