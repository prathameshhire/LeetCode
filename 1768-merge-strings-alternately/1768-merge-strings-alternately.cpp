class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = "";
        int i=0, j=0;
        while (i<word1.length() && j<word2.length()) {
            s += word1[i++];
            s += word2[j++];
        }
        s += word1.substr(i); 
        s += word2.substr(j); 
        return s;
    }
};