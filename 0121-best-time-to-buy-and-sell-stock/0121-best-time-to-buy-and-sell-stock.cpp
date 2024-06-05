class Solution {
public:
    int maxProfit(vector<int>& v) {
        int maxPro = 0;
        int minPrice = 1e4+1;
        for(int i = 0; i < v.size(); i++){
            minPrice = min(minPrice, v[i]);
            maxPro = max(maxPro, v[i] - minPrice);
        }
        return maxPro;
    }
};