#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int n;
cin>>n;
vector<int> nums(n);
for(int i=0;i<n;i++){
    cin>>nums[i];
}
int x;
cin>>x;
int count=0;
for(int i=0;i<n;i++){
    if(nums[i]==x){
        count+=1;
        if(count==2){
            cout<<i;
            return 0;
        }
    }
}
if (count==1){
    cout<<-2;
}
else{
    cout<<-1;
}
return 0;
}
