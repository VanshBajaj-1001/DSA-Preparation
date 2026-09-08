#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
void merge(vector<int>& nums,int l,int mid,int h){

    vector<int> temp;
    int left=l;
    int right=mid+1;
    while(left<=mid &&right<=h){
        if(nums[left]<=nums[right]){
    temp.push_back(nums[left]);
    left++;
        }
        else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(nums[left]);
    left++;
    }
    while(right<=h){
          temp.push_back(nums[right]);
            right++;
    }
    for(int i=l;i<=h;i++){
        nums[i]=temp[i-l];
    }
}
int countpairs(vector<int>& nums,int l,int mid,int h){
    int cnt=0;
    int right=mid+1;
    for(int i=l;i<=mid;i++){
        while(right<=h &&  (long long)nums[i]>nums[right]*2LL){
            right++;
        }
        cnt+=right-(mid+1);
    }
    return cnt;
}
int mergeSort(vector<int>& nums,int l,int h){
    int cnt=0;
    if(l>=h){
        return cnt;
    }
    int mid=l+(h-l)/2;
    cnt+=mergeSort(nums,l,mid);
    cnt+=mergeSort(nums,mid+1,h);
    cnt+=countpairs(nums,l,mid,h);
    merge(nums,l,mid,h);
    return cnt;
}
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
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
    cout<<obj.reversePairs(nums);
    return 0;
}