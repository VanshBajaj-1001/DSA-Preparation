#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0;
        int right = people.size()-1;
        int boats = 0;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
            }
            right--;
            boats++;
        }
        return boats;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int> people(n);
    for(int i=0;i<n;i++){
        cin>>people[i];
    }
    int limit;
    cin>>limit;
    int ans=obj.numRescueBoats(people,limit);
    cout<<ans<<endl;
    return 0;
}