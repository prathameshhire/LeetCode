class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        int ans = -1;
        while(j<haystack.length()) {
            if(j-i+1 == needle.length()) {
                string sub = haystack.substr(i, j-i+1);
                if(sub == needle) {
                    ans = i;
                    break;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};