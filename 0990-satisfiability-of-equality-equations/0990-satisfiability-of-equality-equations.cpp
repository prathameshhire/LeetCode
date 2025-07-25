class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find (int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent) return;
        if (x_parent > y_parent) parent[y_parent] = x_parent;
        else if (y_parent > x_parent) parent[x_parent] = y_parent;
        else {parent[x_parent] = y_parent;  rank[y_parent]++;}
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);
        for (int i = 0; i<26; i++) {
            parent[i] = i;
        }
        for (string &s : equations) {
            if (s[1] == '=') {
                Union(s[0]-'a', s[3]-'a');
            }
        }
        for (string &s : equations) {
            if (s[1] == '!') {
                int parent_a = find(s[0] - 'a');
                int parent_b = find(s[3] - 'a');
                if (parent_a == parent_b) return false;
            }
        }
        return true;
    }
};