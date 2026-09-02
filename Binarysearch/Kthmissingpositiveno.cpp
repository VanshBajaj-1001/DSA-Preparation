#include <bits/stdc++.h>
using namespace std;
// REVISION REQUIRED
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
  int l=0;
  int h=arr.size()-1;
  while(l<=h){
    int mid=l+(h-l)/2;
    int missing=arr[mid]-(mid+1);
    if(missing<k){
        l=mid+1;
    }
    else{
        h=mid-1;
    }
  }      
  return h+1+k;
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
  cout<<obj.findKthPositive(nums,k)<<endl;
  return 0;
}