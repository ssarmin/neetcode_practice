//https://neetcode.io/problems/k-closest-points-to-origin
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        for(int i=0; i<points.size(); i++){
            double dist = sqrt((points[i][0]*points[i][0]) + (points[i][1]*points[i][1]));
            pq.push({dist, i});
        }

        while(res.size() < k){
            int index = pq.top().second;
            pq.pop();
            res.push_back({points[index][0], points[index][1]});
        }
        return res;
    }
};
