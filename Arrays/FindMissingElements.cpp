#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int minimum=*min_element(nums.begin(),nums.end());
        int maximum=*max_element(nums.begin(),nums.end());
        unordered_set<int> s;
        for(int i:nums){
            s.insert(i);
        }
        for(int i=minimum;i<=maximum;i++){
            if(s.find(i)==s.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
int main(){
    Solution obj;
    int n;
    cout<<"Enter Number of Elements in the array"<<endl;
    cin>>n;
    vector<int> ans(n);
    cout<<"Enter Elements in the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>ans[i];
    }
 vector<int> res=obj.findMissingElements(ans);
 cout<<"Output "<<endl;
 for(int i:res){
    cout<<i<<" ";
 }
 cout<<endl;
 return 0;
}