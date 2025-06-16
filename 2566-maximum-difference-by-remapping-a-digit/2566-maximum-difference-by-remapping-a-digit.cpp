class Solution {
public:
    int minMaxDifference(int num) {
        string str1 = to_string(num);
        string str2 = str1;
        int index = str1.find_first_not_of('9');
        if (index != string::npos) {
            char ch = str1[index];
            replace(str1.begin(), str1.end(), ch, '9');
        }
        char ch = str2[0];
        replace(str2.begin(), str2.end(), ch, '0');
        return stoi(str1) - stoi(str2);
    }
};