//https://neetcode.io/problems/products-of-array-discluding-self
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);
        vector<int> res;

        for(int i=1; i<nums.size(); i++){
            left[i] = left[i-1]*nums[i-1];
        }

        for(int i=nums.size()-2; i>=0; i--){
            right[i] = right[i+1]*nums[i+1];
        }
        
        for(int i=0; i<nums.size(); i++){
            res.push_back(left[i]*right[i]);
        }

        return res;
    }
};

//extra testcases:
//[1,2,4,6,23,4,1,4,1,4,2,5,8,9,0,32,3,225,4,56]
