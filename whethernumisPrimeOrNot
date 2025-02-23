#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;  // 1 is not prime
    if (n <= 3) return true;   // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return false;  // Eliminate even numbers and multiples of 3

    for (int i = 5; i * i <= n; i += 2) { 
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << (isPrime(N) ? "yes" : "no") << endl;
    }
    return 0;
}
