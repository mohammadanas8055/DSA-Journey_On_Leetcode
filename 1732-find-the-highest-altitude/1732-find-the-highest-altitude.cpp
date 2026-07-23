class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0; // altitude current gain add karta jayega
                          // Starting altitude question ke according 0 hai

        int maxAltitude = 0; // highest altitude bhi initially 0 se start hoga
                             // kyunki starting point khud ek valid altitude hai
                             // Agar saare gains negative hue, tab bhi answer 0 ho sakta hai

        for(int i = 0; i < gain.size(); i++){
            altitude = altitude + gain[i]; // current gain ko revious altitude me add karke
                                           // next/current altitude nikaal li

            maxAltitude = max(maxAltitude, altitude); // har step pe check kar rahe hain ki
                                                      // nayi altitude ab tak ki sabse badi altitiude hai ya nahi
                                                      // Agar badi hai to answer update kar do
        }
        return maxAltitude; // puri trip me mili hui highest altitude return kar di
    }
};

/*

shuru me altitude 0 hai, isliye maxAltitude = 0 se shuru kiya
phir jo gain ho raha hai use add karte jayen, maximum mile(0 se bada) to usko update kar lenge

TC -> O(n) | SC -> O(1)

Pattern: 
running sum + track maximum

*/