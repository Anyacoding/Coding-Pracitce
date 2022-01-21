法一：埃拉托斯特尼筛法（Sieve of Eratosthenes，简称埃氏筛法）是非常常用的，判断一个整数是
否是质数的方法。并且它可以在判断一个整数 n 时，同时判断所小于 n 的整数，因此非常适合这
道题。其原理也十分易懂：从 1 到 n 遍历，假设当前遍历到 m，则把所有小于 n 的、且是 m 的倍
数的整数标为和数；遍历完成后，没有被标为和数的数字即为质数
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int count = n - 2; //去掉不是质数的1，且题目要求的是小于n的质数的数量，所有n本身也要减掉
        vector<bool> prime(n, true);
        for (int i = 2; i < n; ++i) {
            if (prime[i]) {
                for (int j = 2 * i; j < n; j += i) {
                    if (prime[j]) {
                        prime[j] = false;
                        --count;
                    }
                }
            }
        }
        return count;
    }
};
