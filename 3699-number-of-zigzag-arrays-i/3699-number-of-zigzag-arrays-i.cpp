class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<long long> up(m), down(m);
        vector<long long> nup(m), ndown(m);
        vector<long long> prefUp(m + 1), prefDown(m + 1);

        // Length = 2
        for (int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - 1 - i;
        }

        if (n == 2) {
            long long ans = 0;
            for (int i = 0; i < m; i++) {
                ans = (ans + up[i] + down[i]) % MOD;
            }
            return (int)ans;
        }

        for (int len = 3; len <= n; len++) {

            prefUp[0] = prefDown[0] = 0;

            for (int i = 0; i < m; i++) {
                prefUp[i + 1] = (prefUp[i] + up[i]) % MOD;
                prefDown[i + 1] = (prefDown[i] + down[i]) % MOD;
            }

            long long totalUp = prefUp[m];

            for (int i = 0; i < m; i++) {
                // Previous value < current value
                nup[i] = prefDown[i];

                // Previous value > current value
                ndown[i] = (totalUp - prefUp[i + 1] + MOD) % MOD;
            }

            swap(up, nup);
            swap(down, ndown);
        }

        long long ans = 0;

        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return (int)ans;
    }
};