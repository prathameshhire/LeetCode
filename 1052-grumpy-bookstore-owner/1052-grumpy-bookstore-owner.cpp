class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int i = 0, j = 0, n = grumpy.size(), unsatisfied = 0, answer = 0, maxUnsatisfied = 0;
        while (j<n) {
            if(grumpy[j]) unsatisfied += customers[j];            
            else answer += customers[j];
            maxUnsatisfied = max(maxUnsatisfied, unsatisfied);
            if(j-i+1 == minutes) {
                if(grumpy[i]) unsatisfied -= customers[i];
                i++;
            }
            j++;
        }
        return answer + maxUnsatisfied;
    }
};