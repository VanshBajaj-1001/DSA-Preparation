#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int x;
int a;
int y;
int b;
int d;
cin>>x;
cin>>a;
cin>>y;
cin>>b;
cin>>d;
int rev=x*a +y*b;
if(rev>=d){
    cout<<"YES";
}
else{
cout<<"NO";
}
return 0;
}
