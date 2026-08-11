class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        // Answer yahan build hoga
        // Important: answer reverse order me build hoga
        // kyunki ham last digits se addiiton start kar rahe hain
        
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        // i aur j dono strings ke last index par start kar rahe hain
        // School addition bhi rightmost digit se hi hoti hai

        int carry = 0;
        // Previous place ka carry yahan store rahega

        while(i >= 0 || j >= 0 || carry){
            // Loop tab tak chalega jab tak:
            // - num1 me digits bache hain
            // - ya num2 me digits bache hain
            // - ya carry abhi bhi pending hai

            // carry ko condition me rakhna bahut zaroori hai
            // warna cases like "99" + "1" me last carry lose ho jayegi

            int sum = 0;
            int digit1 = 0;
            int digit2 = 0;
            // Agar kisi string me digit available nahi hai
            // to us side ko 0 treat karenge
            // Ye unequal-length strings handle karne ke liye zaroori hai

            if(i >= 0){
                digit1 = num1[i] -'0';
                // Character digit ko integer digit me convert kiya

                i--;
                // Ek step left move kar gaye
                // negative ho gaya to next loop me if false ho jayega aur iska digit 0 treat hoga
            }
            if(j >= 0){
                digit2 = num2[j] - '0';
                // Same conversion second string ke liye 

                j--;
                // negative ho gaya to next loop me if false ho jayega aur same iska bhi digit 0 treat hoga
            }
            sum = digit1 + digit2 + carry;
            // current place ka total

            ans.push_back(sum % 10 + '0');
            // current place ka actual digit answer me add kiya
            // sum % 10 se last digit milti hai

            // + '0' isliye ki integer digit ko character me convert kar sakein
            
            // Ye push_back reverse order me ho raha hai
            // kyunki addition least significant digit se start hui hai

            carry = sum / 10;
            // Agar sum >= 10 hua, to next place ke liye carry generate hogi
        }
        reverse(ans.begin(), ans.end());
        // Ab tak answer ulta build hua tha
        // isliye final correct order ke liye reverse kar diya

        return ans;
    }
};

/*

Converting whole strings into numbers is not the correct way, because there could be overflow bug 
Instead: Add them like school addition
Starting from last character, add digits and carry, update carry, build answer digit by digit
But the answer will come in reverse order(because we are adding from right to left: units place first, then tens, then hundreds), we would have to reverse it 
while(i >= 0 || j >= 0 || carry) is a very important condition
. i >= 0 -> means num1 me abhi digits bache hain
. j >= 0 -> means num2 me abhi digits bache hain
. carry -> means even if both sstrings khatam ho gayi ho, last carry abhi bhi answer me add karni baaki ho sakti hai(eg. "99" + "1") -> At the end: both strings finish, but carry = 1 still remains
           If || carry nahi hota, to answer wrong ho jaata

Why digit1 = 0, digit2 = 0?
This is necessary because lengths different ho sakti hain 
So when j exhausts, digit2 should act like 0
That is why: if valid index exists, read digit
             otherwise keep it as 0

i-- and j-- are okay inside or outside the blocks
because jab string khatam hogi to i ya j negative ho jayega 
then if(i >= 0) / if(j >= 0) prevents invalid access
So even if pointer aur negative hota rahe, code safe rehta hai
to if ke andar hi zyada thik hai, baar baar updation ki zaroorat nahi 

TC -> O(max(m,n)) | SC -> O(max(m,n)) for output -> Extra auxiliary space -> O(1)

*/