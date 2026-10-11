#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty()&&st.top()>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ans=obj.prevSmaller(arr);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}