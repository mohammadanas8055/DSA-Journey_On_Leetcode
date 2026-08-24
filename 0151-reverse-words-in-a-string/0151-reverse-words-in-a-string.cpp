/*

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        // Ye vector saare individual words store karega
        // Each element ek complete word hoga(no spaces inside)

        // Vector isliye use kiya (stack ki bajaye) kyunki:
        // - Reverse order me iterate karna easy hai (index se)
        // - Words ka natural order preserve hota hai
        // - Stack me character-level thinking ho jaati, jo complicated tha
        
        string currentWord;
        // Temporary storage - ek word ko character by character build karne ke liye 
        // Empty se start kiya, har naye word ke liye reset hoga

        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                currentWord.push_back(s[i]);
                // Non-space character mila -> ye current word ka part hai
                // Isko currentWord ke end me append kiya
            }
            else{
                // Space mila -> POSSIBLY ek word complete ho gaya(ho sakta hai word na bhi ho) 

                if(!currentWord.empty()){
                    // Ye check zaroori hai kyunki:
                    // - Leading spaces me currentWord empty hoga
                    // - Multiple consecutive spaces me bhi empty hoga
                    // - Empty word ko vector me push karne ka koi matlab nahi 

                    words.push_back(currentWord);
                    // Complete word ko vector me save kiya
                    
                    currentWord.clear();
                    // currentWord ko reset karna zaroori hai
                    // Warna agla word purane ke saath merge ho jayega 
                }
                // Agar currentWord empty tha(leading/multiple spaces case), to kuch nahi karna hai
                // Bas space ko ignore kar do 
            }
        }

        // Loop ke bahar bhi ek edge case handle karna hai:
        // Agar string space se end NAHI hoti, to last word abhi bhi currentWord me pada hai
        
        // Example: "hello world" me 'd' ke baad space nahi hai
        // Loop end pe currentWord = "world" hai, but push nahi hua
        if(!currentWord.empty()){
            words.push_back(currentWord);
        }

        string ans;
        // Final result string build karne ke liye

        for(int j = words.size() - 1; j >= 0; j--){
            // Words ko REVERS order me traverse kar rahe hain
            // Last word pehle, first word last me - yahi word reversal ka core hai

            for(int k = 0; k < words[j].length(); k++){
                ans.push_back(words[j][k]);
                // Current word ke saar echaracters ans me append kar rahe hain

                // NOTE: ye ans += words[j] ki manual version hai
                // C++ me dono kaam same karte hain
                // Nabual loop me explicit control milta hai
            }
            if(j != 0){
                ans.push_back(' ');
                // Word ke baad space add karo, LEKIN sirf tab jab
                // ye last word(in reversed order) na ho
                
                // Kyunki last word ke baad trailing space nahi chahiye
                // j = 0 wala word actually output ka last word hoga

                // Example: words = ["the", "sky", "is", "blue"]
                // Reverse iterate: blue, is, sky, the
                // "blue " + "is " + "sky " + "the" (no trailing space)
            }
        }
        return ans;
        // Final reversed-word string return kar diya
    }
};

*/

/*

Simpler approach
Step 1: Har word ko identify karke ek list me daalo
        Traverse the string. Jab non-space character mile, uska word banao. Jab space mile, ya string khatam ho, us word ko list me push kar do

Step 2: Words ko reverse order me join karo

TC -> O(n) 
      First loop(Parse words): Har charater sirf ek baar visit ho raha hai - O(n)
      Second nested loop(build result): Total characters writtenm = original non-space characters + spaces between words <= n - O(n)
      Total: O(n)    
SC -> O(n)
      words vector: Worst case n/2 words
      currentWord string: Worst case ek word pura string ho - O(n)
      ans result string: O(n)
      Total: O(n)

There is an in-place approach
reverse string
reverse individual words
Extra spaces clean up

Just like LC 189 Rotate Array optimal solution

*/

