#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
            int ans=0;
            for(auto& i:mp){
                vector<int>& indices=i.second;
                if(indices.size()!=3){
                    continue;
                }
                int i1=indices[0];
                int i2=indices[1];
                int i3=indices[2];
                if(i2-i1==i3-i2){
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
    cout<<obj.countSpecialIntegers(nums)<<endl;
    return 0;
}