#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        stack<int> st;
        int n=arr.size();
        int water=0;
        int i=0;
        for(i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]<arr[i]){
                int bottom=st.top();
                st.pop();
                if(st.empty()){
                    break;
                }
                int left=st.top();
                int width=i-left-1;
                int boundedheight=min(arr[left],arr[i])-arr[bottom];
                water+=boundedheight*width;
            }
            st.push(i);
        }
        return water;
    }
};
int  main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<obj.maxWater(arr)<<endl;
    return 0;
}