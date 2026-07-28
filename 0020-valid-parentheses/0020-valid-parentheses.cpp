// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> st;

//         for (char ch : s) {
//             if (ch == '(' || ch == '{' || ch == '[') {
//                 st.push(ch);
//             } else {
//                 if (st.empty()) return false;

//                 if ((ch == ')' && st.top() != '(') ||
//                     (ch == '}' && st.top() != '{') ||
//                     (ch == ']' && st.top() != '['))
//                     return false;

//                 st.pop();
//             }
//         }

//         return st.empty();
//     }
// };

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(')
                st.push(')');
            else if (ch == '{')
                st.push('}');
            else if (ch == '[')
                st.push(']');
            else {
                if (st.empty() || st.top() != ch)
                    return false;
                st.pop();
            }
        }

        return st.empty();
    }
};