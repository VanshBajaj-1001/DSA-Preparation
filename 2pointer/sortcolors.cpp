#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
     int low=0;
     int mid=0;
     int high=nums.size()-1;
     while(mid<=high){
        if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid],nums[high]);
            high--;
        }
     }   
    }
};
int main(){
    Solution obj;
    int n;
    cout<<"enter n"<<endl;
    cin>>n;
    vector<int> nums(n);
    cout<<"enter elements in the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    obj.sortColors(nums);
    cout<<"Output"<<endl;
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}