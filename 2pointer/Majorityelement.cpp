#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int number=0;
        for(int i:nums){
            if(i==number){
                count++;
            }
            if(count==0){
                number=i;
                count++;
            }
            else{
                count--;
            }
        }
        return number;
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
int ans=obj.majorityElement(nums);
cout<<ans<<endl;
return 0;
}