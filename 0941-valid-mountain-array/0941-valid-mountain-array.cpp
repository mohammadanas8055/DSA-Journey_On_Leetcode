class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3){
            return 0;
        }
        int i = 0;
        if(arr[0] > arr[1]){
            return 0;
        }
        for(int j = 0; j < arr.size() - 1; j++){
            if(arr[j] < arr[j + 1]){
                i++;
            }
        }
        if(i == arr.size() - 1){
            return 0;
        }
        for(int k = i; k < arr.size() - 1; k++){
            if(arr[k + 1] >= arr[k]){
                return 0;
            }
        }
        return 1;
    }
};