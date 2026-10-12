#include <bits/stdc++.h>
using namespace std;
class StockSpanner {
public:
stack<pair<int,int>> st;//first stores the price and second stores that price's span
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        while(!st.empty()&&st.top().first<=price){
            span+=st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};
