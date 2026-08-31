#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++){
            int l=i+1;
            int r=nums.size()-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(abs(target-sum)<abs(target-closest)){
                    closest=sum;
                }
                if(sum==target){
                    return sum;
                }
                if(sum<target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
            return closest;
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
    cout<<obj.threeSumClosest(nums,target)<<endl;
    return 0;
}