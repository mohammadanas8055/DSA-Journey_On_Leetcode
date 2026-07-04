class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int maxAltitude = 0;
        for(int i = 0; i < gain.size(); i++){
            altitude = altitude + gain[i];
            if(altitude > maxAltitude){
                maxAltitude = altitude;
            }
        }
        return maxAltitude;
    }
};

/*

shuru me altitude 0 hai, isliye maxAltitude = 0 se shuru kiya
phir jo gain ho raha hai use add karte jayen, maximum mile(0 se bada) to usko update kar lenge

TC -> O(n) | SC -> O(1)

Pattern: 
running sum + track maximum

*/