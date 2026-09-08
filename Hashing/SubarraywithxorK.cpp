#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
  int countSubarrays(vector<int>& A, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;

        int prefixXor = 0;

        int count = 0;
        for (int num : A) {
            prefixXor ^= num;
            int target = prefixXor ^ k;   
            if (freq.find(target) != freq.end()) {
                count += freq[target];
            }
            freq[prefixXor]++;
        }
        return count;
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
    int k;
    cin>>k;
    cout<<obj.countSubarrays(nums,k)<<endl;
    return 0;
}