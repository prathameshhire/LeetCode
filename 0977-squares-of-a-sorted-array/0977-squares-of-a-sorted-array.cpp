class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>square;
        for (auto a:nums){
            int b = a*a;
            square.push_back(b);
        }
        sort(square.begin(),square.end());
        return square;
    }
};