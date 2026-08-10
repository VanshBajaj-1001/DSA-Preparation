#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	int score1=0;
	int score2=0;
   int L=0; //maxlead
   int W=0;  //winner
   for(int i=0;i<n;i++){
       int S,T;
       cin>>S;
       cin>>T;
       score1+=S;
       score2+=T;
       int lead;
       if(score1>score2){
           lead=score1-score2;
           if(lead>L){
               L=lead;
               W=1;
           }
       }
       else{
           lead=score2-score1;
           if(lead>L){
               L=lead;
               W=2;
           }
       }
   }
   cout<<W<<" "<<L<<endl;
   return 0;
}
