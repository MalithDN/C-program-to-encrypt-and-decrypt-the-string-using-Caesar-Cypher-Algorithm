#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

// Function prototypes
int is_prime(int num);
long long gcd(long long a, long long b);
long long mod_inverse(long long e, long long phi);
long long mod_pow(long long base, long long exp, long long mod);
void encrypt(char* msg, long long e, long long n, long long* encrypted);
void decrypt(long long* encrypted, int len, long long d, long long n, char* decrypted);

int main() {
    int p, q;
    char msg[MAX];
    long long n, phi, e, d;
    long long encrypted[MAX];
    char decrypted[MAX];

    // Input prime numbers
    printf("Enter first prime number: ");
    scanf("%d", &p);
    if (!is_prime(p)) {
        printf("Invalid prime number.\n");
        return 1;
    }

    printf("Enter second prime number: ");
    scanf("%d", &q);
    if (!is_prime(q) || p == q) {
        printf("Invalid prime number or both primes are equal.\n");
        return 1;
    }

    getchar(); // Clear newline from buffer

    // Input message
    printf("Enter message to encrypt: ");
    fgets(msg, sizeof(msg), stdin);
    msg[strcspn(msg, "\n")] = '\0'; // Remove newline

    n = (long long)p * q;
    phi = (long long)(p - 1) * (q - 1);

    // Choose public key `e`
    e = 3;
    while (gcd(e, phi) != 1) {
        e++;
    }

    // Calculate private key `d`
    d = mod_inverse(e, phi);
    if (d == -1) {
        printf("Modular inverse could not be found.\n");
        return 1;
    }

    printf("\nPublic Key (e, n): (%lld, %lld)\n", e, n);
    printf("Private Key (d, n): (%lld, %lld)\n", d, n);

    // Encrypt
    encrypt(msg, e, n, encrypted);
    printf("\nEncrypted message:\n");
    for (int i = 0; i < strlen(msg); i++) {
        printf("%lld ", encrypted[i]);
    }

    // Decrypt
    decrypt(encrypted, strlen(msg), d, n, decrypted);
    printf("\n\nDecrypted message:\n%s\n", decrypted);

    return 0;
}

// Check if number is prime
int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Compute GCD
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Compute Modular Inverse using Extended Euclidean Algorithm
long long mod_inverse(long long e, long long phi) {
    long long t = 0, newt = 1;
    long long r = phi, newr = e;
    while (newr != 0) {
        long long quotient = r / newr;
        long long temp = newt;
        newt = t - quotient * newt;
        t = temp;

        temp = newr;
        newr = r - quotient * newr;
        r = temp;
    }
    if (r > 1) return -1;
    if (t < 0) t += phi;
    return t;
}

// Fast Modular Exponentiation
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Encrypt message
void encrypt(char* msg, long long e, long long n, long long* encrypted) {
    for (int i = 0; i < strlen(msg); i++) {
        encrypted[i] = mod_pow((long long)msg[i], e, n);
    }
}

// Decrypt message
void decrypt(long long* encrypted, int len, long long d, long long n, char* decrypted) {
    for (int i = 0; i < len; i++) {
        decrypted[i] = (char)mod_pow(encrypted[i], d, n);
    }
    decrypted[len] = '\0';
}
