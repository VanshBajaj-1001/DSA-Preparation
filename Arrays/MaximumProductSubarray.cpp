#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int maxproduct=nums[0];
        int minproduct=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(minproduct,maxproduct);
            }
            maxproduct=max(maxproduct*nums[i],nums[i]);
            minproduct=min(minproduct*nums[i],nums[i]);
res=max(res,maxproduct);
        }
        return res;
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
    int ans=obj.maxProduct(nums);
    cout<<"Output "<<ans<<endl;
    return 0;
}