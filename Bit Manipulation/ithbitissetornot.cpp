#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i;

    cout << "Enter number: ";
    cin >> n;

    cout << "Enter bit position: ";
    cin >> i;

    if ((n >> i) & 1) {
        cout << "The " << i << "-th bit is set";
    } else {
        cout << "The " << i << "-th bit is not set";
    }

    return 0;
}