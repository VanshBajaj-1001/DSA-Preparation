#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    int k;
	    cin>>n;
	    cin>>k;
	    vector<int> a(n);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    sort(a.begin(),a.end());
	    long long total=0;
	    long long maxinc=0;
	    long long previous=0;
	    for(int i=0;i<n;i++){
	        long long finalval=0;
	        if(a[i]<=previous){
	            finalval=previous+1;
	        }
	        else{
	            finalval=a[i];
	        }
	        long long inc=finalval-a[i];
	        total+=inc;
	        maxinc=max(maxinc,inc);
	        previous=finalval;
	    }
	    long long noofoperation=max(maxinc,(total+k-1)/k);
	    cout<<noofoperation<<endl;
	}
return 0;
}
