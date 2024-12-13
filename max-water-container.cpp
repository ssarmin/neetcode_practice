//https://neetcode.io/problems/max-water-container
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0;
        int left = 0;
        int right = heights.size()-1;

        while(left < right){
            int area = (right - left) * min(heights[left], heights[right]);
            max_area = max(max_area, area);
            if(heights[left] < heights[right]){
                left++;
            }else{
                right--;
            }
        }

        return max_area;
    }
};
