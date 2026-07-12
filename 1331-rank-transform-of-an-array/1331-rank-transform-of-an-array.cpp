class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        unordered_map<int, int> mp;
        int rank = 1;

        for (int x : temp) {
            if (!mp.count(x))
                mp[x] = INT_MAX;

            mp[x] = min(mp[x], rank);

            if (mp[x] == rank)
                rank++;
        }

        for (int &x : arr)
            x = mp[x];

        return arr;
    }
};