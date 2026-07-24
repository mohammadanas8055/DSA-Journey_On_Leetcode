class Solution {
public:

    // Helper function isliye banaya taaki ham string me kisi bhi specific part(left to right tak) ko check kar saken
    // string& s use kiya hai taaki memory me string ki copy na bane
    bool isPalindrome(string& s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false; // beech me agar mismatch mila matlab palindrome nahi hai, kyunki ek character hata ke check kar rahe hain
                // ab agar match nahi karega to cetainly palindrome nahi hai
            }
            left++;
            right--;
        }
        return true; // pura check ho gaya, matlab palindrome hai
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while(i < j){ // normal palindrome check ki tarah start kiya
            if(s[i] != s[j]){ // AGAR MISMATCH MILA
                              // Hamare paas sirf EK chance hai character delete karne ka
                              // Ya to 'i' wala char faltu hai, ya 'j' wala
                              
                              // Option 1: 'i' ko skip karke baaki string(i + 1 se j) check karo
                              // Option 2: 'j' ko skip karke baaki string(i se j - 1) check karo
                              // Dono me se koi sa bhi TRUE de de, to matlab 1 deletion se kaam ho gaya
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
            }

            // First I wrote
            // if(s[i] != s[j] && isPalindrome(s, i + 1, j) || s[i] != s[j] && isPalindrome(s, i, j - 1)){
            //     return true;
            // }
            // if(s[i] != s[j]){ // ab agar aage bhi mismatch mil jaye to false hi hai
            //     return false;
            // }
            // So both conditions trigger only if s[i] != s[j], we can combine them 

            i++; // normally agar mismatch nahi hai to i ko aage badhao aur j ko ghatao
            j--;
        }
        return true;
        // agar loop bina kisi return ke khatam ho gaya
        // iska matlab string pehle se hi palindrome thi
        // bagair kisi deletion ke
    }
};

/*

Helper Function: wo function jo main solution function(validPalindrome) ki help karne ke liye aap khud banate ho
                 ek function ke andar dosra function define nahi kar sakte, isliye bahar rakha, tabhi wo run hua 

Pass by reference karenge string ko, nahi to uski copy banegi phir(Large strings ke case me copy avoid karna hai)

First mismatch rule: aisw problems me first mismatch par hi decision lena kaafi hota hai, har character delete karke dekkhne ki brute-force zarurat nahi hai

TC -> O(n) (Poori string maximum 2 baar scan hogi) | SC -> O(1)

*/