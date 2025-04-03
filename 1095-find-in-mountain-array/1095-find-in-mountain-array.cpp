/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length = mountainArr.length();

        int l = 1, r = length - 2;
        int peak = 0;
        while (l<=r) {
            int m = (l+r) / 2;
            int left = mountainArr.get(m-1);
            int middle = mountainArr.get(m);
            int right = mountainArr.get(m+1);
            if (left < middle && middle < right) {
                l = m+1;
            }
            else if (left > middle && middle > right) {
                r = m-1;
            }
            else {
                peak = m;
                break;
            }    
        }
        l = 0;
        r = peak;
        while (l<=r) {
            int m = (l+r)/2;
            int middle = mountainArr.get(m);
            if (middle > target) r = m-1;
            else if (middle < target) l = m+1;
            else return m;
        }

        l = peak + 1; //assign l = peak if error
        r = length-1;

        while (l<=r) {
            int m = (l+r)/2;
            int middle = mountainArr.get(m);
            if (middle > target) l = m+1;
            else if (middle < target) r = m-1;
            else return m;
        }

        return -1;
    }
};