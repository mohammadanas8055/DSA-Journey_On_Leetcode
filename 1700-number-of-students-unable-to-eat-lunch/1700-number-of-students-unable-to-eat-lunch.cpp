// class Solution {
// public:
//     int countStudents(vector<int>& students, vector<int>& sandwiches) {
//         stack<int> st;
//         // Sandwiches ko stack me store kar rahe hain
//         // Top of stack = current sandwich at top of pile

//         for(int i = sandwiches.size() - 1; i >= 0; i--){
//             st.push(sandwiches[i]);
//             // reverse order me push kiya taaki sandwiches[0] stack ke top par aa jaye
//         }

//         queue<int> q;
//         // Students ko queue me store karenge
//         // Front of queue = line me sabse aage wala student

//         for(int i = 0; i < students.size(); i++){
//             q.push(students[i]);
//         }

//         int rejectedCount = 0;
//         // Ye count karega ki current top sandwich ko lagatar kitne students ne reject kiya

//         while(!st.empty()){
//             // Jab tak sandwiches bachi hain, process chalta rahega

//             if(q.front() != st.top()){
//                 // Current front student ko top sandwich pasand nahi aayi
//                 int temp = q.front();
//                 q.pop();
//                 q.push(temp);
//                 // Student ko line ke end me bhej diya

//                 rejectedCount++;
//                 // Ek aur rejection count kar liya

//                 if(rejectedCount == q.size()){
//                     break;
//                 }
//                 // Agar current queue ke saare students ne current top sandwich reject kar di
//                 // To ab process aage kabhi move nahi karegi
//                 // kyunki same sandwich top par rahegi
//                 // aur same students usse mana karte rahenge
//             }
//             else{
//                 // Current front student ko top sandwich

//                 q.pop();
//                 st.pop();
//                 // Student sandwich le kar line se nikal gaya
//                 // Aur sandwich pile se bhi remove ho gayi

//                 rejectedCount = 0;
//                 // Current sandwich consume ho gayi
//                 // Ab nayi top sandwich ke liye fresh counting start hogi
//             }
//         }
//         return q.size();
//         // Queue me jitne students bache hain
//         // Ab nayi wahi sandwich nahi kha payenge
//     }
// };

// /*

// TC -> O(n^2) (Worst case) | SC -> O(n)

// But since sandwich types only 0 aur 1 hain, to actual queue simulation avoid ki ja sakti hai

// */


class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // Students ka order matter nahi karta, sirf unka "choice count" matter karta hai
        // Kyunki jo student nahi khata wo wapas line me lag jata hai
        
        vector<int> count(2, 0);
        // 0 aur 1 wale bachchon ko count karne ke liye constant space ka vector bana liya

        for (int i = 0; i < students.size(); i++) {
            if (students[i] == 0) {
                count[0]++;
                // count[0] = number of students who want 0
            } 
            else {
                count[1]++;
                // count[1] = number of students who want 1
            }
            // or write 
            // count[student[i]]++;
        }

        // Sandwich pile ka order non-negotiable hai
        // Jab tak top sandwich nahi nikalta, niche wale locked hain
        for (int i = 0; i < sandwiches.size(); i++) {
            // Check karo kya line me koi bhi aisa student bacha hai
            // jo ye current sandwich kha sakta hai(count > 0 or count != 0)
            if(sandwiches[i] == 0 && count[0] != 0){
                // Agar 0 wala student bacha hai, to wo aaj nahi to 10 rotation baad
                // front par aa kar ise kha hi lega 
                count[0]--;
            }
            else if(sandwiches[i] == 1 && count[1] != 0){
                // Similarly for student 1
                count[1] --;
            }
            // OR in only one if
            // if(count[sandwiches[i]) > 0]){
            //     count[sandwiches[i]]--;
            // }
            else{
                // Agar line me is type ka EK BHI studnet nahi bacha
                // to ye sandwich pile ke top par hamesha ke liye phans jayegi
                // Aur niche wali sandwiches bhi block ho jayengi
                break;
            }
        }
        // int answer = 0;
        // for(int i = 0; i < 2; i++){
        //     answer += count[i];
        // }
        return count[0] + count[1];
        // Bache hue students ka sum hi hamara answer hai
    }
};

/*

Simulation(Queue) ki zarurat nahi kyunki studnets rotate ho sakte hain
Choice Count: Store how many studnets want 0 and 1
Pile bottleneck: Sandwich tabhi remove hogi jab koi use khane wala bacha ho

Sandwich pile se tabhi niklegi jab koi student use khayega
To agar top par 0 hai, to end me baitha hua student 0 tabhi kha payega jab usse aage wale student rotate hoke use aage karen
Lekin agar line me ek bhi aisa student hi nahi bacha jise 0 chahiye, toh top par rakha 0 kabhi wahan se hatega hi nahi 
Aur agar wo nahi hata, to uske niche wale sandwiches bhi kabhi upar hi nahi aayenge
Isliye:
Bas counts store karlo: Kitno ko 0 chahiye, kitno ko 1.
Pile ko ek-ek karke dekho.
Jo sandwich aayi, dekho kya line mein koi bhi (ANYONE) bacha hai jo ise kha sake?
Agar bacha hai, toh woh rotate hokar kabhi na kabhi upar aa hi jayega. Toh usse minus kar do.
Agar line mein us type ka student hi nahi bacha, toh pile block ho gayi. Wahin ruk jao.

TC -> O(n) | SC -> O(1)

*/