//https://neetcode.io/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        for(int i=1; i<nums.size(); i++){
            if(i >= 2)
                nums[i] = max(nums[i] + nums[i-2], nums[i-1]);
            else
            nums[i] = max(nums[i], nums[i-1]);
        }
        return max(nums[nums.size()-1], nums[nums.size()-2]);
    }
};

// Extra testcases:
// nums=[1,1,30,3,8,5,48,96,59]
// nums=[1,1,30,3,8,5,48,96,59,3,4,2,4,5,2,3,4]
// nums=[5,1,2,10,6,2,7,9,3,1]
