class Solution { 
public: 
    void fillSieve(vector<bool> &sieve){ 
        int n = sieve.size() - 1; 

        for(int i = 3; i * i <= n; i += 2){ 
            if(sieve[i]){ 
                for(int j = i * i; j <= n; j += 2 * i){ 
                    sieve[j] = 0; 
                } 
            } 
        } 
    } 

    int countPrimes(int n) { 
        if(n <= 2) return 0; 

        n = n - 1; 
        int count = 0; 

        vector<bool> sieve(n + 1, 1); 

        sieve[0] = 0; 
        sieve[1] = 0; 

        // Remove all even numbers
        for(int i = 4; i <= n; i += 2){ 
            sieve[i] = 0; 
        }

        fillSieve(sieve); 

        // 2 is the only even prime
        count = 1;

        // Check only odd numbers
        for(int i = 3; i <= n; i += 2){ 
            if(sieve[i]) 
                count++; 
        }  

        return count; 
    } 
};