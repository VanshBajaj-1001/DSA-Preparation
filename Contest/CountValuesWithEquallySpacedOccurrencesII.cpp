#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto& i:mp){
            vector<int>& indices=i.second;
            if(indices.size()<3){
                continue;
            }int diff=indices[1]-indices[0];
            bool special=true;
            for(int j=2;j<indices.size();j++){
                if(indices[j]-indices[j-1]!=diff){
                    special=false;
                    break;
                }
            }
            if(special){
                ans++;
            }
        }
        return ans;
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
    cout<<obj.countSpecialIntegers(nums);
    return 0;
}