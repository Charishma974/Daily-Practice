class Solution {
public:
    const long long MOD = 1e9 + 7;

    // Function for modular exponentiation
    long long modExp(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = 5;
        long long primeCount = 4;

        // Split n into even and odd positions
        long long evens = (n + 1) / 2;  // Number of even positions
        long long odds = n / 2;         // Number of odd positions

        // Calculate evenCount^evens % MOD and primeCount^odds % MOD
        long long evenContribution = modExp(evenCount, evens);
        long long oddContribution = modExp(primeCount, odds);

        // Multiply the results and take modulo MOD
        long long result = (evenContribution * oddContribution) % MOD;

        return (int)result;
    }
};
