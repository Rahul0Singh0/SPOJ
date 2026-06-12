// https://www.spoj.com/problems/PRIME1/
#include <iostream>
#include <unordered_map>

std::unordered_map<long long, bool> dp;

bool isPrime(long long n) {
    if (dp.find(n) != dp.end()) {
        return dp[n];
    }

    if (n < 2) {
        return dp[n] = false;
    }

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return dp[n] = false;
        }
    }

    return dp[n] = true;
}

// bool isPrime(long long n) {
//     if (n < 2) {
//         return false;
//     }
//
//     for (long long i = 2; i * i <= n; i++) {
//         if (n % i == 0) {
//             return false;
//         }
//     }
//
//     return true;
// }


/*
   1 <= t <= 10
   (1 ≤ m ≤ n ≤ 1000000000, n-m ≤ 100000)
*/

// TLE
// O(10 * (n-m) * m)
// In worst case - 10 * 100000 * 10 ^ 9 = 10 ^ 15
// If we assume If system perform 10 ^ 8 operations per second then 10 ^ 15 / 10 ^ 8 = 115.7407407 days

// bool isPrime(long long n) {
//     if (n == 1) {
//         return false;
//     }
//
//     for (long long i = 2; i < n; i++) {
//         if (n % i == 0) {
//             return false;
//         }
//     }
//
//     return true;
// }

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        long long m;
        std::cin >> n >> m;
        for (long long i = n; i <= m; i++) {
            if (isPrime(i)) {
                std::cout << i << std::endl;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}