class Solution {
public:
    int climbStairs(int n) {
        if (n<=2) return n;
        vector<int> array(n+1);
        int a = 1;
        int b = 2;
        int c = 3;
        for (int i = 3; i<=n; i++) {
            c = a + b;
            int temp = b;
            a = temp;
            b = c;
        }
        return c;
    }
};