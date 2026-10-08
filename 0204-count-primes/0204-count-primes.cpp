// class Solution {
// public:
//     bool isPrime(int n){
//         for(int i = 2; i * i <= n; i++){
//             if(n % i == 0){
//                 return false;
//             }
//         }
//         return true;
//     }
//     int countPrimes(int n) {
//         if(n == 0 || n == 1 || n == 2){
//             return 0;
//         }
//         int count = 0;
//         for(int i = 2; i < n; i++){
//             if(i == 2 || i == 3){
//                 count++;
//             }
//             else if(isPrime(i)){
//                 count++;
//             }
//         }
//         return count;
//     }
// };

class Solution{
public: 
    int countPrimes(int n){
        if(n == 0 || n == 1 || n == 2) return 0;
        vector<bool> seen(n, true);
        seen[0] = false;
        seen[1] = false;
        for(int i = 2; i * i <= n; i++){
            if(seen[i] == true){
                for(int j = i * i; j < n; j = j + i){
                    seen[j] = false;
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(seen[i] == true){
                count++;
            }
        }
        return count;
    }
};