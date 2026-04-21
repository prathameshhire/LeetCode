class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
        int j = 0;
        for(int i = 1; i<=n; i++) {
            if(j < target.size() && target[j] == i) {
                operations.push_back("Push");
                j++;
                if(j == target.size()) break;
            }
            else {
                operations.push_back("Push");
                operations.push_back("Pop");
            }
        }
        return operations;
    }
};