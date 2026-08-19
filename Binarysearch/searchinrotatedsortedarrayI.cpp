#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // given array is left rotated
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[low]<=nums[mid]){// checks if left part is sorted or not
            if(target>=nums[low]&& nums[mid]>=target){
                    high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        else{//if right part is sorted
              if(target>=nums[mid]&&target<=nums[high]){
                low=mid+1;
              }
              else{
                high=mid-1;
              }
        }
        }
      return -1;
        
    }
};
int main(){
    Solution obj;
   int n;
   cin>>n;
   vector<int> ans(n);
   for(int i=0;i<n;i++){
    cin>>ans[i];
   }
   int target;
   cin>>target;
   int a=obj.search(ans,target);
   cout<<a<<endl;
   return 0;
}