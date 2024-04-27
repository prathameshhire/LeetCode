class Solution {
private:
    float median (vector<int> v){
        int k=0;
        int j=v.size()-1; // try v.end later
        while (k<j){
            j--;
            k++;
        }
        float a=v[k];
        float b=v[j];
        //float i = ((a+b)/2);
        return (a+b)/2; 
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end()); // try temp vect to store both if not working
        sort(nums1.begin(), nums1.end());
        return median (nums1);
    }
};