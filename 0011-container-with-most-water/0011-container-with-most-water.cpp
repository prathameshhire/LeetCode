class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxVol = 0;
        int l = 0;
        int r = height.size()-1;
        while (l<r) {
            int vol = (r-l) * min(height[l], height[r]);
            maxVol = max(maxVol, vol);
            if (height[l]>height[r]) r--;
            else l++;
        }
        return maxVol;
    }
};