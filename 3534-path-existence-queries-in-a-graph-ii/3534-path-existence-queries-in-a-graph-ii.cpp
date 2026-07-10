class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        // pos[node] = position in sorted array
        vector<int> pos(n);

        // component id of each position
        vector<int> comp(n);

        int id = 0;
        comp[0] = 0;
        pos[arr[0].second] = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i].first - arr[i - 1].first > maxDiff)
                id++;
            comp[i] = id;
            pos[arr[i].second] = i;
        }

        // next[i] = farthest position reachable in one edge
        vector<int> nxt(n);
        int r = 0;
        for (int l = 0; l < n; l++) {
            while (r + 1 < n && arr[r + 1].first - arr[l].first <= maxDiff)
                r++;
            nxt[l] = r;
        }

        int LOG = 20;
        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            up[0][i] = nxt[i];

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int a = pos[q[0]];
            int b = pos[q[1]];

            if (a > b)
                swap(a, b);

            if (comp[a] != comp[b]) {
                ans.push_back(-1);
                continue;
            }

            if (a == b) {
                ans.push_back(0);
                continue;
            }

            int cur = a;
            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < b) {
                    steps += (1 << k);
                    cur = up[k][cur];
                }
            }

            ans.push_back(steps + 1);
        }

        return ans;
    }
};