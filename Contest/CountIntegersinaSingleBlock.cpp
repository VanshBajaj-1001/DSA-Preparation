#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        set<int>specialnos;
        set<int>notspecialno;
        int prev=nums[0];
        specialnos.insert(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=prev){
                if(specialnos.count(nums[i])){
                    notspecialno.insert(nums[i]);
                    specialnos.erase(nums[i]);
                }
                else if(!notspecialno.count(nums[i])){
                    specialnos.insert(nums[i]);
                }
            }
            prev=nums[i];
        }
        return specialnos.size();
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