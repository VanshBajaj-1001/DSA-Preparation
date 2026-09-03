#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int atmost(vector<int>& nums,int k){
    int l=0;
    int res=0;
    for(int r=0;r<nums.size();r++){
        if(nums[r]%2!=0){
            k--;
        }
        while(k<0){
            if(nums[l]%2!=0){
                k++;
            }
            l++;
        }
        res+=(r-l+1);
    }
    return res;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
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
    cout<<obj.numberOfSubarrays(nums,k)<<endl;
    return 0;
}