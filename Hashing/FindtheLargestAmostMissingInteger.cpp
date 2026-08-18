#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i=0;i<=nums.size()-k;i++){
            unordered_set<int> s;
            for(int j=i;j<i+k;j++){
                s.insert(nums[j]);
            }
            for(int i:s){
                freq[i]++;
            }
        }
        int ans=-1;
        for(auto i:freq){
            if(i.second==1){
                ans=max(ans,i.first);
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
    int k;
    cin>>k;
    int ans=obj.largestInteger(nums,k);
    cout<<"Output "<<ans<<endl;
    return 0;
}