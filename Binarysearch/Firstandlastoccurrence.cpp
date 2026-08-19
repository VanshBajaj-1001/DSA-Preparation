#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstocc(vector<int> &nums,int target){
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;//trying to find in lower index
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return ans;

    }
    int lastocc(vector<int> &nums,int target){
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                ans=mid ;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstocc(nums,target);
        int last=lastocc(nums,target);
        return {first,last};
        
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int> nums (n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int target;
    cin>>target;
   vector<int> ans(2);
   ans=obj.searchRange(nums,target);
   cout<<ans[0]<<" "<<ans[1]<<endl;
   return 0;

}