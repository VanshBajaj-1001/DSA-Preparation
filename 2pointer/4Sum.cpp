#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
           if(i>0 && nums[i]==nums[i-1]){
            continue;
           }
           for(int j=i+1;j<n;j++){
            if(j>i+1 && nums[j]==nums[j-1]){
                continue;
            }
            int left=j+1;
            int right=n-1;
            while(left<right){
                long long foursum=(long long)nums[i]+nums[j]+nums[left]+nums[right];
                if(foursum==target){
                    ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                    while(left<right && nums[left]==nums[left+1]){
                        left++;
                    }
                    while(left<right && nums[right]==nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                }
                else if(foursum<target){
                    left++;
                }
                else {
                    right--;
                }
            }
           }
        }
        return ans;
    }
};
int main() {
    Solution obj;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    vector<vector<int>> ans = obj.fourSum(nums, target);

    cout << "Quadruplets are:\n";

    for(auto quad : ans) {
        cout << "[ ";
        for(int x : quad) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}