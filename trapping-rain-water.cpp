//https://neetcode.io/problems/trapping-rain-water
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> preLeft(height.size(), -1);
        vector<int> preRight(height.size(), -1);
        for(unsigned int i=1; i<height.size(); i++){
            preLeft[i] = max(preLeft[i-1], height[i-1]);
        }

        for(int i=height.size()-2; i>=0; i--){
            preRight[i] = max(preRight[i+1], height[i+1]);
        }

        int count = 0;
        for(unsigned int i=0; i<height.size(); i++){
            count += max(min(preLeft[i], preRight[i]) - height[i], 0);
        }

        return count;
    }
};
