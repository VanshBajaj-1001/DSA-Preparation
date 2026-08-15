#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int ans=INT_MAX;
        for(int r=0;r<n;r++){
            int operations=r;
            for(int i=0;i<n/2;i++){
                char left=s[(i+r)%n];
                char right=s[(n-1-i+r)%n];
                int difference=abs(left-right);
                operations+=min(difference,26-difference);
            }
            ans=min(ans,operations);
        }
        return ans;
    }
};
int main(){
    Solution obj;
    string s;
    cout<<"Enter a string"<<endl;
    cin>>s;
    int ans=obj.minOperations(s);
    cout<<"Output "<<ans<<endl;
    return 0;
}