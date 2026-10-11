#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        stack<int> st;
        vector<int> ans(arr.size(),-1);
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty()&&st.top()<=arr[i]){
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
    vector<int> ans=obj.nextLargerElement(arr);
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}