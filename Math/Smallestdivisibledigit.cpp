#include <iostream>
using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {
        int num=n;
        for(int i=n;;i++){
    int temp=i;
    int prod=1;
    while(temp>0){
        prod=prod*(temp%10);
        temp/=10;
    }
    if(prod%t==0){
        return i;
    }
        }
        return -1;
    }
};
int main(){
    Solution obj;
    int n;
    int t;
    cout<<"Enter values for n and t"<<endl;
    cin>>n;
    cin>>t;
    cout<<"Output "<<obj.smallestNumber(n,t);
    return 0;
}