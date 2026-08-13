class Solution {
public:
    int minTimeToType(string word) {
        int time = 0;
        // time me total seconds count karenge
        // Isme rotation ka time aur typing ka time dono add hoga

        char previous = 'a';
        // Pointer initially 'a' par hota hai(problem statement ke according)

        // previous ka role:
        // Ye batayega ki pointer abhi kis character par khada hai
        // Har naye character type karne se pehle ham previous character se current tak ka minimum rotation nikalenge

        // char rakha, int nahi, kyunki ham characters ke saath deal kar rahe hain
        // C++ me char aur int ke arithmetic automatic ho jaata hai(ASCII values)

        for(int i = 0; i < word.length(); i++){
            // word ke har character ko process karenge
            // Har character ke liye 2 kaam hote hain:
            // 1. Pointer ko rotate karna
            // 2. Type karna

            int diff = abs(word[i] - previous);
            // Alphabet-wise direction nikaali previous aur current char ke beech 

            // abs() isliye use kiya kyunki
            // difference direction-independent hona chahiye

            // eg.
            // 'a' se 'd' ki distance = |100 - 97| = 3
            // 'd' se 'a' ki distance = |97 - 100| = 3
            // Circle par distance same hoti hai chahe seedha karo ya ulta

            diff = min(diff, 26 - diff);
            // Keyboard circular hai, isliye 2 raaste hote hain:

            // 1. Clockwise = diff(seedhi distance)
            // 2. Anticlockwise = 26 - diff(circle ki doosri taraf se)

            // Total characters 26 hain, isliye
            // agar ek taraf se diff steps lagti hain
            // to dusre taraf se (26 - diff) steps lagengi
            
            // eg.
            // 'a' se 'z' -> clockwise = 25, anticlockwise = 1
            // min = 1;

            // Hamesha shortest path lena hai, isliye min()

            time += diff + 1;
            // diff = rotation seconds(minimum path)
            // +1 = typing seconds(har char ko type karne me 1 sec lagta hai)

            // Dono ko ek saath add kar diya taaki alag alag line na likhni pade

            previous = word[i];
            // ab pointer current character pe shift ho gaya
            // Next iteration me ye "previous" ban jayega
            // Isliye update karna zaroori hai 
        }
        return time;
        // Pure word ko type karne me laga total time return kar diya
    }
};

/*

Ye pehle se sochne ke bajaye ki kon paas rahega(word[i] + 13 karke), bas ek formule se pata chal jayega kon sa raasta paas padega
Clockwise ya anticlockwise - dono me jo SHORTEST ho, wahi lo

If 'a' pe hai current pointer aur 'z' pe jana hai 
a → b → c → .... → z (Distance = 25)
a → z (Distance = 1)
To diff kya hai shuru me = abs(current - previous) 
Then clockwise = diff
anticlockwise = 26 - diff
Minimum of these two = actual movement time
Plus 1 for typing 

We use abs() because charactr difference direction-independent hona chahiye 
clockwise anticlockwise to 26 se minus karke aa hi jayega

Why 26 - diff? Because circle me total 26 characters hain
Agar clockwise diff steps lagti hain, to anticlockwise 26 - diff lagegi

Aur pehla position 'a' hi hoga
to 'a' se shuru karenge pointer ko

Therefore, 
abs() = kitni distance chalni hai(direction chhod ke)
26 - diff = same distance ka doosra raasta(circle ke doosri taraf se)
min() = jo chhota hai wahi lo

TC -> O(n) | SC -> O(1)

*/