#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseArray(vector<int> &nums,int start,int end){
        while(start<end){
            int temp=nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            start++;
            end--;
        }
    } 
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0||k==0){
            return ;
        }
        k=k%n;
        reverseArray(nums,0,n-1);
        reverseArray(nums,0,k-1);
        reverseArray(nums,k,n-1);
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
    obj.rotate(nums,k);
    for(int i: nums){
        cout<<i<<" ";
    }
    return 0;
}