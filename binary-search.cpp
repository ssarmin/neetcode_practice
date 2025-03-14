//https://neetcode.io/problems/binary-search
class Solution {
public:
    int bst(vector<int>& nums, int target, int start, int end){
        if(start > end){
            return -1;
        }else if(start == end){
            if(nums[start] == target){
                return start;
            }
                return -1;
        }else{
            int mid = start + (end - start)/2;
            if(target == nums[mid])
                return mid;
            else if(nums[mid] > target){
                return bst(nums, target, start, mid-1);
            }
                return bst(nums, target, mid+1, end);
        }
    }
    int search(vector<int>& nums, int target) {
        return bst(nums, target, 0, nums.size()-1);
    }
};
