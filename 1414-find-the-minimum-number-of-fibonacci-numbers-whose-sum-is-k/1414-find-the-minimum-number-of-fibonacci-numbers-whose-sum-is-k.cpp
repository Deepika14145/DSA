class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib = {1,1};

        while(true){
            int next = fib[fib.size() -1] + fib[fib.size() - 2];

            if(next > k)
                break;

            fib.push_back(next);
        }


        int ans = 0;

        for(int i = fib.size() -1; i>= 0 && k > 0; i--){
            if(fib[i] <= k){
                k -= fib[i];
                ans++;
            }
        }
        return ans;

        
    }
};