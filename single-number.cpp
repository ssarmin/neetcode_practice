//https://neetcode.io/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val = nums[0];
        for(int i=1; i<nums.size(); i++){
            val = val^nums[i];
        }
        return val;
    }
};
