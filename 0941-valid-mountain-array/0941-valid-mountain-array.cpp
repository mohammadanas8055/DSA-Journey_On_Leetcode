class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3){
            return false;
        }
        if(arr[0] >= arr[1]){
            return false;
        }
        int i = 0;
        while(arr[i + 1] > arr[i]){
            i++;
        }
        // i is the peak now

        while(arr[i + 1] < arr[i]){
            i++;
            if(i == arr.size() - 1){
                return true;
            }
        }
        return false;
    }
};