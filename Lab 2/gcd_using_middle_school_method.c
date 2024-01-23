#include <stdio.h>
#include <math.h>

int isPrime(int n, int *opCount) {
	for (int j = 2; j <= n/2; j++) {
		if (n % j == 0) {
			return 0;
		}
	}
	return 1;
}

int gcd(int m, int n, int *opCount) {
	int min = m < n ? m : n;

	int prodPrimes = 1;
	for (int i=1; i<=min; i++) {
		(*opCount)++;
		if (m % i == 0 && n % i == 0 && isPrime(i, opCount)) {
			prodPrimes *= i;
		}
	}
	return prodPrimes;
}

int main() {
	int opCount = 0;
	printf("Enter numbers for gcd\n");
	int m, n;
	scanf("%d%d", &m, &n);
	printf("%d\n", gcd(m, n, &opCount));
	printf("Opcount: %d\n", opCount);
}







// int primes1[m], c = 0;
	// int primes2[n], d = 0;
	// int isPrime;
	// int i=0, j=0;

	// for (i = 2; i < m; i++) {
	// 	isPrime = 1;
	// 	for (j = 2; j < i/2; j++) {
	// 		if (i % j == 0 && i != j) {
	// 			isPrime = 0;
	// 			break;
	// 		}
	// 	}
	// 	printf("%d\n", isPrime);
	// 	if (isPrime && m % i == 0) {
	// 		printf("c: %d\n", c);
	// 		primes1[c++] = i;
	// 	}
	// }

	// for (i = 1; i < n; i++) {
	// 	isPrime = 1;
	// 	for (j = 2; j < i/2; j++) {
	// 		if (i % j == 0 && i != j) {
	// 			isPrime = 0;
	// 			break;
	// 		}
	// 	}
	// 	if (isPrime && n % i == 0) {
	// 		primes2[d++] = i;
	// 	}
	// }

	// int prodPrimes = 1;
	// i = 0, j = 0;
	// while (i < c && j < d) {
	// 	(*opCount)++;
	// 	if (primes1[i] == primes2[j]) {
	// 		prodPrimes *= primes1[i];
	// 		i++;
	// 		j++;
	// 	} else if (primes1[i] > primes2[j]) {
	// 		j++;
	// 	} else {
	// 		i++;
	// 	}
	// }
	// for (i=0; i<c; i++) {
	// 	printf("%d ", primes1[i]);
	// }
	// printf("\n");
	// for (i=0; i<d; i++) {
	// 	printf("%d ", primes2[i]);
	// }
	// printf("\n");
	// return prodPrimes;