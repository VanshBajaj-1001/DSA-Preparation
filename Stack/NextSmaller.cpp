#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n=arr.size();
        vector<int> ans(arr.size(),-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
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
    vector<int> ans=obj.nextSmallerEle(arr);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}