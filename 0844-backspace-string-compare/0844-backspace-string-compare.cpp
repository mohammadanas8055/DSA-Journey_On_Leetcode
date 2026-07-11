class Solution {
public:
    bool backspaceCompare(string s, string t) {
        /* 
        
        stack<char> s1;
        stack<char> t1;

        //Processing the string s

        for(int i = 0; i < s.length(); i++){ 
        //agar current character '#' hai aur stack empty nahi hai to last type character ko delete kar denge(pop)
            if(!s1.empty() && s[i] == '#'){
                s1.pop();
            }
            // Agar stack empty hua, aur tab '#' mil jaye, to delete karne ko kuch hai nahi, to us backspace character ko skip kar dena hai and continue
            else if(s[i] == '#'){
                continue;
            }
            // Koi aur normal character aayega, to use push kar denge stack me 
            else{
                s1.push(s[i]);
            }
        }

        //Processing the string t(same logic as string s)

        for(int i = 0; i < t.length(); i++){
            if(!t1.empty() && t[i] == '#'){
                t1.pop();
            }
            else if(t[i] == '#'){
                continue;
            }
            else{
                t1.push(t[i]);
            }
        }
        
        // '==' operator compares sizes and elements for std::stack
        // Top to bottom in linear time, If they match -> Returns true
        return s1 == t1;

        TC -> O(m + n) -> O(n)(If both have same length) | SC -> O(m + n) -> O(n)

        So Trying SC of O(1) 

        */

        // Initialising two pointers at the end of both strings(right-to-left)
        // Why right-to-left?
        // A backspace(#) only deletes characters to its left
        // If we go left-to-right, we don't know if a letter survive because a future '#' might delete it
        // But if we go right-to-left, the moment we see a #, we know the next letter on the left has to erased

        int i = s.length() - 1;
        int j = t.length() - 1;
        int skipS = 0; // Number of "Erasers" we have in our hand
                       // Jab bhi '#' mile, ek eraser badha lo aur agle character pe aa jao
                       // Agar eraser khatam ho gaye(skipS == 0) -> ye letter bach gaya, phir isi tarah dusri string se ek survived letter aayega aur compare hoga 
        int skipT = 0;

        while(i >= 0 || j >= 0){ // || operator kyunki koi string badi ho sakti hai koi string choti, dono strings ko pura traverse karna hai na

            while(i >= 0){ // Jab tak string s khatam nahi ho rahi 
                if(s[i] == '#'){ // Found a backspace
                    skipS++;     // pick up an eraser
                    i--;         // Agle character pe aao, jise delete karna hoga
                }
                else if(skipS > 0){ // Found a letter, but have erasers? -> Erase it
                    skipS--;
                    i--;
                }
                else{ // Found a letter and NO erasers? -> Stop! -> This letter survived
                    break;
                }
            }
            
            // Similarly find a surviving character from string t
            while(j >= 0){
                if(t[j] == '#'){
                    skipT++;
                    j--;
                }
                else if(skipT > 0){
                    skipT--;
                    j--;
                }
                else{
                    break;
                }
            }
            if((i >= 0 && j < 0) || (i < 0 && j >= 0)){ // Agar ek pointer valid hai( >= 0) aur doosre ke character khatam ho chuke hain( < 0)
            // Matlab ek string me surviving letters hain abhi bhi aur dusri string khatam ho chuki, to empty string != non-empty string -> Return false
                return false;
            }
            // Agar if statement false hai -> i and j are still inside the string ( >= 0) or out of bounds( < 0)
            else if(i >= 0 && j >= 0 && s[i] != t[j]){ // Agar pointers valid hain( >= 0), current surviving characters same hone chahiye, agar nahi hain to matlab strings equal nahi aayengi -> Return false  
                return false;
            }
            // Agar ye bhi false hua, to iska matlab koi aisi situation nahi hai jisme dono pointer in-bound bhi hon aur character different hon

            // Both are in-bound and matching(to i-- aur j-- kar do)
            // Maybe dono out of ound ho jayen(to upar i >= 0 || j >= 0) se loop end ho jayega
            else{ // Yani dono character match kar gaye, to dono pointer ko piche laayenge, rest of the characters ko compare karne ke liye
                i--;
                j--;
            }
        }

        // Agar pura traverse ho gaye dono without any mismatch -> Strings are equal after backspaces
        return true;
    }
};

/*

TC -> O(m + n) | SC -> O(1) 

*/