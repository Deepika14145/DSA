class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        string prefix = strs[0];

        for(int i = 1; i< strs.size(); ++i){

            int j = 0;
            while(j< prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]){
                ++j;
            }

            prefix = prefix.substr(0, j); 

            if(prefix.empty()) return "";
        }
        return prefix;

    }
};

//approach two- if prefix is not updated again and again , only we have to iterate over each char and then compare;
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";  // Handle edge case: empty array

    // Iterate over characters of the first string
    for (int i = 0; i < strs[0].length(); ++i) {
        char c = strs[0][i];  // Current character in the first string

        // Compare with the corresponding character in other strings
        for (int j = 1; j < strs.size(); ++j) {
            // If out of bounds or mismatch, return the common prefix so far
            if (i >= strs[j].length() || strs[j][i] != c) {
                return strs[0].substr(0, i);
            }
        }
    }

    // If we finish iterating through the first string, it is the common prefix
    return strs[0];
}
