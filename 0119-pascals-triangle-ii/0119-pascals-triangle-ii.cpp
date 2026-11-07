int nCr(int n, int r){
    long long result = 1;
    for(int i = 0; i < r; i++){
        result = result * (n - i);
        result = result / (i + 1);
    }
    return result;
}
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1);
        for(int i = 0; i <= rowIndex; i++){
            if(i == 0 || i == rowIndex){
                result[i] = 1;
            }
            else{
                result[i] = nCr(rowIndex, i);
            }
        }
        return result;
    }
};