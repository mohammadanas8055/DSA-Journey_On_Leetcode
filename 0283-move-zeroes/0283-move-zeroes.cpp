class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        // 'i' ek marker hai jo batata hai ki agla non-zero element kahan place hona chahiye

        for(int j = 0; j < nums.size(); j++){
            // 'j' ek scout/explorer hai jo puri array me aage badhega
            // Aur check karega ki koi non-zero mila ya nahi

            if(nums[j] != 0){
                // Agar 'j' ko non-zero mil gaya
                // to use uthakar 'i' ki position par daal do(swap kar do)
                swap(nums[i], nums[j]); 

                // Ab 'i' waali jagah bhar gayi, to marker ko aage badhao
                i++;
            }
            // Agar nums[j] == 0 hai, to kuch mat karo, bas 'j' ko aage badhne do
            // Piche chhoota hua 0 baad me swap hokar apne aap end me chala jayega
        }
        // Array in-place modify ho gayi
        // Saare non-zeros aage aa gaye, aur saare zeros swap hokar piche chale gaye
    }
};

/*

i is the pointer that says: "Put the next non-zero number here"
j is the scout that goes looking for non-zero numbers
When j finds a non-zero:
It swaps with i
i moves forward, securing that non-zero in its rightful place

TC -> O(n) | SC -> O(1)

*/