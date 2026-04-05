class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> characters(26, 0);
        vector<int> digits(10, 0);
        for (char &c : s) {
            if (c - 'a' < 0) {
                digits[c-'0']++;
            }else{
                characters[c-'a']++;
            }
        }
        int result = 0;
        int i = 0;
        int j = 25;
        while(i<j) {
            result += abs(characters[i] - characters[j]);
            i++;
            j--;
        }
        i = 0;
        j = 9;
        while(i<j) {
            result += abs(digits[i] - digits[j]);
            i++;
            j--;
        }
        return result;
    }
};