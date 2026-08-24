#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int y;
	int x;
	int k;
	cin>>x;
	cin>>y;
	cin>>k;
	int distance=abs(y-x);
	if(distance<=k){
	    cout<<"YES";
	}
	else{
	    cout<<"NO";
	}
	return 0;

}
