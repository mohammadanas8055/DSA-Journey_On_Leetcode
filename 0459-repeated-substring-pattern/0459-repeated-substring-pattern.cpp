class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        // Candidate substring ki length 1 se n/2 tak ho sakti hai
        // Kyunki poori string khud repeated substring nahi ho sakti
        for(int i = 0; i < n / 2; i++){
            int len = i + 1;

            // Agar string length, len se diivde nahi ho rahi
            // to is length ka pattern possible hi nahi hai
            if(n % len != 0){
                continue; // to agle length ka substring se pattern dhoondhne ki koshish karenge
            }

            bool match = true; // Pehle assume kar lo ki len work karta hai, agar kahin mismatch mila, then match = false
            
            // first block ko base maan kar
            // baaki characters check karenge
            for(int j = len; j < n; j++){ // pehle len charcaters base pattern hain -> Ab baaqi string ko usi pattern ke according check karna hai
                // current character ko uske corresponding base pattern character se compare karo
                if(s[j] != s[j % len]){ // if len = 3 -> compare s[3] with s[0], s[4] with s[1], s[5] with s[2] and then again s[6] with s[0]  
                // So '% len' wraps index back into the first block
                    match = false;
                    break;
                }
            }

            // Agar puri string pattern follow kar rahi hai, to match true hi raha(matlab string repeated pattern se bani hai)
            if(match == true){
                return true;
            }
        }

        // if no length works
        return false;
    }
};

/// “Kya string equal-sized blocks me divide ho sakti hai, aur kya saare blocks same hain?”

/// Agar string length n hai, to repeated piece ki length:

// n nahi ho sakti
// because then repeat kitni baar hua? only once
// So candidate lengths only:

// 1 se n/2 tak

/// sab lengths try karni hain?
// Nahi.

// Agar piece ki length len hai, to poori string usse exact divide honi chahiye.

// So:
// n % len == 0 hona chahiye

// TC -> O(n^2) | SC -> O(1)

/*

String Concatenation Trick
Agar koi string apne aap ko repeat karke bani hai, to agar tum us string ko usi ke saath jod do (concatenate), aur starting & ending characters hata do, to bhi original string uske andar chhipi hui mil jayegi.

s ko khud ke saath add karo: string doubled = s + s;
Nayi string ka first aur last character hata do.
Ab is bachi hui string mein check karo ki kya original s mil rahi hai ya nahi.
Agar mil gayi -> true
Nahi mili -> false

Why does this work? (The Math/Logic)
Maan lo s do blocks se bani hai: s = A + A.
Jab tum s + s karte ho, to wo ban jata hai: A + A + A + A.

Jab tumne first aur last char hataya, to tumne actually first aur last A block ko tod diya/kharab kar diya.
Lekin beech ke do A blocks abhi bhi safe hain! (A_broken + A + A + A_broken).
Aur A + A hi to tumhara original s tha!

Lekin agar string repeating blocks se nahi bani, to ye middle overlapping kabhi original string nahi bana payegi.

class Solution{
public:
    bool repeatedSubstringPattern(string s){

        // s ko s ke sath jodo
        string doubled = s + s;

        // first aur last character hata kar substring nikalo
        // substr(position, length)
        string modified = doubled.substr(1, doubled.length() - 2);

        // check karo agar original 's' modified string mein hai ya nahi
        if(modified.find(s) != string::npos){
            return true;
        }
        return false;
    }
};

TC -> O(n) | SC -> (n)

*/
