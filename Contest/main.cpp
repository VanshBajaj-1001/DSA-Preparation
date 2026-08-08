#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n){
  if(n<2){
    return false;
  }
  for(int i=2;i<=sqrt(n);i++){
  if(n%i==0){
    return false;
  }
  }
  return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        if(isPrime(n+1)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}