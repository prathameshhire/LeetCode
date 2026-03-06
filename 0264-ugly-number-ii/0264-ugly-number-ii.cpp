class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> t(n+1);
        
        t[1] = 1;

        int twoMult = 1;
        int threeMult = 1;
        int fiveMult = 1;

        for (int i = 2; i<=n; i++) {
            int secondMult = t[twoMult]*2;
            int thirdMult = t[threeMult]*3;
            int fifthMult = t[fiveMult]*5;

            int uglyNumber = min({secondMult, thirdMult, fifthMult});
            
            t[i] = uglyNumber;
            
            if (uglyNumber == secondMult) twoMult++;
            if (uglyNumber == thirdMult) threeMult++;
            if (uglyNumber == fifthMult) fiveMult++;
        
            
        }

        return t[n];
    }
};