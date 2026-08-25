#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n,true);
        if(n<=2){
            return 0;
        }
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i=3;i*i<n;i+=2){
            if(isPrime[i]){
                for(int j=i*i;j<n;j+=2*i){
                     isPrime[j]=false;
                }
            }
        }
        int count=1;
        for(int i=3;i<n;i+=2){
            if(isPrime[i]){
                count++;
            }
        }
        return count;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    int ans=obj.countPrimes(n);
    cout<<ans<<endl;
    return 0;
}