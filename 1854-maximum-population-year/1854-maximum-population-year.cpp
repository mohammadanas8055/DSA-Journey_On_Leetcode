class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int maxPopulation = 0;
        // Ab tak ka maximum population count store karega
        // 0 se start isliye kiya kyunki koi bhi valid population usse bada hoga
        // Aur agar array khali bhi ho to bhi safe hai(edge case)

        int maxYear = logs[0][0];
        // maxYear ko logs ke pehle person ke birth year se initialize kiya
        // kisi person ka actual data, not just a range boundary
        // Assumption: logs khali nahi hai

        for(int Y = 1950; Y <= 2050; Y++){
            // har possible year check karenge
            // Problem constraints ke according years 1950 se 2050 ke beech hi hote hain
            // Isliye baaki years check karne ki zaroorat nahi 

            int population = 0;
            // Current year Y me kitne log alive hain, wo count karega
            // Har naye year ke liye 0 se reset karna zaroori hai

            for(int i = 0; i < logs.size(); i++){
                // Har person ko check karenge

                if((logs[i][0] <= Y) && (logs[i][1] > Y)){
                    // Person alive hai year Y me agar:
                    // - birth year Y se pehle ya barabar hai(log[i][0] <= Y)
                    // - death year Y ke baad hai (log[i][1] > Y)
                    
                    // > isliye use kiya(not >= ) kyunki death year me person alive NAHI hota
                    // Problem statement clearly kehta hai person alive in [birth, death)
                    // Yani half-open interval - death year exclusive hai

                    population++;
                    // Ye person alive hai, count badhaya
                }
            }
            if(population > maxPopulation){
                // Strictly greater check kar rahe hain, >= nahi
                // Kyunki problem tie-breaker kehta hai: earliest year return karo
                
                // Agar koi later year same maximum hit karega, wo update nahi hoga
                // Isse automatically earliest year retain rehta hai

                maxPopulation = population;
                maxYear = Y;
            }
        }
        return maxYear;
        // Wo year return kar diya jab maximum log alive the
    }
};

/*

tue breaker handled automatically
because if(population > maxPopulation) strictly greater hone par hi update ho raha hai
agar koi aur year me same max population hit hue, to > false hoga, to maxYear update nahi hoga, so earliest year hi return hoga

TC -> O(100 * n) -> O(n) | SC -> O(1)

There can be another smarter approach using Prefix Sum/Difference array that runs in O(n + 100)
But that's an optimization

*/