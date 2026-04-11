class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string result = "";
        for(int i = 0; i<numRows; i++) {
            int increment = (numRows-1) * 2;
            for (int j = i; j<s.length(); j+=increment) {
                result += s[j];
                if (i > 0 && i < numRows-1 && j + increment-2*i < s.length()) {
                    result += s[j+increment-2*i];
                }
            }
        }
        return result;
    }
};