#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int a:asteroids){
        bool alive=true;
        while(!st.empty()&&a<0&&st.top()>0&&alive){
            if(st.top()<-a){
                st.pop();
            }
            else if(st.top()==-a){
                st.pop();
                alive=false;
            }
            else{
                alive=false;
            }
        }
        if(alive){
            st.push(a);
        }
        }
        vector<int> ans(st.size());
        int s=st.size();
for(int i=s-1;i>=0;i--){
    ans[i]=st.top();
    st.pop();
}
return ans;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int> asteroids(n);
    for(int i=0;i<n;i++){
        cin>>asteroids[i];
    }
    vector<int> ans=obj.asteroidCollision(asteroids);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}