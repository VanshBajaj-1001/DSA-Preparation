#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int number1=0;
        int number2=0;
        int c1=0;
        int c2=0;
        for(int i:nums){ //finding 2 numbers which can be majority
             if(i==number1){
                c1++;
             }
             else if(i==number2){
                c2++;
             }
             else if(c1==0){
                number1=i;
                c1=1;
             }
             else if(c2==0){
                number2=i;
                c2=1;
             }
             else{
                c1--;
                c2--;
             }
        }
        //verifying if they afre >n/3
        c1=0;c2=0;
        for(int i:nums){
            if(i==number1){
                c1++;
            }
            else if(i==number2){
                c2++;
            }
        }
        vector<int> ans;
        if(c1>nums.size()/3){
            ans.push_back(number1);
        }
        if(c2>nums.size()/3){
            ans.push_back(number2);
        }
        return ans;
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
    vector<int> ans=obj.majorityElement(nums);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}