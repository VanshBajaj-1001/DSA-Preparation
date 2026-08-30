#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long power(long long x,long long y){
        long long ans=1;
        long long mod=1000000007;
        while(y>0){
            if(y%2==1){
                ans=(ans*x)%mod;
            }
            x=(x*x)%mod;
            y/=2;
        }
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        long long mod=1000000007;
        long long sum=0;
        for(long long i:nums){
            int width=i%10;
            long long d=i/10;
            long long temp=d;
            int digitinD=0;
            while(temp>0){
                digitinD++;
                temp/=10;
            }
            long long divisor=1;
            for(int i=0;i<digitinD-width;i++){
                divisor*=10;
            }
            long long x=d/divisor;
            long long y=d%divisor;
            sum=(sum+power(x,y))%mod;
        }
        return sum;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<long long> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<obj.sumDecoded(nums)<<endl;
    return 0;
}