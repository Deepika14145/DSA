class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()); 
    
        int high= 0;
        for(int w : weights){
            high += w;
        }

        while(low < high){
            int capacity = low + (high - low) /2;

            int day = 1;
            int currWeight = 0;

            for(int w : weights){
                if(currWeight + w > capacity){
                    day++;
                    currWeight= 0;
                }
                currWeight += w;
            }

            if(day<=days){
             high = capacity;
            }else{
            low = capacity + 1;
            }
        }
    return low;
    }
};
