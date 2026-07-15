class Solution{
public:
    bool repeatedSubstringPattern(string s){

        // s ko s ke sath jodo
        string doubled = s + s;

        // first aur last character hata kar substring nikalo
        // substr(position, length)
        string modified = doubled.substr(1, doubled.length() - 2);

        // check karo agar original 's' modified string mein hai ya nahi
        return modified.find(s) != string::npos;
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

class Solution(){
public:
    bool repeatedSubstringPattern(string s){

        // s ko s ke sath jodo
        string doubled = s + s;

        // first aur last character hata kar substring nikalo
        // substr(position, length)
        string modified = doubled.substr(1, doubled.length() - 2);

        // check karo agar original 's' modified string mein hai ya nahi
        return modified.find(s) != string::npos;
    }
};

*/
