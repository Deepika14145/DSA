#sliding windows
class Solution {
public:
    int kDistinctChar(string& s, int k) {
       int maxLen = 0;
       int left = 0;
       unordered_map<int, int> freq;

       for(int right = 0; right<s.length(); ++right){
        freq[s[right]]++;

        while(freq.size() > k){
            freq[s[left]]--;
            if(freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
       } 
       return maxLen;
    }
};
