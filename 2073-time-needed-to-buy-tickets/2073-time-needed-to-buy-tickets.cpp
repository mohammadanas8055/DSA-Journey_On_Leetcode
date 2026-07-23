// class Solution {
// public:
//     int timeRequiredToBuy(vector<int>& tickets, int k) {
//         queue<int> q;
//         int time = 0;

//         for(int i = 0; i < tickets.size(); i++){
//             q.push(i); // queue me ticket values nahi store kar rahe
//                        // logon ke indices store karenge
//                        // kyunki position(k) bhi to track karna hai 
//         }

//         while(tickets[k] != 0){ // jab tak kth position wale person ko uski desired number of tickets nahi milti 
//                                 // tab tak process chalta rahega 

//             int index = q.front();
//             q.pop();
//             // queue ke front pe jo person tha
//             // uski position(index) store kar liya aur pop kar diya
            
//             tickets[index]--; // current person ne ek ticket kharid liya
//                               // isliye use jitne tickets chahiye usme se ek kam ho gaya

//             time++; // Har ek ticket kharidne me exactly 1 second lagta hai

//             if(tickets[index] > 0){ // tickets[index] > 1 use kar rahe to decrement baad me hoga -> Less natural
//                                    // Cleaner logic is, decrement number of tickets still needed -> agar >0 hai to push kar do 
//                 q.push(index); // Agar current person ko tickets kharidna bacha hai
//                                // to wo line ke end me wapis aa jayega      
//             }
//             // agar tickets[index] == 0 ho gaya 
//             // to us person ka kaam khatam, use queue me wapis nahi bhejna
            
//         }
//         return time;
//         // Jiase hi kth person(required person) ko saare tickets mil gye(tickets ka count 0 ho gaya)
//         // utna total time answer hai

//     }
// };

// /*

// In every turn, these 2 things always happen:
// 1. current person buys one ticket
// 2. time+
// Uske baad sawal ye hai, kya abhi is person ko aur tickets chahiye
// us index ko hata to diya hi hai aage se
// aur ticket Chahiye -> to sabse piche bhejo
// agar aur ticket Nahi chahiye -> to mat karo push

// TC -> O(sum of all tickets) -> (Har loop iteration me ek ticket buy ho raha hai, to utni baar loop chalega jitne ticket purchase honge) | SC -> O(n)

// But it can be done by another direct counting solution 
// O(n) TC and O(1) SC

// */

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int x = tickets[k]; // x = k-th person ko total kitne ticket kharidne hain
                            // Puri process exactly us moment tak chalegi, tab k-th person apna x-th ticket le lega

        int time = 0; // total seconds / total ticket purchases count karega

        for(int i = 0; i < tickets.size(); i++){
            if(i <= k){ // Jo log ke ke left me hain ya khud k hain
                        // unko k ke finish hone wale final round 

                        // isliye ye log maximum x baar ticket le sakte hain

                        // Lekin agar kisi ko x se kam tickets h ichahiye the
                        // to wo utne hi lenge aur line se nikal jayenge

                        // isliye contibution = min(tickets[i], x);

                time = time + min(tickets[i], x);
            }
            else{ // jo log k ke right me hain
                  // usko k ke final (x-th) turn ke baad chance hi nahi milega
                  // kyunki jaise hi k apna last tickt leta hai, process stop ho jaati hai

                  // matlab right side wale log maximum x - 1 baar hi ticket le sakte hain

                  // agar kisi ko usse kam ticket chahiye the, to wo utne hi lenge

                  // isliye contibution = min(tickets[i], x - 1);

                time = time + min(tickets[i], x - 1); 
            }
        }
        return time;
        // sab logon ke contributions ka total hi final answer hai
    }
};

/*

The ticket counter works in "rounds"
. Round 1: Everyone who wants a ticket gets 1 ticket
. Round 2: Everyone who still wants a ticket gets 1 ticket....and so on
Person k needs exactly x tickets
Yani counter will go around x times
but, round x will stop exactly when person k gets their last ticket

Now what happens to the people in the line during these x rounds?

Case 1: People In Front of k(and k themselves) -> i <= k
Processed before k in every single round
In round 1, they get a ticket. 
In round 2, they get a ticket
In round x, they get a ticket before k finishes
Tickets kitni kharidi unhone?
Agar kam tickets chahiye thin x se, to wo leke jaldi leave kar lenge(eg. they needeed 2, and k wanted 5) -> tickets[i] lenge wo log
Agar zyada tickets chahiye x se, to k ko pehle hi mil jayegi ticket, unhe bhi x ticket hi mi payegi, uske baad k ko x ticket milegi aur process stop ho jayega
Therefore contribtion to the time is: min(tickets[i], x)

Case 2: People standing BEHIND k -> i > k
Processed AFTER k in every single round
Round 1: They get a ticket
Round 2: They get a ticket
Round x: Person k buys xth ticket an process ends. Simulation Stops Immediately
To jo piche the, unhe us round me ticket nahi mila
yani x - 1 round me unhone particiapte

And then same logic, kam ticket chahiye hongi x - 1 se, to tickets[i] kharid ke nikal jayenge
Aur agar zyada chahiye hongi x - 1 se, to kth aadmi x ticket leke nikal jayega, unse pehle unhe x - 1 ticket hi mili hogi
Therefore, thier contibution in the time: min(tickets[i], x - 1)

TC -> O(n) | SC -> O(1)

*/