//https://neetcode.io/problems/maximum-subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxVal = nums[0];
        for(int i=1; i<nums.size(); i++){
            nums[i] = max(nums[i], nums[i]+nums[i-1]);
            maxVal = max(maxVal, nums[i]);
        }

        return maxVal;
    }
};
