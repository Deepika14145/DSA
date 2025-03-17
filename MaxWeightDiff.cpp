#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> weights(n);
        for (int i = 0; i < n; ++i) {
            cin >> weights[i];
        }
        sort(weights.begin(), weights.end());
        long long sum1 = 0;
        long long sum2 = 0;
        if (k <= n / 2) {
            for (int i = 0; i < k; ++i) {
                sum1 += weights[i];
            }
            for (int i = k; i < n; ++i) {
                sum2 += weights[i];
            }
        } else {
            for (int i = 0; i < n - k; ++i) {
                sum1 += weights[i];
            }
            for (int i = n - k; i < n; ++i) {
                sum2 += weights[i];
            }
        }
        cout << abs(sum2 - sum1) << endl;
    }
    return 0;
}
