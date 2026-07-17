/*

class Solution {
public:
    string makeGood(string s) {
        string good; // string behaving as a stack
        // Valid characters ko push karenge, bad pair mila to pop kar denge
        for(int i = 0; i < s.length(); i++){

            // agar good empty hai to directly push karo
            // kyunki empty string ke last element ko access karne se error(segmentation fault) aayega
            if(good.empty()){
                good.push_back(s[i]);
            }

            // Check if current element aur stack ka top char ek "bad pair" banate hain?
            // Bad pair ki condition
            // 1. Dono same case nahi hone chahiye
            // 2. dono alphabet same hone chahiye
            else if(s[i] != good.back() && tolower(s[i]) == tolower(good.back())){
                good.pop_back();
                // Bad pair mil gaya to purane character ko result se hata do
                // current character(s[i]) kko bhi push mat karo(dono cancel ho gaye)
            }

            // agar bad pair nahi hai to current char simply push kar do
            else{
                good.push_back(s[i]);
            }
        }

        // jo characters bach gaye, wshi good string hai
        return good;
    }
};

There is a mathematical trick to check opposite cases in ASCII.
The difference between a lowercase and uppercase letter in ASCII is exactly 32.

So:
'a' - 'A' = 32
'z' - 'Z' = 32

So the condition could also be:
abs(s[i] - good.back()) == 32 (absolute value )

TC -> O(n) | SC -> O(n)

We can try in-place 
Then the extra space used will be O(1)

*/

class Solution {
public:
    string makeGood(string s) {
        int write = 0; // current valid string ka size(length)
                       // aur next valid character kis index pe likhna hai
                       // so top of string = s[write - 1]
                       // push = s[write] = s[i]
                       // pop = write--
                       // no actual deletion needed
        int n = s.length();
        for(int i = 0; i < n; i++){ // i original string ko left to right read karega
            if(write == 0){ // means current valid string empty hai
                            // Is case me compare karne ke liye koi previous valid character hi nahi hai
                            // so current char ko directly place kar do
                s[write] = s[i];
                write++;
                // ab valid string ki length 1 badh gayi
            }
            else if(s[i] != s[write - 1] && tolower(s[i]) == tolower(s[write - 1])){ // if s[i] is forming a bad pair(Kiske saath?) sahi characters ke top element ke sath(write - 1) -> AND NOT i - 1 -> To wo element sahi tha hi nahi -> write--
            // current character ko last valid character se compare kar rahe hain
            // s[write - 1] current valid string ka last character hai
            // 1. Same character nahi hone chahiye(a and a, B and B)
            // 2. Same alphabet hone chahiye(abs(s[i] - s[write - 1] == 32) or tolower(s[i]) == tolower(s[write - 1]))
            // Same letter + opposite case

                write--;
                // Bad pair mil gaya 
                // Iska matlab previous valid character ko hata do
                // current character ko bhi write nahi karenge
                // dono effectivley remove ho gaye
            }
            else{
                // Agar bad pair nahi bana
                // to current character valid string ka part banega

                s[write] = s[i];
                write++;
                // Valid string me push kar diya
            }
        }
        s.resize(write);
        // Final valid answer sirf write characters me hai

        return s; // return s.resize(write) is invalid because resize() returns void, it changes the string but khud kuch nahi karta hai
    }
};


/*

TC -> O(n) | SC -> O(1)
Returning final string may create output copy, but auxiliary extra space used by algorithm is O(1).

*/