#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int partitions(vector<int> &nums,int maxsum){
    int subarraysum=0;
    int noofpartitions=1;
    for(int i:nums){
        if(subarraysum+i>maxsum){
            noofpartitions++;
            subarraysum=i;
        }
        else{
            subarraysum+=i;
        }
    }
    return noofpartitions;
}
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        while(l<=r){
            int mid=l +(r-l)/2;
            int part=partitions(nums,mid);
            if(part>k){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l;
    }
};
int main(){
    Solution obj;
    int n;cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;
    cout<<obj.splitArray(nums,k)<<endl;
    return 0;
}