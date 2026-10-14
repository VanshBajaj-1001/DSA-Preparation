#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> maxsubsequence(vector<int>& nums,int k){
    stack<int> st;
    int remove=nums.size()-k;
    for(int i:nums){
        while(!st.empty()&&remove>0&&st.top()<i){
            st.pop();
            remove--;
        }
        st.push(i);
    }
    int n=st.size();
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        ans[i]=st.top();
        st.pop();
    }
    ans.resize(k);
    return ans;
}
bool greatersuffix(vector<int>& a,int i,vector<int>& b,int j){
    while(i<a.size()&&j<b.size()&&a[i]==b[j]){
        i++;
        j++;
    }
    if(j==b.size()){
        return true;
    }
    if(i==a.size()){
        return false;
    }
    return a[i]>b[j];
}
vector<int> merge(vector<int> a,vector<int>& b){
    vector<int> res;
    int i=0;int j=0;
    while(i<a.size()||j<b.size()){
        if (j == b.size() || (i < a.size() && greatersuffix(a, i, b, j))){
            res.push_back(a[i]);
            i++;
        }
        else{
            res.push_back(b[j]);
            j++;
        }
    }
    return res;
}
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans;
        for(int i=max(0,k-m);i<=min(k,n);i++){
            vector<int> a=maxsubsequence(nums1,i);
            vector<int> b=maxsubsequence(nums2,k-i);
            vector<int> candidate=merge(a,b);
            if(candidate>ans){
                ans=candidate;
            }

        }
        return ans;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int> nums1(n);
    for(int i=0;i<n;i++){
        cin>>nums1[i];

    }
    int m;
    cin>>m;
    vector<int> nums2(m);
    for(int i=0;i<m;i++){
        cin>>nums2[i];
    }
    int k;
    cin>>k;
    vector<int> ans=obj.maxNumber(nums1,nums2,k);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}