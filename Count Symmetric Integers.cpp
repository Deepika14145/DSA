//bruteforce approach

class Solution {
public:

    int sumOfDigits(string s, int start, int end){
        int sum = 0;
        for(int i = start; i<end; i++){
            sum += s[i] - '0';
        }
        return sum;
    }

    int countSymmetricIntegers(int low, int high) {
        int count=0;

        for(int num = low; num <= high; num++){
            string str = to_string(num);
            int len = str.length();

            if(len%2 != 0)
                continue;
            
            int mid = len / 2;
            int leftsum = sumOfDigits(str, 0, mid);
            int rightSum = sumOfDigits(str, mid, len);

            if(leftsum == rightSum){
                count++;
            }
        }
        return count;
    }
};
