#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>
int millerTest(unsigned long long n, std::vector<int> Q, int t);
bool generatePrime(int bits, int t, unsigned long long& prime, int& rejected, const std::vector<int>& simple);
unsigned long long modulo(unsigned long long base, unsigned long long power, unsigned long long mod);
void sieve(std::vector<int>& simple);
int bit(unsigned long long x);
unsigned long long generate(int bits, std::vector<int> simple, std::vector<std::pair<int, int>>& coef);
int main() {
    std::srand(std::time(NULL));
    std::vector<int> simple;
    sieve(simple);
    int bits, t;
    std::cin >> bits;
    std::cin >> t;
    unsigned long long prime;
    int rejected;
    if (generatePrime(bits, t, prime, rejected, simple)) {
        std::cout << "Prime: " << prime << std::endl;
        std::cout << "Rejected: " << rejected << std::endl;
    }
    return 0;
}
void sieve(std::vector<int>& simple) {
    std::vector<bool> index(1001, false);
    for (int i = 2; i < 1001; ++i) index[i] = true;
    for (int i = 2; i * i < 1001; ++i) {
        if (index[i]) {
            for (int j = i * i; j < 1001; j += i) index[j] = false;
        }
    }
    for (int i = 0; i < 1001; ++i) {
        if (index[i] == true && i != 2) {
            simple.push_back(i);
        }
    }
}
int bit(unsigned long long x) {
    int length = 0;
    while (x > 0) {
        ++length;
        x = x >> 1;
    }
    return length;
}
unsigned long long generate(int bits, std::vector<int> simple, std::vector<std::pair<int, int>>& coef) {
    unsigned long long m;
    std::vector<int> used;
    bool isDone = 1;
    while (isDone) {
        m = 1;
        coef.clear();
        used.clear();
        bool isOkey = 1;
        while (bit(m) < bits - 1 && isOkey == 1) {
            if (used.size() == simple.size())
                isOkey = 0;
            else {
                int q = 0;
                bool found = 1;
                while (found && used.size() < simple.size()) {
                    int i = std::rand() % simple.size();
                    q = simple[i];
                    bool isUsed = 1;
                    for (int number : used)
                        if (number == q) isUsed = 0;
                    if (isUsed == 1) {
                        found = 0;
                        used.push_back(q);
                    }
                }
                int a = (std::rand() % 3) + 1;
                unsigned long long multiplier = 1;
                for (int i = 0; i < a; ++i) multiplier *= q;
                if (bit(m * multiplier) <= bits - 1) {
                    m *= multiplier;
                    coef.push_back({q, a});
                }
            }
        }
        if (bit(m) == bits - 1) isDone = 0;
    }
    return m;
}
unsigned long long mod(unsigned long long base, unsigned long long power, unsigned long long modulo) {
    base %= modulo;
    unsigned long long res = 1;
    while (power > 0) {
        if (power % 2 == 1) res = (res * base) % modulo;
        base = (base * base) % modulo;
        power /= 2;
    }
    return res;
}
bool generatePrime(int bits, int t, unsigned long long& prime, int& rejected,
                   const std::vector<int>& simple) {
    rejected = 0;
    std::vector<std::pair<int, int>> coef;
    unsigned long long m, n;
    while (true) {
        m = generate(bits, simple, coef);
        n = 2 * m + 1;
        if (bit(n) != bits) {
            rejected++;
            continue;
        }
        std::vector<int> Q;
        Q.push_back(2);
        for (size_t i = 0; i < coef.size(); ++i) Q.push_back(coef[i].first);
        if (millerTest(n, Q, t) != 2) {
            rejected++;
            continue;
        }
        if (millerTest(n, Q, 2) == 2) {
            prime = n;
            return true;
        } else
            rejected++;
    }
}
int millerTest(unsigned long long n, std::vector<int> Q, int t) {
    if (n < 2) return 1;
    if (n == 2) return 2;
    unsigned long long nminus1 = n - 1;
    std::vector<unsigned long long> avals;
    std::vector<unsigned long long> useda;
    for (int i = 0; i < t; ++i) {
        unsigned long long a;
        bool already;
        while (true) {
            a = 2 + (std::rand() % (n - 3));
            already = false;
            for (unsigned long long u : useda)
                if (u == a) already = true;
            if (!already) break;
        }
        useda.push_back(a);
        avals.push_back(a);
    }
    for (unsigned long long a : avals)
        if (mod(a, nminus1, n) != 1) return 1;
    for (int q : Q) {
        unsigned long long exp = nminus1 / q;
        bool allone = true;
        for (unsigned long long a : avals)
            if (mod(a, exp, n) != 1) {
                allone = false;
                break;
            }
        if (allone) return 1;
    }
    return 2;
}
