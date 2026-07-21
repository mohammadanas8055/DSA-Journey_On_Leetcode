class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0; // Left pointer array ke start par rakha
                   // Ye left wall represent karega

        int j = height.size() - 1; // Right pointer array ke end par rakha
                                   // Ye right wall represent karega

        int maxArea = 0; // ab tak ka maximum area store karega

        while(i < j){ // jab tak dono pointers alag hain, tab tak container ban sakta hai
                      // agar i == j ho gaya, to width 0 ho jayegi, isliye loop wahin ruk jaata hai

            int width = j - i; // Container ki width = dono lines ke beech ka distance

            int containerHeight = min(height[i], height[j]); // Water level hamesha choti wall se decide hota hai
                                                             // Badi wall zyada height rakh sakti hai, but paani choti wall se upar nahi ruk sakta

            int currentArea = width * containerHeight; // Current pointers ke saath banta hua area

            maxArea = max(currentArea, maxArea); // Agar current area pehle wale maximum se bada hai, to answer update kar do

            if(height[j] > height[i]){ // Left wall choti hai
                                       // width to next step me kam ho hi rahi hai
                                       // isliya agar larger area chahiye
                                       // to hame height badhane ki ummeed chahiye
                                       // aur current bottleneck left wall hai
                                       // to right wall ko move karne se bottleneck remove nahi hoga
                                       // isliye choti wall ko hatao aur better wall dhoondho

                i++;
            }
            else{ // Yahan 2 cases included hain:
                  // 1. height[i] > height[j]
                  // 2. height[i] == height[j]
                  
                  // agar right wall choti hai, to same logic
                  // right wall bottleneck ai, isliye usko move karo

                  // Agar dono equal hain, to kisi ko bhi move kar sakte hain
                  // dono hi bottleneck hain
                  // consistency ke liye right pointer hi move kar rahe hain 
                j--;
            }
        }
        return maxArea; // Sab possible useful pointer states consider karne ke baad
                        // maximum area return kar diya
    }
};

/*

Kisi bhi pointer ko move karne par Width is always decreasing 
Agar taller pointer ko move kiya, to height of new container limit ho jayegi old shorter pointer ki wajah se
so moving the bigger pointer is guaranteed to give a smaller area here

Moving the shorter pointer is not a "prediction" that the area will increase. It is a realization that moving the taller pointer cannot possibly increase the area.

eg. [1, 8, 6, 2, 5, 4, 8, 3, 5]
Humein j ko isliye nahi move karna ki agla area 35 se bada hi aayega. Humein j ko isliye move karna hai kyunki bade wale (i) ko move karke kabhi bhi 35 se bada jawab nahi mil sakta.

Hamara goal har step par area badhana nahi hai. Hamara goal ye hai ki jis raste pe koi umeed nahi hai (taller pointer move karna), us raste ko chhod do.
Isse farq nahi pad raha ki (agle step pe) kaun sa product bada mil raha hai... par current se bada tabhi milne ka chance hai jab chhote wali height ko move karenge.

agar height barabar hai, to kisi ko bhi move kar do, kyunki dono hi bottleneck hain 
Improvement laane ke liye dono ko hi move karna padega
Joki loop next baar dusre ko handle kar hi lega

TC -> O(n) | SC -> O(1)

Final logic in 4 lines:
. Current area kis se banta hai> -> width * shorter height
. Next step me kya guaranteed hai? -> width kam hogi
. To area badhne ka chance kab hai? -> jab shorter height badhe
. Shorter height ko badhane ka chance kis me hai? -> Sirf shorter pointer move karne me

*/