class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 0;
        int n = arr.size();

        while(i + 1 < n && arr[i + 1] > arr[i]){
            i++;
        }
        // i is the peak now
        // But kya valid peak hai?
        
        if(i == 0 || i == n - 1){
            return false; // Peak cannot be first or last element
        }
        

        while(i + 1 < n && arr[i + 1] < arr[i]){
            i++;
        }
        return i == n - 1;
    }
};