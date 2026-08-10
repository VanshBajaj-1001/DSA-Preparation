#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int houserobber(vector<int> &nums,int index,vector<int> &arr){
    if(index>=nums.size()){
        return 0;
    }
    if(arr[index]!=-1){
        return arr[index];
    }
   int rob=nums[index]+houserobber(nums,index+2,arr);
   int skip=houserobber(nums,index+1,arr);
   return arr[index]=max(rob,skip);
}
    int rob(vector<int>& nums) {
        vector<int> arr(nums.size(),-1);
        int ans=houserobber(nums,0,arr);
        return ans;
    }
};
int main(){
    Solution obj;
    int n;
    cout<<"Enter number of elements"<<endl;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ans=obj.rob(nums);
    cout<<"Output "<<ans<<endl;
    return 0;
}