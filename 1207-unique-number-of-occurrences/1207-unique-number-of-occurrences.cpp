class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector <int> v;
        unordered_map <int,int> m;
        for (int i=0; i<arr.size(); i++){ // try auto next time
            int k = arr[i];
            m[k]++;
        }
        for (auto it=m.begin(); it!=m.end(); it++){
            int k = (it -> second);
            v.push_back(k);
        }
        /*sort (v.begin(), v.end());
        for (int i=0; i<v.size(); i++) {
            for (int j=i+1; j<v.size(); j++){
                if (v[i]==v[j]){
                    return false;
                    //break;
                }
                else {
                    return true;
                }
            }
        }*/
        sort (v.begin(), v.end());
        for (int i = 0; i < v.size() - 1; i++){
            if (v[i] == v [i+1])
                return false;
        }
        return true;
        //return {};
    }
};