#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int odd = 0;
        int total = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            total += x;
            if (x % 2!=0) {
                odd++;
            }
        }
            if (total % 2 == 0) {
                cout << total - odd / 2 << endl;
            }
            else {
                cout << (odd - 1) / 2 << endl;
            }
    }
    return 0;
}