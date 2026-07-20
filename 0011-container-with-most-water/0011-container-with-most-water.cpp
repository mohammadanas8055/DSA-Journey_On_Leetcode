class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int area = 0;
        int maxArea = 0;
        while(i < j){
            area = (j - i) * min(height[i], height[j]);
            maxArea = max(area, maxArea);
            if(height[j] > height[i]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxArea;
    }
};