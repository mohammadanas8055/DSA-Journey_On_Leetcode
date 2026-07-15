// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         if(haystack.find(needle) != string::npos){
//             return haystack.find(needle);
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();

        if(n > m){
            return -1;
        }

        for(int i = 0; i <= m - n; i++){
            int j = 0;
            
            while(j < n){
                if(haystack[i + j] != needle[j]){
                    break;
                }
                j++;
            }
            if(j == n){
                return i;
            }
        }
        return -1;
    }
};