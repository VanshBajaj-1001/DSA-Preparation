#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        int half=n/2;
        long long total=0;
        for(int x:nums){
            total+=x;
        }
        long long windowsum=0;
        for(int i=0;i<half;i++){
            windowsum+=nums[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(windowsum>total-windowsum){
                ans++;
            }
            windowsum-=nums[i];
            windowsum+=nums[(i+half)%n];
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
  cout<<obj.countGoodRotations(nums);
  return 0;
}