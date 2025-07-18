//https://neetcode.io/problems/count-connected-components
class Solution {
public:
    void traverse(int node, vector<vector<int>> v, vector<bool> &visited){
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            node = q.front();
            vector<int> temp = v[node];
            q.pop();
            if(visited[node])continue;
            visited[node] = true;
            for(int i=0; i<temp.size(); i++){
                if(!visited[temp[i]]){
                    q.push(temp[i]);
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n, vector<int>{});
        
        for(auto e: edges){
            v[e[0]].push_back(e[1]);
            v[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i] && v[i].size() == 0){
                count++;
            } else if(!visited[i] && v[i].size() > 0){
                traverse(i, v, visited);
                count++;
            }
        }
        return count;
    }
};


// Time complexity: O(V+E)
// Space complexity: O(V+E)

// V = number of nodes
// E = number of edges
// 7
// [[0, 1], [6, 0], [2, 4], [2, 3], [3, 4]]
