// class Solution {
// public:
//     bool isPrime(int n){
//         for(int i = 2; i * i <= n; i++){
//             if(n % i == 0){
//                 return false;
//             }
//         }
//         return true;
//     }
//     int countPrimes(int n) {
//         if(n == 0 || n == 1 || n == 2){
//             return 0;
//         }
//         int count = 0;
//         for(int i = 2; i < n; i++){
//             if(i == 2 || i == 3){
//                 count++;
//             }
//             else if(isPrime(i)){
//                 count++;
//             }
//         }
//         return count;
//     }
// };

/*

Har number i ke liye O(sqrt(i)) me primality check ki hai
Total time complexity: O(N(sqrt(N)))
For N = 5 * 10^6 -> N(sqrt(N)) = 11,000,000,000
In C++, ek second me max 10^8 operations ho sakte hain
11 Billion operations ke liye 100 seconds lagenge -> TLE

Iska solution: Sieve of Eratosthenes(O(NloglogN))

not checking individual elements, instead using Elimination(Table strike-off) technique

2 se N - 1 tak saare number prime maan liye 
2 aaya -> prime hai -> sare multiple cut kar do
3 aaya -> prime -> multiples cut
4 aaya -> prime nahi hai(pehle hi 2 ne kaat chuka hai)
5 aaya -> saare multiples cut
Aur do optimization tricks in Sieve: 
. inner loop start hoga i x i se, kyunki 5 ke multiples kaatte waqt 5 x 2 = 10, 5 x 3 = 15 aur 5 x 4 = 20 pehle hi 2,3,4 se kar chuke hain
. outer loop sqrt(N) tak hi chalega, kyunki inner loop i x i se start ho raha hai

*/

class Solution{
public: 
    int countPrimes(int n){
        if(n <= 2) return 0; // 2 se chhote kisi number ke paas primes nahi hote(strictly excluded)

        // Step 1: Ek boolean vector banao size 'n' ka(1 bit per bool instead of 1 byte)
        // Initially sabhi numbers ko 'true'(prime) assume kar lo
        vector<bool> seen(n, true);

        // 0 aur 1 Prime nahi hote
        seen[0] = false;
        seen[1] = false;

        // Step 2: Sieve marking
        // Outer loop sirf sqrt(n) tak chalega(i * i < n)
        // Because if a composite number 'x' < n has a factor
        // at least one factor must be <= sqrt(n)
        // Also inner loop i x i se start ho raha hai. agar i > sqrt(n) hua, to i x i > n ho jayega
        // Use long long for 'i' to prevent integer overflow when computing i * i for large
        for(long long i = 2; i * i <= n; i++){
            // Agar 'i' prime hai, to uske saare multiples ko NOT PRIME(false) mark kar do
            if(seen[i] == true){

                // Inner loop i * i se start hota hai kyunki smaller multiples pehle hi mark ho chuke hain
                // Step size: j += i (jumps through all multiples of u : i * i, i * i + i, i * i + 2i ....)
                for(long long j = i * i; j < n; j = j + i){
                    seen[j] = false; // Mark multiples as non-prime
                }
            }
        }

        // Step 3: Count total 'true' values in vector
        int count = 0;
        for(int i = 2; i < n; i++){
            if(seen[i] == true){
                count++;
            }
        }
        return count;
    }
};

/*

Outer loop i x i <= n pe ruk kyun gaya?
For n = 20:
. i = 2 -> 2 x 2 = 4 <= 20 (Chala)
. i = 3 -> 3 x 3 = 9 <= 20 (Chala)
. i = 4 -> 4 x 4 = 16 <= 20 (Chala)
. i = 5 -> 5 x 5 = 25 > 20 (Ruk gaya)
Kyunki 20 se chhote jitne bhi compostie(non-prime) numbers the(jaise 4,6,8,9,10,12,14,15,16,18), un sabka...koi na koi factor ... <= sqrt(20) ≈ hota hi hai
i = 5 par pahunchne tak, bacha hua har ek number jo abhi bhi true hai, wo GUARANTEED PRIME hai

1. if(seen[i] == true): "Agar kisi number ko abhi tak piche wale kisi number ne NAHI kata, iska matlab 1 aur khud ke alawa koi factor nahi hai. Matlab ye PRIME hai"

2. int j = i * i: "Is number i ke saare chhote multiples(jaise i x 2, i x 3, i x 4) chhote prime spehle hi kaat chuke hain. Hame mehnat wahan se shuru karni hai jahan se pehle kisi ne nahi kata: i x i se"

3. i * i <= n: "n se chhote saare non-prime numbers ke factors <= sqrt(n) hote hai. Jab ham sqrt(n) tak saare multiples kaat chuke, to ab array me jo true bache hain wo 100% Primes hain. Loop aage chalane ki zaroorat nahi"

TC -> O(NloglogN) (N x (1/2 + 1/3 + 1/5 + 1/7 + ...) = O(NloglogN))
now for N = 5 x 10^6, NloglogN ≈ 1.5 x 10^7 
1.5 x 10^7 << 10^8 -> runs in 50ms
SC -> O(N)

*/