#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int n;
cin>>n;
vector<int> a(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}
int count =1;
int minspeed=a[0];
for(int i=1;i<n;i++){
    if(a[i]<minspeed){
        count+=1;
        minspeed=a[i];
    }
}
cout<<count<<endl;
return 0;
}
