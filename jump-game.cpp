//https://neetcode.io/problems/jump-game
class Solution {
public:
    bool canJump(vector<int>& nums){
        if(nums[0] == 0 && nums.size()>1)
            return false;
        vector<bool> visit(nums.size(), false);
        visit[0] = true;
        for(int index=0; index<nums.size(); index++){
            if(visit[index]){
                for(int i=1; i<=nums[index] && index+i < nums.size(); i++){
                    visit[index+i] = true;
                }
            }
            if(visit[nums.size()-1])
                return true;
        }

        return visit[nums.size()-1];
    }
};
