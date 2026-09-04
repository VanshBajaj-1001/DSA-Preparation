#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0]=nums[0];
         for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],nums[i]);
         }
         suffix[n-1]=nums[n-1];
         for(int i=n-2;i>=0;i--){
            suffix[i]=min(nums[i],suffix[i+1]);
         }
         for(int i=0;i<n;i++){
            if(prefix[i]-suffix[i]<=k){
                return i;
            }
         }
         return -1;
    }
};
int main(){
    Solution obj;
   int n;
   cin>>n;
   int k;
   vector<int> nums(n);
   for(int i=0;i<n;i++){
    cin>>nums[i];
   }
   cin>>k;
   cout<<obj.firstStableIndex(nums,k)<<endl;
   return 0;
}