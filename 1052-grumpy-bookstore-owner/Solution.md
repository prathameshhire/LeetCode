# C++ 2 pass solution using sliding window in O(n) time and O(1) space beats 100% 

# Code
```cpp []
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int i = 0, j = 0, n = grumpy.size(), result = 0, answer = 0;
        for(int k = 0; k<n; k++) {
            if(!grumpy[k]) result += customers[k];
        }
        while (j<n) {
            (grumpy[j] == 1) ? result += customers[j] : result += 0;
            answer = max(answer, result);
            if(j-i+1 == minutes) {
                if(grumpy[i]) result -= customers[i];
                i++; 
            }
            j++;
        }
        return answer;
    }
};
```