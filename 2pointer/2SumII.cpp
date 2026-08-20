#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r=numbers.size()-1;
        while(l<r){
            int sum=numbers[l]+numbers[r];
            if(sum==target){
                return {l+1,r+1};
            }
            else if(sum<target){
                l++;
            }
            else{
                r--;
            }
        }
        return {};
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
     int target;
    cin>>target;
    vector<int> ans=obj.twoSum(nums,target);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;

}