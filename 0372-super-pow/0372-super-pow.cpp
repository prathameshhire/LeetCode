class Solution {
private:
    int binExp(int a, int b, int m) {
        a %= m;
        int ans = 1;
        while (b > 0) {
            if (b & 1) {
                ans = (ans * 1LL * a) % m;
            }
            a = (a * 1LL * a) % m;
            b >>= 1;
        }
        return ans;
    }
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last_digit = b.back();
        b.pop_back();
        return (binExp(superPow(a, b), 10, 1337) * binExp(a, last_digit, 1337)) % 1337;
    }
};