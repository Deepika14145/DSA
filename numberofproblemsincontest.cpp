#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;  // Number of test cases

    while (T--) {
        int N;
        cin >> N;  // Number of problems
        
        int start38_count = 0, ltime108_count = 0;
        string contest_code;
        
        // Count occurrences of START38 and LTIME108
        for (int i = 0; i < N; i++) {
            cin >> contest_code;
            if (contest_code == "START38")
                start38_count++;
            else if (contest_code == "LTIME108")
                ltime108_count++;
        }

        // Output result for the test case
        cout << start38_count << " " << ltime108_count << endl;
    }
    return 0;
}
