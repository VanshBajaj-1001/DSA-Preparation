#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  vector<int> nextsmall(vector<int>&nums){
      stack<int> st;
      int n=nums.size();
      vector<int> ans(n,n);
      for(int i=n-1;i>=0;i--){
          while(!st.empty()&&nums[st.top()]>=nums[i]){
              st.pop();
          }
          if(!st.empty()){
              ans[i]=st.top();
          }
          st.push(i);
      }
      return ans;
  }
  vector<int> prevsmaller(vector<int>& nums){
      stack<int> st;
      int n=nums.size();
      vector<int> ans(n,-1);
      for(int i=0;i<n;i++){
          while(!st.empty()&&nums[st.top()]>=nums[i]){
              st.pop();
          }
          if(!st.empty()){
              ans[i]=st.top();
          }
          st.push(i);
      }
      return ans;
  }
    int getMaxArea(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int> left(n);
        vector<int> right(n);
 left=prevsmaller(arr);
right=nextsmall(arr);
        int maxarea=INT_MIN;
        for(int i=0;i<n;i++){
            int width=right[i]-left[i]-1;
            int area=arr[i]*width;
            maxarea=max(maxarea,area);
        }
        return maxarea;
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
    int area=obj.getMaxArea(arr);
    cout<<area<<endl;
    return 0;
}