#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,int> freq;
        for(int i:bulbs){
            freq[i]++;
        }
        vector<int> ans;
        for(auto it:freq){
            if(it.second%2==1){
                ans.push_back(it.first);
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
    vector<int> ans=obj.toggleLightBulbs(nums);
    cout<<"Output "<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}