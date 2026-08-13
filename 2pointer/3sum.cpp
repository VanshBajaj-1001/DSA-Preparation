#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
                if(nums[i] > 0) break;

            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
           int  left=i+1;
            int right=n-1;
            while(left<right){
                long long sum=(long long)nums[i]+nums[left]+nums[right];
                if(sum==0){
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]){
                        left++;
                    }
                    while(left<right && nums[right]==nums[right+1]){
                        right--;
                    }

                }
                else if(sum<0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return ans;
    }
};
int main(){
    Solution obj;
    int n;
    cout<<"enter n"<<endl;
    cin>>n;
    vector<int> nums(n);
    cout<<"enter elements in the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<int>> ans=obj.threeSum(nums);
    cout<<"output"<<endl;
    for(auto i:ans){
        cout<<"[";
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}