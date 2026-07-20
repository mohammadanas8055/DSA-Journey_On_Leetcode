class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st; // Stack numbers store karega
                       // Jab operator milega, to stack ke top ke last 2 numbers par operation hoga

        for(int i = 0; i < tokens.size(); i++){

            // Case 1: Addition operator
            if(tokens[i] == "+"){
                int b = st.top();
                st.pop(); // top element pehle pop hota hai, ye second operand hoga

                int a = st.top();
                st.pop(); // Iske niche wala first operand hoga

                st.push(a + b); // a + b ka result stack me wapas push kar diya 
            }

            // Case 2: Subtraction operator
            else if(tokens[i] == "-"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a - b); // Order important hai
                                // RPN me top wala second operand hota hai
                                // isliye a - b karna hai, b - a nahi
            }

            // Case 3: Mulitplication operator
            else if(tokens[i] == "*"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a * b);
            }
            
            // Case 4: Division operator 
            else if(tokens[i] == "/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a / b); // Yahan bhi order important hai
                                // a first operand hai, b second operand
            }

            // Case 5: Token ek number hai
            else{
                int sign = 1; // sign negative number handle karne ke liye 
                int num = 0;
                int start = 0; // start batayega digit parsing kis index se start karna hai

                if(tokens[i][0] == '-'){ // Agar first character '-' hai
                                         // to number negative hai
                                         // Isliye actual digits index 1 se start hongi
                    sign = -1;
                    start = 1;
                }
                for(int j = start; j < tokens[i].length(); j++){
                    num = num * 10 + tokens[i][j] - '0'; // String token ko manually integer me convert kar rahe hain
                }

                num = num * sign; // Agar negative tha to final sign apply kar diya 
                
                st.push(num); // Parsed number stack me push kar diya 
            }
        }

        return st.top(); // End me stack me sirf final evaluated result bachega
    }
};

/*

In RPN, when you see an operator:
. first pop = second operand
. second pop = first operand
So is the stack top is ...a b
Then for operator
pop b
pop a
result should be a op b
and not          b op a

> RPN means:

numbers go into stack
operator appears → apply it on last two numbers
So stack naturally fits because:

most recent operands are needed first

>Alternative for number parsing
stoi(tokens[i])

TC -> O(total characters in all tokens) -> O(n) (if token lengths are treated as small. Each token processed once, number parsing scans its digits once) | SC -> O(n) (Stack may store many numbers)


*/