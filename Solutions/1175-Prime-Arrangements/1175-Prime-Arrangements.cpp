
#include <iostream>
class Solution {
private:
	int isPrime(int n) {
		for (int j = 2; j < n; j++) {
			if (n % j == 0) {
				return 0;
			}
		}
		return 1;
	}
	int countPrime(int n) {
		int ret = 0;
		for (int i = 2; i <= n; i++) {
			if (isPrime(i)) {
				ret++;
			}
		}
		return ret;
	}

	long factorial(int n) {
		long ret = 1;
		for (int i = 1; i <= n; i++) {
			ret = (ret * i) % 1000000007;
		}
		return ret;
	}
public:
	int numPrimeArrangements(int n) {
		int count = countPrime(n);
		return (factorial(count) * factorial(n - count)) % 1000000007;
	}
};

int main()
{
    std::cout << "Hello World!\n";
}