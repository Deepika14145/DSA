class Solution {
public:
    string smallestNumber(string number, long long target) {

        long long tempTarget = target;

        for (int factor = 2; factor <= 9; factor++) {
            while (tempTarget % factor == 0) {
                tempTarget /= factor;
            }
        }

        if (tempTarget != 1) {
            return "-1";
        }

        int length = number.size();
        vector<char> result(number.begin(), number.end());

        vector<long long> remainingTarget(length + 1, 0);
        remainingTarget[0] = target;

        int firstZeroIndex = length - 1;

        for (int index = 0; index < length; index++) {

            int currentDigit = result[index] - '0';

            if (currentDigit == 0) {
                firstZeroIndex = index;
                break;
            }

            long long commonFactor = gcd(remainingTarget[index], (long long)currentDigit);
            remainingTarget[index + 1] = remainingTarget[index] / commonFactor;
        }

        if (remainingTarget[length] == 1) {
            return number;
        }

        for (int index = firstZeroIndex; index >= 0; index--) {

            int originalDigit = result[index] - '0';

            for (int candidateDigit = originalDigit + 1; candidateDigit <= 9; candidateDigit++) {

                result[index] = char('0' + candidateDigit);

                long long requiredValue = remainingTarget[index];
                requiredValue /= gcd(requiredValue, (long long)candidateDigit);

                vector<char> suffixDigits;

                for (int pos = index + 1; pos < length; pos++) {

                    int bestDigit = 9;

                    while (bestDigit > 1 && requiredValue % bestDigit != 0) {
                        bestDigit--;
                    }

                    if (requiredValue % bestDigit == 0) {
                        requiredValue /= bestDigit;
                    }

                    suffixDigits.push_back(char('0' + bestDigit));
                }

                if (requiredValue == 1) {

                    reverse(suffixDigits.begin(), suffixDigits.end());

                    for (int pos = index + 1; pos < length; pos++) {
                        result[pos] = suffixDigits[pos - index - 1];
                    }

                    return string(result.begin(), result.end());
                }
            }

            result[index] = number[index];
        }

        vector<char> factorDigits;
        long long remainingValue = target;

        for (int digit = 9; digit >= 2; digit--) {
            while (remainingValue % digit == 0) {
                factorDigits.push_back(char('0' + digit));
                remainingValue /= digit;
            }
        }

        int finalLength = max(length + 1, (int)factorDigits.size());

        while ((int)factorDigits.size() < finalLength) {
            factorDigits.push_back('1');
        }

        reverse(factorDigits.begin(), factorDigits.end());

        return string(factorDigits.begin(), factorDigits.end());
    }
};