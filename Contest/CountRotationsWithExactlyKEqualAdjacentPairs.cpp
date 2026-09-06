#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countRotations(string s, int k) {
        int n=s.size();
        int total=0;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                total++;
            }
        }
            int ans=0;
            if(total==k){
                ans++;
            }
        for(int i=1;i<n;i++){
            int score=total;
            if(s[i-1]==s[i]){
                score--;
            }
            if(s[n-1]==s[0]){
                score++;
            }
            if(score==k){
                ans++;
            }
        }
        return ans;
            
        
    }
};
int main(){
    Solution obj;
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<obj.countRotations(s,k)<<endl;
    return 0;
}