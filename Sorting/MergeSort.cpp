#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  void merge(vector<int>& arr,int l,int mid,int r){
      vector<int> temp;
      int i=l;
      int j=mid+1;
      while(i<=mid && j<=r){
          if(arr[i]<=arr[j]){
              temp.push_back(arr[i]);
              i++;
          }
          else{
              temp.push_back(arr[j]);
              j++;
          }
      }
      while(i<=mid){
          temp.push_back(arr[i]);
          i++;
      }
      while(j<=r){
          temp.push_back(arr[j]);
          j++;
      }
      for(int k=l;k<=r;k++){
          arr[k]=temp[k-l];
      }
  }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r){
            return ;
        }
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
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
    int l=0;
    int h=nums.size()-1;
    obj.mergeSort(nums,l,h);
    for(int i:nums){
        cout<<i<<" ";
    }
    return 0;
}