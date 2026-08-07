constexpr uint8_t DIV_GCD[10][10] = {
    {},
    {1},
    {2, 1},
    {3, 1, 1},
    {4, 1, 2, 1},
    {5, 1, 1, 1, 1},
    {6, 1, 2, 3, 2, 1},
    {7, 1, 1, 1, 1, 1, 1},
    {8, 1, 2, 1, 4, 1, 2, 1},
    {9, 1, 1, 3, 1, 1, 3, 1, 1},
};

constexpr int MAX_SIZE = 200001;

long long remainingFactor[MAX_SIZE];
char answerBuffer[MAX_SIZE + 1];

class Solution {
public:
    string smallestNumber(string num, long long t) {

        long long checkFactor = t >> __builtin_ctzll(t);

        for (int prime : {3, 5, 7}) {
            while (checkFactor % prime == 0)
                checkFactor /= prime;
        }

        if (checkFactor > 1)
            return "-1";

        int length = num.size();

        remainingFactor[0] = t;
        remainingFactor[length] = 0;

        int firstZero = length - 1;

        for (int i = 0; i < length; i++) {

            if (num[i] == '0') {
                firstZero = i;
                break;
            }

            int digit = num[i] - '0';

            remainingFactor[i + 1] =
                remainingFactor[i] /
                DIV_GCD[digit][remainingFactor[i] % digit];
        }

        if (remainingFactor[length] == 1)
            return num;

        for (int i = firstZero; i >= 0; i--) {

            while (++num[i] <= '9') {

                int digit = num[i] - '0';

                long long currentNeed =
                    remainingFactor[i] /
                    DIV_GCD[digit][remainingFactor[i] % digit];

                int largestDigit = 9;

                for (int j = length - 1; j > i; j--) {

                    while (currentNeed % largestDigit != 0)
                        largestDigit--;

                    currentNeed /= largestDigit;
                    num[j] = largestDigit + '0';
                }

                if (currentNeed == 1)
                    return num;
            }
        }

        int bufferIndex = MAX_SIZE + 1;

        for (int digit = 9; digit > 1; digit--) {

            while (t % digit == 0) {
                answerBuffer[--bufferIndex] = digit + '0';
                t /= digit;
            }
        }

        while (MAX_SIZE - bufferIndex < length)
            answerBuffer[--bufferIndex] = '1';

        return string(answerBuffer + bufferIndex,
                      MAX_SIZE + 1 - bufferIndex);
    }
};