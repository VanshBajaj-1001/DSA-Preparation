#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int prev=lower-1;
        for(int i:nums){
            if(i<lower||i>upper){
                continue;
            }
            if(i-prev>=2){
                ans.push_back({prev+1,i-1});
            }
            prev=i;
            }
            if(upper-prev>=1){
                ans.push_back({prev+1,upper});
        }
        return ans;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int> nums(n);
    int lower;
    int upper;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Enter lower and upper"<<endl;
    cin>>lower;
    cin>>upper;
    vector<vector<int>> ans=obj.findDisappearedNumbers(nums,lower,upper);
    for(auto i:ans){
        cout<<"[";
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"]";
    }
    return 0;
}