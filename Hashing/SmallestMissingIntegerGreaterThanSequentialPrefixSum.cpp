#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
                if(nums[i]==nums[i-1]+1){
                    sum+=nums[i];
                }
                else{
                    break;
                }
        }
        unordered_set<int> s(nums.begin(),nums.end());
        int x=sum;
        while(s.count(x)){
            x++;
        }
        return x;
    }
};
int main(){
    Solution obj;
    int n;
    cout<<"Enter no of elements in the array"<<endl;
    cin>>n;
    cout<<"Enter elements in the array"<<endl;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ans=obj.missingInteger(nums);
    cout<<"Output "<<ans<<endl;
    return 0;
}