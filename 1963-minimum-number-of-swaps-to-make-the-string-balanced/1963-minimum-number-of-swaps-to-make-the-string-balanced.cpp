class Solution {
public:
    int minSwaps(string s) {
        int max=0, close=0;
        for (char ch: s) {
            if (ch=='[') {
                close--;
            }
            if (ch==']') {
                close++;
                if (close>max) {
                    max=close;
                }
            }
        } 
        return (max+1)/2;
    }
};