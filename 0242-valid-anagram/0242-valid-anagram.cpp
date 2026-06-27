class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return 0;
        }
        int count[26] ={0};
        for(int i = 0; i < s.length(); i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(count[i] != 0){
                return 0; /// some letters count isn't zero -> not anagram
            }
        }
        return 1; /// all counts are zero
    }
};

/*

~ Two strings are anagrams if they contain the SAME LETTERS, just in DIFFERENT order.

* Par sorting me time complexity O(nlogn) lag rahi hai aur space complexity O(1) hai

# Second Approach
> Count Character Frequence: Count how many times each letter appears, if counts match, then anagrams
. Time complexity now -> O(n) and Space complexity -> O(1) -> Only 26 int array
//= This technique is right now according to leetcode questions where two words were given, that too in lowercase.
//- Agar string clean karni hoti to wo bhi kar lete isi function me

- pehle count naam ka array bana liya jisme 26 dabbe the, for each alphabet, aur initialise kar diya har dabbe me 0 ko
- count[0] -> 'a' box, count[1] -> 'b' box and so on
- uske baad kisi bhi ek length tak loop chal aliya, kyunki different length to cancel hi ho jaa rahi hain
- ek string se letters ke count ko badhaya
- dusre string se same letters ki count ko ghataya
- agar har dabbe ki count zero hai, yani har letter jitni baar badhaya gaya, utni hi baar ghataya gaya
- yani same count of all alphabets -> anagrams

// count badhayi/ghatayi kaise
/ count[s1[i] - 'a']++; -> jo bhi character hoga us position pe, use 'a' ke ASCII se minus kar denge, 0 to 25 me fit karna ke liye
/ 'a' - 'a' -> 0 -> count[0] me ek badha do(s1 se) 
/ count[s2[i] - 'a']--;
/ 'b' - 'a' -> 1 -> count[1] me ek ghata do(s2 se)
* if everything that went up came back down -> anagram

# This pattern (frequency array) is used in MANY DSA problems:

~ Anagram check ✅
~ First non-repeating character
~ Find duplicates
~ Character permutations
~ Word patterns

*/
