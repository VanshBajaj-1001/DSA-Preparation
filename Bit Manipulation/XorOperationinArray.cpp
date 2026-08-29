#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans=0;
        for(int i=0;i<n;i++){
            ans^=start+2*i;
        }
        return ans;
    }
};
int main(){
    Solution obj;
    int start;
    int n;
    cin>>n;
    cin>>start;
    cout<<obj.xorOperation(n,start);
    return 0;
}