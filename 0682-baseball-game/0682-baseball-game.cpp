class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;
        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "C"){
                ans.pop_back();
            }
            else if(operations[i] == "D"){
                int doubled = 2 * ans.back();
                ans.push_back(doubled);
            }
            else if(operations[i] == "+"){
                // int last = ans.back();
                // ans.pop_back();
                // int add = last + ans.back();
                // ans.push_back(last);
                // ans.push_back(add);
                // Instead of this, we can directly access elements using index
                int sum = ans[ans.size() - 1] + ans[ans.size() - 2];
                ans.push_back(sum);
            }
            else{
                int num = 0;
                if(operations[i][0] == '-'){
                    for(int j = 1; j < operations[i].length(); j++){
                    num = num * 10 + (operations[i][j] - '0');
                }
                num = num * -1;
                }
                else{
                    for(int j = 0; j < operations[i].length(); j++){
                    num = num * 10 + (operations[i][j] - '0');
                }
                }
                ans.push_back(num);
            }
        }
        int sum = 0;
        for(int i = 0; i < ans.size(); i++){
            sum = sum + ans[i];
        }
        return sum;
    }
};

/*

We used ans vector as a stack
And here vector is actually convenient because later you can also access second last element more easily.

// ans vector ko stack ki tarah use kar rahe hain
// isme valid scores store honge

// "C" aaye to last valid score hata do

// "D" aaye to previous valid score ka double push karo

// "+" aaye to last do valid scores ka sum push karo

// agar operation number hai, to us string ko integer me convert karke push karo

// end me saare valid scores ka sum return kar do

TC -> "C" → O(1)
   -> "D" → O(1)
   -> "+" → O(1)
   -> number string → O(length of that string)
   therefore O(total characters in all strings + number of operations) -> O(n) (n = operations.size()) because sting lengths are small and each operation is processed once
   Summation loop -> O(n)
   But total still O(n) + O(n) = O(n)
SC -> O(n)

We can also maintain a running sum while processing operations

> stoi(operations[i]) can be used for number parsing(converting string to integer)

*/

/*

More clean code(with running sum)

class Solution{
public:
    int calPoints(vector<string>& operations){
        vector<int> scores; // Stack ki tarah use karenge valid scores store karne ke liye
        int sum = 0; // running sum maintain karenge taaki end me alag loop na lagana pade

        for(int i = 0; i < operations.size(); i++){

            // Case 1: "C" -> Last valid score cancel ho jayega
            if(operations[i] == "C"){
                sum = sum - scores.back(); // jo score remove kar rahe hain usko sum se bhi hata do
                scores.pop_back();
            }

            // Case 2: Previous valid score ka double add karna hai
            else if(operations[i] == "D"){
                int doubledScore = 2 * scores.back(); 
                sum = sum + doubledScore;
                scores.push_back(doubledScore);
            }

            // Case 3: "+" -> last 2 valid scores la sum add karna hai
            else if(operations[i] == "+"){
                int newScore = scores[scores.size() - 1] + scores[scores.size() - 2];
                sum = sum + newScore;
                scores.push_back(newScore);
            }

            // Case 4: Normal number string hai
            else{
                int num = 0;
                int sign = 1;
                int start = 0;

                // Agar negative number hai to sign ko -1 kar do
                if(operations[i][0] == '-'){
                    sign = -1;
                    start = 1;
                }

                // string ko integer me manually convert karo
                for(int j = start; j < operations[i].length();j++){
                    num = num * 10 + operations[i][j] - '0';
                }

                num = num * sign;

                scores.push_back(num);
                sum = sum + num;
            }
        }
        return sum;
    }
};


*/