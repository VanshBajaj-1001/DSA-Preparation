#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int w;
cin>>w;
int n;
cin>>n;
vector<int> weights(n);
for(int i=0;i<n;i++){
    cin>>weights[i];
}
sort(weights.begin(),weights.end(),greater<int>());
int sum=0;
int units=0;
for(int i=0;i<n;i++){
    sum+=weights[i];
    units++;
    if(sum>=w){
        cout<<units;
        return 0;
    }
    sum+=weights[i];
    units++;
    if(sum>=w){
        cout<<units;
        return 0;
    }
}
cout<<-1;
return 0;
}
