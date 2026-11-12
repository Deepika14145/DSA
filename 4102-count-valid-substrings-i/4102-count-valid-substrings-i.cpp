// // // class Solution {
// // // public:
// // //     long long countValidSubstrings(string s) {
// // //         int n = s.size();
// // //         int count = 0; 
// // //         for(int i = 0; i<s.size(); i++){
// // //             string temp = "";

// // //             for(int j = i; j<n; j++){
// // //                 temp += s[j];

// // //                 if(temp.find("abc") == string::npos){
// // //                     count++;
// // //                 }
// // //             }
// // //         }
// // //         return count;
// // //     }
// // // };


// // class Solution {
// // public:
// //     long long countValidSubstrings(string s) {
// //         int n = s.size();
// //         long long ans = 0;

// //         for (int i = 0; i < n; i++) {
// //             bool valid = true;

// //             for (int j = i; j < n; j++) {

// //                 if (j >= i + 2 &&
// //                     s[j - 2] == 'a' &&
// //                     s[j - 1] == 'b' &&
// //                     s[j] == 'c') {
// //                     valid = false;
// //                 }

// //                 if (valid)
// //                     ans++;
// //                 else
// //                     break;
// //             }
// //         }

// //         return ans;
// //     }
// // };


// class Solution {
// public:
//     long long countValidSubstrings(string s) {
//         long long n = s.size();

//         long long total = n * (n + 1) / 2;
//         long long invalid = 0;

//         for (int i = 0; i + 2 < n; i++) {
//             if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') {
//                 invalid += (i + 1) * (n - i - 2);
//             }
//         }

//         return total - invalid;
//     }
// };
class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        int left = 0;
        long long ans = 0;

        for (int right = 0; right < n; right++) {
            if (right >= 2 && s[right-2] == 'a' &&
                s[right-1] == 'b' && s[right] == 'c') {
                left = right - 1;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};