class Solution{
public: 
    string reverseWords(string s){
        int n = s.length();

        // STEP 1: Extra spaces clean karo(In-place two-pointer method)

        // Goal: Leading spaces, trailing spaces, aur consecutive multiple spaces ko single space me convert karna, taaki string formatted ho jaye

        int write = 0;
        // write pointer batayega ki current cleaned valid string ki length kitni hai
        // aur agla valid character s[0...write-1] me kahan overwrite hoga

        for(int read = 0; read < n; read++){
            if(s[read] != ' '){
                // Agar current character space nahi hai, matlab ek word ka part hai

                if(write > 0 && s[read - 1] == ' '){
                    // Critical Condition:
                    // 1. write > 0 ensures karta hai ki ye pehla word nahi hai
                    //    (pehle word ke aage spaces nahi chahiye, leading spaces ignore karne ke liye)
                    // 2. s[read - 1] == ' ' check karta hai ki kya piche ek space tha
                    //    jiske baad ab naya word shuru ho raha hai
                    
                    // Agar dono true hain, to do words ke beech me exatamente(exactly) EK space insert karo

                    s[write] = ' ';
                    write++;
                }
                s[write] = s[read];
                write++;
                // Non-space character ko in-place overwrite kar do
                // Read pointer aage scan kar raha hai, write pointer output space organize kar raha hai
            }
            // Agar s[read] == ' ' hai, to use simply skip kar do (read++ loop se ho jayega)
            // Isse multiple consecutive spaces automatic clean ho jaate hain
        }
        s.resize(write);
        // String ko write length par shrink kar diya
        // Step 1 ke baad:
        // - Leading spaces khatam
        // - Trailing spaces khatam
        // - words ke beech me exactemente 1 space
        // Example: "  the  sky  is  blue  " -> "the sky is blue"

        n = s.length();
        // Updated cleaned length store kar li agle steps ke liye

        // STEP 2: Puri cleaned string ko reverse karo

        reverse(s.begin(), s.end());
        // Standard STL reverse in-place reverse karta hai O(n) me

        // Is step ka result:
        // Words ka ORDER reverse ho gaya(jo word aakhri me tha wo pehle aa gaya)
        // LEKIN har individual word ke characters bhi ulte ho gaye
        // Example: "the sky is blue" -> "eulb si yks eht"

        // STEP 3: har individual word ko Un-Reverse (Fix) karo

        // Ab hame "eulb" ko wapas "blue", "si" ko "is" banana hai

        int start = 0;
        // current word ke starting index track karega

        for(int end = 0; end <= n; end++){
            // end <= n (not < n) isliye kyunki aakhri word ke baad
            // Space nahi hota, balki string ka END(n) hota hai

            if(end == n || s[end] == ' '){
                // Ek word do cases me khatam hota hai:
                // 1. s[end] == ' ' (Word ke baad space mil gaya)
                // 2. end == n (String khatam ho gayi, last word complete)

                reverse(s.begin() + start, s.begin() + end);
                // Substring [start .... end - 1] ko in-place reverse kar do

                // Why s.begin() + end(exclusive upper bound)?
                // C++ STL(first, last) me 'last' iterator exclusive hota hai
                // Isliye s.begin() + end pass karne par index 'end - 1' tak hi reverse hota hai
                // jo ki space se pehle wala character hai

                start = end + 1;
                // agle word ka start point space ke just baad wala index hoga
            }
        }
        return s;
        // Cleaned, fully reversed words string return kar di
    }
};

/*

Step 1: Extra spaces clean karo(In-place)
read and write pointers ka use karke leading, trailing aur duplicate spaces hata do
Same as LC 283 Move Zeroes and LC 1047 Remove Duplicates 
Agar naya word start ho raha hai (aur ye pehla word nahi hai), to ek space add karo
Trimmed via resize

Step 2: Puri string ko reverse kar do
Words ka order reverse ho gaya(blue pehle, the aakhri me)
par har word ke characters bhi ulte ho gaye

Step 3: har word ko individually reverse karo(To fix characters)
Word tab khatam hota hai jab space mile YA strin end ho jaye

TC -> O(n) 
      Step 1: spaces -> O(n)
      Step 2: reverse all -> O(n)
      Step 3: reverse words -> O(n)
      Total = 3n = O(n)
SC -> O(1) Auxiliary space

*/