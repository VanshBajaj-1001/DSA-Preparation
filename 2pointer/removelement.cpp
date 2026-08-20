#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
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
     int val;
     cin>>val;
     int ans=obj.removeElement(nums,val);
     cout<<ans<<endl;
     return 0;
}