class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Agar input vector empty hai(safety case), empty string bhej do(Yahan hai nahi, kyunki 1 <= strs.length <= 200)
        // if(strs.empty()) return "";

        // Outer loop: Pehli string ke ek-ek character par chalega
        // Hum pehli string (strs[0]) ko benchmark maan rahe hain
        for(int j = 0; j < strs[0].size(); j++){

            // Inner loop: Baaki saari strings (i = 1 to end) check karega
            for(int i = 1; i < strs.size(); i++){

                // DO CASES ME RUKNA HAI:
                // 1. Agar current word(str[i]) ki length benchmark se chhoti hai(j == size)
                // 2. Agar current word ka character mismatch
                // if(j == strs[i].size() || strs[i][j] != strs[0][j]){
                // strs[0].resize(j);
                // return s;
                // }

                // Ya to if me upar wali conditions likh ke return kar do, no else required
                // OR
                // valid characters ko continue karte jao, jaise hi koi bhi condition false -> else me jaake return
                if(j < strs[i].size() && strs[i][j] == strs[0][j]){
                    continue;
                }
                else{

                    // In-place Optimization:
                    // Hame pata hai ki index 'j' tak hi common tha
                    // To pehli string ko wahin tak resize kiya aur return kar diya
                    strs[0].resize(j);
                    return strs[0];
                }
            }
        }

        // Agar pure loops khatam ho gaye to bina mismatch ke
        // iska matlab pehli pehli string khud puri ki puri common prefix hai
        return strs[0];
    }
};

/*

How Would I Place A Pointer At Each Word...If There are 200 Words? -> Ans. We don't need 200 pointers
Instead we manage two things:
Which character index are we looking at?(j)
2. Which word are we comparing it against(i)

So let's look the firsrt word, and assume it might be the common prefix
Ab uske ek ek character ko check karo, dusre words ke first character se(loop from 1 to strs.size() - 1)
Agar aage ka koi word chhota na ho(iske liye j < strs[i].size() hoga, na ki empty check -> MORE ON THIS BELOW), aur phir match bhi kar gaya, to next character pe shift
agar first word khatam ho gaya, iska matlab wahi maximum common prefix ho sakta hai(Aur saare word usse chhote the length me)
Jaise hi mismatch mile, waise hi stop kar dena hai

> empty check ke bajaye aage ki strings ki length check karni chahiye
strs[i] chhoti hui to(** yahan chal jaa raha tha kyunki just next character '\0' access ho raha tha aur wo mismatch hoke else me bhej de raha tha)

accessing exactly 'one index past the end of a std::string does NOT crash. It safely returns the Null Character
But in Java/Pyhton, outofboundexception, and crash
Also if strs[1] was a vector<char>, accessing next element after ending would be undefined behaviour and could crash

agar ek bhi aur aage access karne ka code likhte to error aate
aur string na hoke vector hota to aata hi aata error next position access karne me
string me '\0' ki wajah se chal jaa raha hai code
to strs[0] ke har character ke liye ye check karen ki baaki sare words khatam to nahi ho gaye us position tak
Isliye better safety check -> if(j < strs[i].size() && strs[0][j] == strs[i][j])

Hamne !strs[i].empty() check kiya jo achha tha, par wo sirf tab bachata hai jab string bilkul khali ho
hame "string khali hai ya nahi" check nahi karna. Hamee yeh check karna hai ki "Kya main jis index j par hoon, kya yeh wali string utni badi hai bhi ya nahi?"
Isliye
length check -> j < strs[i].size() zyada zarooori hai 
Isme empty check bhi apne aap ho jaa raha hai(j = 0 pe (agar aage ke koi se bhi word empty hain(0 <= strs[i].length <= 200) to), 0 < 0 -> false, else me aake 0 length me resize karke empty string returned)

So, conclusion: Our code passed because C++ strings secretly have a \0 at the end, and comparing a character like 'e' with \0 correctly triggered our mismatch logic before we could go any further out of bounds
But we should not rely on the \0 trick to save our loops
Adding j < strs[i].length() is universal and language prrof correct way

TC -> O(S) | SC -> O(1) (If we don't count the returned string, we did it in-place)

Agar substr use karte(strs[0].substr(0, j);) to memory me ek nayi string banegi 
TC usme O(j) lagegi (Nayi string banane aur usme characters copy karne me utna hi time lagta hai jitna lamba prefic hai) 
aur SC O(j) (kyunki ek completely nayi string banayi)

resize me TC O(1) aur SC O(1)

So if modifying is OK(We don't need teh input vector function again or it will be trash) then we can resize) -> Memory bachegi
Aur agar
users ki query hain array ke form me
agar resize kar diya to user ka original word permanently kharab ho jayega -> substr -> memory use hogi par original data safe rahega

"I'm using resize to keep the space complexity O(1). However, if the input data needs to be preserved for future use, I would use substr to return a new string instead."

*/