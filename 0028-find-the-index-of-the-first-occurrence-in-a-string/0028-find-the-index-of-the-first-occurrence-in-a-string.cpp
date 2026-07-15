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

        // Agar needle badi hai to wo haystick me mil hi nahi sakti
        if(n > m){
            return -1;
        }

        // i = haystack me starting sliding position
        // ham m - n tak hi jayenge, kyunki uske baad needle haystack me fit nahi hogi
        for(int i = 0; i <= m - n; i++){
            int j = 0; // har baar needle ke shuru se hi compare karna hai na
            
            // Needle ke har character ko match karke dekho haystack ke characters se, starting from i
            while(j < n){
                if(haystack[i + j] != needle[j]){
                    break; // agar mismatch mil gaya, loop se bahar niklo
                }
                j++;
            }

            // agar j, n ke equal pahunch gaya, matlab saare character match ho gaye
            if(j == n){
                return i;
            }
        }
        return -1; // kahin match nahi mila
    }
};

/*

TC -> O(m * n) | SC -> O(1)

This is the standard brute force approach
Using KMP algorithm, it can be done faster

*/