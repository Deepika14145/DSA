// User function Template for C++
class Solution {
  public:
    long long count(int n) {
        int totalEdges = n * (n - 1)/2;
        long long result = 1LL << totalEdges;
        
        return result;
    
    }
};
