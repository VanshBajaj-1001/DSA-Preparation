#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
	int precedence(char c) {
		if (c == '^')
			return 3;
		if (c == '*' || c == '/')
			return 2;
		if (c == '+' || c == '-')
			return 1;
		return - 1;
	}
	
	string infixToPostfix(string& s) {
		// code here
		stack<char>st;
		string ans = "";
		for (int i = 0; i<s.size(); i++) {
			char c = s[i];
			if (isalnum(c)) {
				ans += c;
			}
			else if (c == '(') {
				st.push(c);
			}
			else if (c == ')') {
				while (!st.empty() && st.top() != '(') {
					ans += st.top();
					st.pop();
				}
				if (!st.empty()) {
					st.pop();
				}
			}
			else {
				while (!st.empty() && st.top() != '(' && (precedence(st.top()) > precedence(c) ||
				(precedence(st.top()) == precedence(c) && c != '^'))){
				    ans+=st.top();
				    st.pop();
				}
				st.push(c);
			}
		}
		while(!st.empty()){
		    ans+=st.top();
		    st.pop();
		}
		return ans;
	}
};
