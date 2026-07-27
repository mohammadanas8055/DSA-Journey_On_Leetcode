class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int j = arr.size() - 1;
        int maximumOnRight = -1;
        for(int i = arr.size() - 1; i >= 0; i--){
            int temp = arr[i];
            arr[i] = maximumOnRight;
            maximumOnRight = max(temp, maximumOnRight);
        }
        return arr;
    }
};