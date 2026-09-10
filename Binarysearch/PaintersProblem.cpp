#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int cntpainter(vector<int>& arr,int time){
      int painters=1;
      int boardspainted=0;
      for(int i=0;i<arr.size();i++){
          if(boardspainted+arr[i]>time){
              painters++;
              boardspainted=arr[i];
          }
          else{
              boardspainted+=arr[i];
          }
      }
      return painters;
  }
    int minTime(vector<int>& arr, int k) {
        // code here
        int l=*max_element(arr.begin(),arr.end());
        int h=accumulate(arr.begin(),arr.end(),0);
        int time=h;
        while(l<=h){
            int mid=l+(h-l)/2;
            int painters=cntpainter(arr,mid);
            if(painters>k){
                l=mid+1;
            }
            else{
                time=mid;//valid soln try minimize
                h=mid-1;
            }
        }
        return time;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;
    cout<<obj.minTime(nums,k);
    return 0;
}