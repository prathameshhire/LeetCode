class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        long long mod = 1000000007;

        for (int i = 1; i<complexity.size(); i++) {
            if (complexity[0] >= complexity[i])
                return 0;
        }

        long long fact = 1;
        for (int i = 2; i<complexity.size(); i++) {
            fact = (fact*i)%mod;
        }
        return static_cast<int>(fact);
    }
};