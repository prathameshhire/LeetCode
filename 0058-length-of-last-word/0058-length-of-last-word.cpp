class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        int size = s.length()-1;
        while (size>=0 && s[size]==' ') {
            size--;
        }
        while (size>=0 && s[size]!=' '){
            size--;
            count++;
        }
        return count;
    }
};