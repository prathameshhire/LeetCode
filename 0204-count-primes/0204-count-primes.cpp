class Solution {
public:
    int countPrimes(int n) {
        const int N = 5*1e6;
        vector<int> isPrime (N,1);
        isPrime[0] = isPrime[1] = 0;
        for (int i = 2; i< n; i++) {
            if (isPrime[i]==1) {
                for (int j=i*2; j < n; j+=i) {
                    isPrime[j] = 0;
                }
            }
        }
        int count = 0;
        for (int i=0; i<n; i++) {
            if (isPrime[i] == 1) {
                count ++;
            }
        }
        return count;
    }
};