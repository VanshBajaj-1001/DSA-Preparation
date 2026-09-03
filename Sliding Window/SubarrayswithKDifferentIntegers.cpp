#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int atmost(vector<int> nums,int k){
    int l=0;
    int res=0;
    unordered_map<int,int> freq;
    for(int r=0;r<nums.size();r++){
        if(freq[nums[r]]==0){
            k--;
        }
        freq[nums[r]]++;
        while(k<0){
            freq[nums[l]]--;
            if(freq[nums[l]]==0){
                k++;
            }
            l++;
        }
        res+=(r-l+1);
    }
    return res;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
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
    cout<<obj.subarraysWithKDistinct(nums,k);
    return 0;

}
//another solm
/*
class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        unordered_map<int, int> mp;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            mp[nums[right]]++;

            while (mp.size() > k) {
                mp[nums[left]]--;

                if (mp[nums[left]] == 0)
                    mp.erase(nums[left]);

                left++;
            }

            // All subarrays ending at right
            // from left to right are valid
            ans += right - left + 1;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
*/