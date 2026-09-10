#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i])!=s.end()){
                return true;
            }
            s.insert(nums[i]);
            if(s.size()>k){
                s.erase(nums[i-k]);
            }
        }
        return false;
        
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    bool ans=obj.containsNearbyDuplicate(nums,k);
    if(ans){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}