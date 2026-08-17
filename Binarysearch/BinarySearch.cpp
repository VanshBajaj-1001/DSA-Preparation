#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int b=0;
        int l=nums.size()-1;
        while(b<=l){
            int mid=(b+l)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                l=mid-1;
            }
            else{
                b=mid +1;
            }
        }
            return -1;//no need to check condition
        
    }
};
int main(){
    Solution obj;
    int n;
    cout<<"enter no of elements in the array"<<endl;
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter elements inb the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int target;
    cout<<"Enter target"<<endl;
    cin>>target;
    int ans=obj.search(nums,target);
    if(ans==-1){
        cout<<"element not found "<<endl;
    }
    else{
        cout<<"found at "<<ans<<" index"<<endl;
    }
    return 0;
}