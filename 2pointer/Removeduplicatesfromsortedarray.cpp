#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        int i, j;
        i = 0;
        for (j = 1; j < nums.size(); j++)
        {
            if (nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
        ;
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
     int ans=obj.removeDuplicates(nums);
     cout<<ans<<endl;
     return 0;
}