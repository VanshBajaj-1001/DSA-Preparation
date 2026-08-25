#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorall=0;
        for(int i:nums){
            xorall^=i;
        }
      unsigned int x=xorall;
      unsigned int bit=x&(-x);
        int a=0;
        int b=0;
        for(int i:nums){
            if(i&bit){
                a^=i;
            }
            else{
                b^=i;
            }
        }
        return {a,b};
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
    vector<int> ans=obj.singleNumber(nums);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}