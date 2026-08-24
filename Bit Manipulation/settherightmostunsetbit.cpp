#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cout << "Enter number: ";
    cin >> n;

    n = n | (n + 1);

    cout << "After setting rightmost unset bit: " << n;

    return 0;
}