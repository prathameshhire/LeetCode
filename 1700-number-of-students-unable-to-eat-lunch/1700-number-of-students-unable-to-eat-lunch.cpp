class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        vector<int> vec(2,0);
        for(auto &student : students) vec[student]++;
        for(int i = 0; i<n; i++) {
            int sandwich = sandwiches[i];
            if(vec[sandwich] == 0) return n-i;
            vec[sandwich]--;
        }
        return 0;
    }
};