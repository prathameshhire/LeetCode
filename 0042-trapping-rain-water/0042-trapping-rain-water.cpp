class Solution {
public:
    int trap(vector<int>& height) {
        int lmax = 0, rmax = height.size()-1;
        int l = 0;
        int vol = 0;
        int r = height.size()-1;
        while (l<r) {
            if (height[l] < height[r]) {
                if (height[lmax] > height[l]) vol += height[lmax] - height[l];
                else lmax = l;
                l++;
            }
            else {
                if (height[rmax] > height[r]) vol += height[rmax] - height[r];
                else rmax = r;
                r--;
            }
        }
        return vol;
    }
};