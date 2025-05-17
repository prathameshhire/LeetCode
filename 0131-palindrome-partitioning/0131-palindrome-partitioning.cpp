class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> substring;
        rec(s,res,substring,0);
        return res;
    }
    void rec(const string &s, vector<vector<string>> &res, vector<string> &substring, int i) {
        if (i >= s.length()) { // check i == s.length()
            res.push_back(substring);
            return;
        }
        for (int j = i; j<s.length(); j++) {
            if (isPali(s,i,j)) {
                substring.push_back(s.substr(i,j-i+1));
                rec(s,res,substring,j+1);
                substring.pop_back();
            }
        }
    }
    bool isPali(const string &s, int i, int j) { 
        while (i<j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
};