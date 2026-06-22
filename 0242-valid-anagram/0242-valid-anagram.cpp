// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         //maintain hashtable
//         if(s.size() != t.size())
//             return false;

//         int cnt[26] = {0};

//         for(int i = 0; i< s.size(); i++)
//             cnt[s[i] - 'a']++;

//         for(int i = 0; i < t.size(); i++)
//             cnt[t[i] - 'a']--;

//         for(int i = 0; i<26; i++)       //check if any dissimilar char exists or not
//             if(cnt[i] != 0)
//                 return false;

//         return true;
        
//     }
// };

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());

//         return s == t;
//     }
// };

class Solution {
public:
    bool isAnagram(string s, string t){
        if(s.size() != t.size())
            return false;

        unordered_map<char, int> mp;

        for(char ch : s)
            mp[ch]++;

        for(char ch : t)
            mp[ch]--;

        for(auto &p : mp)
            if(p.second != 0)
                return false;

        return true;
    }
};
