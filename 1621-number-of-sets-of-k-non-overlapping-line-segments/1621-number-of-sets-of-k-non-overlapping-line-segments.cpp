class Solution {
    int MOD = 1e9 + 7;

    // Helper function for modular exponentiation
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // Helper function to find modular inverse
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    int numberOfSets(int n, int k) {
        int totalPoints = n + k - 1;
        int endpoints = 2 * k;
        
        if (totalPoints < endpoints) return 0;
        
        long long num = 1; // Numerator
        long long den = 1; // Denominator
        
        // Calculate (totalPoints)C(endpoints)
        for (int i = 0; i < endpoints; i++) {
            num = (num * (totalPoints - i)) % MOD;
            den = (den * (i + 1)) % MOD;
        }
        
        // Combine numerator and modular inverse of denominator
        return (num * modInverse(den)) % MOD;
    }
};