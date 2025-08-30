//https://neetcode.io/problems/concatenation-of-array
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        nums.insert(nums.end(), nums.begin(), nums.end());
        return nums;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
