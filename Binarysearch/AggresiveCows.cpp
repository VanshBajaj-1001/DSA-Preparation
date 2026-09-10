#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  bool canweplace(vector<int>&stalls,int k,int d){
      int cnt=1;
      int  lastcow=stalls[0];
      for(int i=1;i<stalls.size();i++){
          if(stalls[i]-lastcow>=d){
              cnt++;
              lastcow=stalls[i];
          }
          if(cnt>=k){
              return true;
          }
      }
      return false;
  }
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int l=1;
        int ans=0;
        int h=arr.back()-arr.front();
        while(l<=h){
            int mid=l+(h-l)/2;
            if(canweplace(arr,k,mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
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
    int cows;
    cin>>cows;
    int ans=obj.aggressiveCows(nums,cows);
    cout<<ans<<endl;
    return 0;
}