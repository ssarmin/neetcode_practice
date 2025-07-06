//https://neetcode.io/problems/min-cost-climbing-stairs
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()<2)
            return 0;
        for(int i=2; i<cost.size(); i++){
            cost[i] += min(cost[i-1], cost[i-2]);
        }

        return min(cost[cost.size()-1], cost[cost.size()-2]);
    }
};
// [1,2,1,2,1,1,1,3,4,4,2,5,6,3,5,7,3,15,67,4,54]
// [1]
// [1,2]
