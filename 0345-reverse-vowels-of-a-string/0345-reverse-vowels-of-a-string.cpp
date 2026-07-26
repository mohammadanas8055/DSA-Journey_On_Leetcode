class Solution {
public:
    // Helper function to cleanly check if a character is a vowel
    bool isVowel(char ch){
        // tolower handles both uppercase and lowercase vowels
        if(tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' || tolower(ch) == 'o'|| tolower(ch) == 'u'){
            return true;
            // Agar character vowel hai to true return hoga 
            // warna false
        }
        return false;
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;

        while(i < j){
            // jab tak pointers cross nahi karte
            // tab tak koi vowel na mil jaye

            while(i < j && !isVowel(s[i])){
                i++;
                // Move left pointer until a vowel is found
                // i < j ensures pointer doesn't go out-of-bounds or cross j
            }
            
            while(i < j && !isVowel(s[j])){
                j--;
                // Move right pointer until a vowel is found
                // i < j ensures pointer doesn't go out of bounds or cross i
            }

            // If both stopped at valid vowels and haven't crossed
            if(i < j){ //  Let's say s = "xyz"
                       // i = 0; j = 2
                       // Then first while loop se i = 2; j = 2
                       // Dusra while loop chalega hi nahi
                       // Ab agar if condition nahi hoti, to swap hote s[2] aur s[2] aur i = 3; j = 1
                       // Ye karne se string kharab nahi ho rahi, par waste of power hai ek extra swap aur i++ aur j-- karke
                       // So i < j -> Taaki swap sirf aur sirf tab hi ho jab dono taraf laag-alag vowels khade hon
                       // Ensures that same position pe na hon pointers
                swap(s[i], s[j]);
                // Dono vowels ko swap kar diya
                // Isse vowels ka order reverse hona start ho jata hai
                i++;
                j--;
                // Swap ke baad dono pointewrs ko andar ki taraf move kar do
                // kyunki current vowel pair ka kaam ho chuka hai
            }
        }
        return s;
        // Modified string return kar di
    }
};

/*

Main problem is: 
vowels ko reverse karo
So directly ye hi decide karna hai current character vowel hai ya nahi

So, 
Step 1: left pointer ko tab tak move karo jab tak vowel na mil jaye
Step 2: right pointer ko tab tak move karo jab tak vowel na mil jaye
Step 3: Agar dono vowels mil gaye aur i < j, then swap
Step 4: Swap ke baad pointers move

Therefore "if" nahi, while skip loops use karo(with the help of helper function)

Also same iteration me pointers multiple times mpove honge to check karna padega(ki i < j hai bhi ya nahi, nahi to agar vowel mila hi nahi, to infinite loop ban jayega)

TC -> O(n) | SC -> O(1)

*/