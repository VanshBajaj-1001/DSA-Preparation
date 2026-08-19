#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            if(nums[mid]>nums[mid+1]){
                  high=mid;
            }
            else{
            low=mid+1;
            }
        }
        return low;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
     vector<int> nums (n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ans=obj.findPeakElement(nums);
    cout<<ans<<endl;
    return 0;
}