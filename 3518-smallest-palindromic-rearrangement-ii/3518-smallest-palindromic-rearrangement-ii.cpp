class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = (int)s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        // Build half counts
        vector<int> half(26, 0);
        for (int i = 0; i < 26; ++i) half[i] = cnt[i] / 2;

        // Middle character (if any)
        char mid = 0;
        if (n % 2 == 1) {
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] % 2 == 1) {
                    mid = char('a' + i);
                    break;
                }
            }
        }

        int halfLen = n / 2;
        string firstHalf;
        firstHalf.reserve(halfLen);

        // Precompute factorials is not needed; we'll compute multinomials with capping.

        // Helper: compute number of permutations of multiset 'cnts' with capping at cap
        auto countWays = [&](const vector<int>& cnts, long long cap) -> long long {
            int total = 0;
            for (int x : cnts) total += x;
            if (total == 0) return 1;

            // We'll compute multinomial: total! / prod(cnt[i]!)
            // But instead of huge numbers, we build it step by step with capping.
            // Use: ways = 1; for each char, ways *= C(remaining, cnt[i]); remaining -= cnt[i];
            long long ways = 1;
            int remaining = total;

            for (int c = 0; c < 26; ++c) {
                int cntc = cnts[c];
                if (cntc == 0) continue;

                // Multiply ways by C(remaining, cntc), with capping
                // C(n, k) = n! / (k!(n-k)!)
                // We'll compute it iteratively: product_{i=1..k} (n - k + i) / i
                int kk = cntc;
                if (kk > remaining - kk) kk = remaining - kk;

                // Compute C(remaining, cntc) with capping
                long long comb = 1;
                for (int i = 1; i <= kk; ++i) {
                    // comb = comb * (remaining - kk + i) / i
                    // To keep integer division exact, do multiplication first.
                    // But it can overflow, so we use __int128 for intermediate.
                    __int128 tmp = comb;
                    tmp = tmp * (remaining - kk + i);
                    tmp /= i;
                    comb = (long long)tmp;
                    if (comb > cap) {
                        comb = cap + 1; // cap+1 means "more than cap"
                        break;
                    }
                }

                // ways *= comb, with capping
                __int128 w = ways;
                w = w * comb;
                if (w > cap) {
                    ways = cap + 1;
                } else {
                    ways = (long long)w;
                }

                if (ways > cap) {
                    // No need to continue; already more than cap
                    return ways;
                }

                remaining -= cntc;
            }

            return ways;
        };

        long long K = k;

        for (int pos = 0; pos < halfLen; ++pos) {
            bool placed = false;
            for (int c = 0; c < 26; ++c) {
                if (half[c] == 0) continue;

                // Try placing char c here
                half[c]--;

                // Count number of ways to complete the rest
                long long ways = countWays(half, K);

                if (K > ways) {
                    K -= ways;
                    half[c]++; // revert choice
                } else {
                    // Choose this char
                    firstHalf.push_back(char('a' + c));
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                // Not enough permutations
                return "";
            }
        }

        // Build final palindrome
        string res = firstHalf;
        if (mid) res.push_back(mid);
        string rev = firstHalf;
        reverse(rev.begin(), rev.end());
        res += rev;

        return res;
    }
};