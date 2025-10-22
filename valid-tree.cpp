//https://neetcode.io/problems/valid-tree
class Solution {
public:
    vector<int> parent;
    void init(int n){
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    int find(int i){
        if(i == parent[i])
            return i;
        return find(parent[i]);
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n > (edges.size()+1))
            return false;
        init(n);
        for(auto e: edges){
            int p1 = find(e[0]);
            int p2 = find(e[1]);
            if(p1 == p2)
                return false;
            parent[p1] = p2;
        }
        unordered_set<int> visit;
        return true;
    }
// };
// 4
// [[0,1],[0,2]]
