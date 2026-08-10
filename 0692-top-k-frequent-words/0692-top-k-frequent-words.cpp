class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        for (string word : words) {
            freq[word]++;
        }

        vector<string> v;
        for (auto &it : freq) {
            v.push_back(it.first);
        }

        sort(v.begin(), v.end(), [&](string &a, string &b) {
            if (freq[a] != freq[b])
                return freq[a] > freq[b];   // higher frequency first

            return a < b;                    // alphabetical order
        });

        // Take first k
        return vector<string>(v.begin(), v.begin() + k);
    }
};