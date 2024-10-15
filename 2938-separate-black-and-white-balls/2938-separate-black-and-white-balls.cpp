class Solution {
public:
    long long minimumSteps(string s) {
        int black=0;
        long long swap=0;
        for (char ch:s) {
            if (ch == '1') {
                black++;
            }
            if (ch == '0') {
                swap+=black;
            }
        }
        return swap;
    }
};