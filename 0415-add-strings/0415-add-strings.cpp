class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1; // num1 ka last index
        int j = num2.size() - 1; // num2 ka last index
        int carry = 0; // agar sum 10 ya usse bada hai to next place par carry jayega
        string ans; // ans reverse order me sum ko store karega
        while(i >= 0 || j >= 0 || carry){ // jab tak ek bhi number me digits available hon, ya carry available ho(edge cases me, 99 + 1) tab tak loop chalega
            int digit1 = 0; // agar number me digit nahi bacha hai(valid index), it is treated as 0
            if(i >= 0){
                digit1 = num1[i] - '0'; // converting character into digit
                i--;
            }
            int digit2 = 0;
            if(j >= 0){
                digit2 = num2[j] - '0';
                j--;
            }
            int sum = digit1 + digit2 + carry;
            ans.push_back((sum % 10) + '0'); // current digit pushed as a character into sum
            carry = sum / 10; // 10 se bada tha to wo carry ka digit divide se aayega
            // next iteration ke liye carry update kiya
        }

        // answer reverse order me hai, isko reverse karna hoga
        int low = 0;
        int high = ans.length() - 1;
        while(low < high){
            char temp = ans[low];
            ans[low] = ans[high];
            ans[high] = temp;
            low++;
            high--;
        }
        return ans;
    }
};

/*

Converting whole strings into numbers is not the correct way, because there could be overflow bug 
Instead: Add them like school addition
Starting from last character, add digits, keep carry, build answer digit by digit
But the answer will come in reverse order, we would have to reverse it 

TC -> O(max(m,n)) | SC -> O(max(m,n))

*/