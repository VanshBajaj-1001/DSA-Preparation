#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while(num>=10){
            int sum=0;
            while(num>0){
                sum+=num%10;
                num/=10;
            }
            num=sum;
        }
        return num;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    cout<<obj.addDigits(n)<<endl;
    return 0;
}