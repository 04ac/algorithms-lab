#include <stdio.h>
#include <math.h>

int gcd(int m, int n, int *opCount) {
	int t = m < n ? m : n;

	while (t > 0) {
		(*opCount)++;
		if (m % t == 0 && n % t == 0) {
			return t;
		}
		t--;
	}
}

int main() {
	int opCount = 0;
	printf("%d\n", gcd(1033, 2097, &opCount));
	printf("Opcount: %d\n", opCount);
}
