#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //since time complexity is logn means it is binary search
        int low=0;
        int high=nums.size()-1;
        int anspos=nums.size();//if element is greatest
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>=target){
                anspos= mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return anspos;
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
    int target;
    cin>>target;
    int ans=obj.searchInsert(nums,target);
    cout<<"Answer position"<<ans<<endl;
    return 0;
}