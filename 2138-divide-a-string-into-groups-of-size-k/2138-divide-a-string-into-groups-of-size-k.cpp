class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string> result;
        int i = 0;
        while (i<n) {
            int j = (i+k-1 < n) ? i+k-1 : n-1;
            string sub = s.substr(i,j-i+1);
            if (j-i+1 < k) {
                int remaining = k - (j-i+1);
                string add = string(remaining, fill);
                sub.append(add);
            }
            result.push_back(sub);
            i += k;
        }
        return result;
    }
};