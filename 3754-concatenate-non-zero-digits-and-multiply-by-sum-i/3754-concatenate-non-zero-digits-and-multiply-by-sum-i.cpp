// class Solution {
// public:
//     long long sumAndMultiply(int n) {
//         // 1. Handle the base edge case where n itself is 0
//         if (n == 0) return 0;

//         long long x = 0;
//         long long place_value = 1;
//         long long sum = 0;

//         // 2. Loop through all digits
//         while (n > 0) {
//             int digit = n % 10;
            
//             if (digit != 0) {
//                 // Correctly place the digit at the front of x
//                 x = digit * place_value + x;
//                 place_value *= 10;
                
//                 // Directly add the digit to the running sum
//                 sum += digit;
//             }
//             // n /= 10 must run in every iteration, whether digit is 0 or not
//             n /= 10; 
//         }

//         // 3. Return the final required product
//         return x * sum;
//     }
// };

#include <string>

class Solution {
public:
    long long sumAndMultiply(int n) {
        // Convert the number into a string (e.g., 10203 -> "10203")
        std::string num_str = std::to_string(n);
        
        long long x = 0;
        long long sum = 0;

        // Process characters from left to right
        for (char c : num_str) {
            if (c != '0') {
                int digit = c - '0'; // Convert character '5' to integer 5
                
                x = x * 10 + digit;  // Naturally appends to the back of x
                sum += digit;        // Accumulates the sum
            }
        }

        return x * sum;
    }
};

