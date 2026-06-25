class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j){
            if(!isalnum(s[i])){
                i++;
                continue; // continue is needed because what if two back-to-back non-alphanumeric characters come
            }             // this way, jab tak kisi bhi taraf non-alphanumeric characters aate rahenge, tab tab while loop skip hoga, aur phir agle character ke liye check karega
            if(!isalnum(s[j])){
                j--;
                continue; // similary, from the right side, jab tak non-alphanumeric characters hat nahi jaate, tab tak hatata rahega !isalnum()
            }
            if(tolower(s[i]) != tolower(s[j])){
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
};

/*

= isalnum() se pata chala ki alpha numeric character hai ya nahi(0~9, a~z, A~Z)
= tolower() se ek character lower case me aata hai
= dono #include <cctype> library me hote hain
~ tolower() is giving an int as an output, that's why for adding it in an empty string, it has to be casted explicitly

> This is called the "skip and continue" pattern in two-pointer problems
> Used in two-pointer problems where you need to skip certain elements 
? You'll use it for:

. Skipping spaces in strings
. Skipping zeros in arrays
. Skipping duplicates in sorted arrays
. Many other two-pointer problems

// PATTERN:
//   while(i < j){
//       if(condition to skip i){
//           i++;
//           continue;   // ! CRITICAL - jumps back to while check
//       }
//       if(condition to skip j){
//           j--;
//           continue;
//       }
         / Both i and j are valid here
         / Do comparison/work
//       i++;
//       j--;
//   }

? Why is 'continue' critical?
* It handles MULTIPLE consecutive elements that need skipping
* Without continue, only ONE skip per iteration
* With continue, can skip many in a row

*/
