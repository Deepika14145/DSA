#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int freq[11] = {0}; // index 1 to 10
        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            freq[x]++;
        }

        int maxFreq = 0, count = 0, laptop = -1;

        for (int i = 1; i <= 10; ++i) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                count = 1;
                laptop = i;
            }
            else if (freq[i] == maxFreq) {
                count++;
            }
        }

        if (count == 1)
            cout << laptop << endl;
        else
            cout << "CONFUSED" << endl;
    }

    return 0;
}
