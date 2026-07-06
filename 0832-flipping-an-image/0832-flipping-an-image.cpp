class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i = 0; i < image.size(); i++){
            int left = 0; 
            int right = image[i].size() - 1;
            while(left <= right){
                int temp = 1 - image[i][left];
                image[i][left] = 1 - image[i][right];
                image[i][right] = temp;
                left++;
                right--;
            }
            // invert and flip at the same time(left <= right is needed so that the middle element also gets inverted) OR
            // for(int j = 0; j < image[i].size(); j++){
            //     image[i][j] = 1 - image[i][j];
            // }
        }
        return image;
    }
};

/*

TC -> O(n^2) or O(rows*cols) | SC -> O(1)

. Pattern used:
2D vector traversal + row-wise two pointer + bit inversion

*/