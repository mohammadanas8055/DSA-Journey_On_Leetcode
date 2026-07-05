class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        for(int i = 0; i < arr.size() - 1; i++){
            int maximum = arr[i + 1];
            for(int j = i + 1; j < arr.size(); j++){
                if(arr[j] > maximum){
                    maximum = arr[j];
                }
            }
            arr[i] = maximum;
        }
        arr[arr.size() - 1] = -1;
        return arr;
    }
};