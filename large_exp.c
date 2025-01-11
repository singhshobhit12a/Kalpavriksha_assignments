#include <stdio.h>

long long calculate(long long base, long long exp, long long mod) {
    long long answer = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            answer = (answer * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }

    return answer;
}

int main() {
    long long base, exp, mod;
    printf("Enter expression as base, exponent and mod ");
    scanf("%lld %lld %lld", &base, &exp, &mod);

    printf("Result: %lld\n", calculate(base, exp, mod));

    return 0;
}
