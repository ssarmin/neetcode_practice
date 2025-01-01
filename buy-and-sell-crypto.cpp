//https://neetcode.io/problems/buy-and-sell-crypto
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total_profit = 0;
        int profit = INT_MIN;
        int buy = prices[0];
        for(int i=1; i<prices.size(); i++){
            if(buy > prices[i]){
                buy = prices[i];
            }else{
                profit = max(profit, prices[i] - buy);
            }
        }
        return max(profit, 0);
    }
};
//extra testcases:
// [7,1,5,3,6,4]
// [2,4,1]
// [2,1,2,0,1]
