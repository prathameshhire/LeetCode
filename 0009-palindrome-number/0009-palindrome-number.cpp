class Solution {
public:
    bool isPalindrome(int x) {
        long long a=0;
        long long temp=x;
        if (x<0) {
            return false;
        }
        while (x>0) {
            int b=x%10;
            a=a*10 +b;
            x=x/10;
        }
        if (a==temp) {
            return true;
        }
        else {
            return false;
        }
    }
};