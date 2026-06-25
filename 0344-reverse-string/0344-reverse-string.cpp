class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;
        while(i < j){
            char temp = s[i]; // Ek character ko change karna hai, to char use karenge
                              // Also arrays ke jaise elements ko access kar sakte, name[i] se
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};

/*

! #include <algorithm> is needed for reverse
* abhi #include <string> ke bagair bhi chal raha hai par name.length() aur name.begin() string class me hi aata hai

# Pass by value vs Pass by reference

* agar void function me pass kiya to name = By VALUE pass ho raha hai. uski ek Copy mil rahi hai function ko 
= jo wo reverse kar raha hai , wo us copy ko reverse kar raha hai, na ki original ko
= to jab wapis main() me aayenge, to name(Original) is unchanged
* ANAS hi print ho jayega
/ FIX: Add & to make the function modify the original name string

> Arrays ke liye & nahi zaroori tha, kyunki they are always passed by reference 
> Strings(std::string) are NOT. They are passed by valued by default. & lagana padta hia
. int arr[] -> automatically by reference
. string str -> by value(use string& str for reference)
. vector<int> v -> by value(use vector<int>& v for reference)
> to strings aur vectors ke liye & use hoga pass by reference ke liye 

? agar ye banate function -> void func(const string& str) -> isse modify nahi hoga, 
? par jo copy ho raha tha wo bhi nahi hoga(read-only ke liye best hai)

= Passing by value

~ agar pass by reference na karte
~ to string data type ka function banana padta
~ usme value hi pass karte, aur phir reversed array ko return karte
> aur usko capture karne ke liye main() me bhi ek string banani padti
> phir use print kara lete
. isko avoid kar sakte jab string bahut badi ho

*/

/*

> "I can do this two ways: I'll use pass-by-reference for in-place modification,
> but I could also return a new string if you want the original preserved. Which would you prefer?"

*/
