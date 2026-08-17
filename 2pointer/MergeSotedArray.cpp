#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                i--;
                k--;
            }
            else{
                nums1[k]=nums2[j];
                j--;
                k--;
            }
        }
        while(j>=0){
            nums1[k]=nums2[j];
            k--;
            j--;
        }
    }
};
int main(){
    Solution obj;
    int m;
    cin>>m;
    int n;
    cin>>n;
    vector<int> nums1(m+n);
    vector<int> nums2(n);
    for(int i=0;i<m;i++){
      cin >> nums1[i];
    }
      for(int i = 0; i < n; i++) {
        cin >> nums2[i];
    }
obj.merge(nums1,m,nums2,n);
cout<<"Output"<<endl;
for(int i:nums1){
    cout<<i<<" ";
}
return 0;

}