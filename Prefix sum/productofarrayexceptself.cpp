#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);
        int leftproduct=1;
        int rightproduct=1;
        for(int i=0;i<n;i++){
            ans[i]=leftproduct;
            leftproduct*=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            ans[i]*=rightproduct;
            rightproduct*=nums[i];
        }
        return ans;
    }
};
int main(){
    Solution obj;
    cout<<"enter no of elements in the array"<<endl;
    int n;
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter elements in the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> ans=obj.productExceptSelf(nums);
    cout<<"Output"<<endl;
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}