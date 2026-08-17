#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        int repeating=-1;
        int  missing=-1;
        for(int i=0;i<=nums.size();i++){
            if(mp[i]==2){
                repeating=i;
            }
            if(mp[i]==0){
                missing=i;
            }
        }
        return {repeating,missing};
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
    vector<int> ans=obj.findErrorNums(nums);
    cout<<"Output "<<endl;
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}