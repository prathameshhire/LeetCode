class Solution {
public:
    int waviness(int i) {
        string s = to_string(i);
        int valley, peak = 0;
        for(int j = 1; j < s.length()-1; j++) {
            if(s[j] > s[j-1] && s[j] > s[j+1]) peak++;
            if(s[j] < s[j-1] && s[j] < s[j+1]) valley++;
        }
        return peak + valley;
    }
    int totalWaviness(int num1, int num2) {
        int result = 0;
        for(int i = num1; i <= num2; i++) {
            result += waviness(i);
        }
        return result;
    }
};