#include <bits/stdc++.h>
using namespace std;

class Solution {
public: int sumdivisor(vector<int>&nums, int divisor){
    int sum=0;
    for(int i:nums){
        sum+=ceil((double)i/divisor);
    }
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size()>threshold){
            return -1;
        }
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        while(l<=r){
            int mid=l+(r-l)/2;
            if(sumdivisor(nums,mid)<=threshold){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
          }
          return l;
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
  int limit;
  cin>>limit;
  cout<<obj.smallestDivisor(nums,limit);
  return 0;
}