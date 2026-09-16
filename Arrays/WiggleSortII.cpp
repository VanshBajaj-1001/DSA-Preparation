#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        int n=nums.size();
        int mid=(n-1)/2;
        int h=n-1;
        for(int i=0;i<n;i++){
            if(i%2==0){
                nums[i]=temp[mid];
                mid--;
            }
            else{
                nums[i]=temp[h];
                h--;
            }
        }
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
    obj.wiggleSort(nums);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}