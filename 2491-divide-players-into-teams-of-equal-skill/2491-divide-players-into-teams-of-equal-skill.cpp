class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int i=0;
        int j=skill.size()-1;
        sort (skill.begin(), skill.end());

        long long chem = 0;
        int maxVal=skill[i]+skill[j];
        while (i<j) {
            int currentVal = skill[i] + skill[j];
            if (currentVal!=maxVal) {
                return -1;
            }
            chem += skill[i]*skill[j];
            i++;
            j--;        
        }
        return chem;   
    }
};