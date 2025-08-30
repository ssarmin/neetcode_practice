//https://neetcode.io/problems/contains-duplicate-ii
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        int i = 0;
        for(; i < nums.size() && i <= k; i++){
            if(s.count(nums[i]))
                return true;
            s.insert(nums[i]);
        }
        for(; i<nums.size(); i++){
            s.erase(nums[i - k - 1]);
            if(s.count(nums[i]))
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
