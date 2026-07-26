class Solution {
public:
    bool isVowel(char s){
        if(tolower(s) == 'a' || tolower(s) == 'e' || tolower(s) == 'i' || tolower(s) == 'o'|| tolower(s) == 'u'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j){
            while(i < j && !isVowel(s[i])){
                i++;
            }
            while(i < j && !isVowel(s[j])){
                j--;
            }
            if(i < j){
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
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



*/