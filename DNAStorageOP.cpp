// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         string s;
//         cin >> s;

//         string result = "";
        
//         for (int i = 0; i < n; i += 2) {
//             string pair = s.substr(i, 2); // Extract two characters at a time
            
//             if (pair == "00") result += 'A';
//             else if (pair == "01") result += 'T';
//             else if (pair == "10") result += 'C';
//             else if (pair == "11") result += 'G';
//         }

//         cout << result << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <unordered_map>
using namespace std;

// Function to encode binary string to DNA sequence
string encodeDNA(const string &binaryString) {
    unordered_map<string, char> encoding = {
        {"00", 'A'},
        {"01", 'T'},
        {"10", 'C'},
        {"11", 'G'}
    };
    
    string dnaSequence = "";
    for (size_t i = 0; i < binaryString.length(); i += 2) {
        string pair = binaryString.substr(i, 2);
        dnaSequence += encoding[pair];
    }
    return dnaSequence;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        string binaryString;
        cin >> N >> binaryString;
        cout << encodeDNA(binaryString) << endl;
    }
    return 0;
}
