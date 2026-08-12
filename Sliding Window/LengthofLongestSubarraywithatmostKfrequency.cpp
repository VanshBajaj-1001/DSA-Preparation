#include <iostream>
#include<vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int left=0;
        int ans=0;
        for(int right=0;right<nums.size();right++){
            freq[nums[right]]++;
            while(freq[nums[right]]>k){
                freq[nums[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
int main(){
    Solution obj;
    int n;
    cout<<"Enter no of elements in the array"<<endl;
    cin>>n;
    vector<int> nums(n);
    cout<<"enter elements in the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cout<<"enter k"<<endl;
    cin>>k;
    int ans=obj.maxSubarrayLength(nums,k);
    cout<<"Output "<<ans<<endl;
    return 0;
}