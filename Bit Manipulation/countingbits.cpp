#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=1;i<=n;i++){
            ans[i]=ans[i/2]+(i%2);
        }
        return ans;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int> ans=obj.countBits(n);
    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}