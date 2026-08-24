#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cout << "Enter number: ";
    cin >> n;

    if (n & 1) {
        cout << "Odd";
    } else {
        cout << "Even";
    }

    return 0;
}