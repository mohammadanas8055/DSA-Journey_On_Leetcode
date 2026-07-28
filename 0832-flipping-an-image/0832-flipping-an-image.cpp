class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i = 0; i < image.size(); i++){
            // Har row ke liye operation kar rahe hain

            int left = 0; 
            int right = image[i].size() - 1;
            // Row ke leftmost aur rightmost column index

            while(left <= right){
                // <= isliye use kiya hai
                // taaki odd-length row me middle element bhi process ho(invert karne ke liye)

                int temp = 1 - image[i][left];
                // Left element ko invert kark temporarily store kiya

                image[i][left] = 1 - image[i][right];
                // Right element ko invert karke left me daal diya

                image[i][right] = temp;
                // Original left ka inverted value right me daal diya

                left++;
                right--;
                // Dono pointers ko center ki taraf move kar diya
            }
        }
        return image;
    }
};

/*

TC -> O(n^2) or O(rows * cols) | SC -> O(1)

. Pattern used:
2D vector traversal + row-wise two pointer + bit inversion

*/