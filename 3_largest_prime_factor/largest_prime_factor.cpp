#include <iostream>
#include <vector>

bool is_prime(long n) {
	for(long i = 2; i < n; i++) {
		if ((n % i) == 0) {
			return false;
		}
	}
	return true;
}

std::vector<long> prime_factors(long n) {
	std::vector<long> factors;
	if (is_prime(n)) {
		factors.push_back(n);
		return factors;
	}
	else {
		for (long i = 2; i < n; i++) {
			if (n % i == 0) {
				std::vector<long> new_factors = prime_factors(i);
				std::vector<long> other_new_factors = prime_factors(n/i);
				factors.insert(factors.end(), new_factors.begin(), new_factors.end());
				factors.insert(factors.end(), other_new_factors.begin(), other_new_factors.end());
				return factors;
			}
		}
	}
}

int main(int argc, char* argv[]) {
	if (argc !=  2) {
		fprintf(stderr, "USAGE: %s number to be factored\n", argv[0]); exit(-1);
	}

	long input_num = std::stol(argv[1]);

	std::vector<long> p_factors = prime_factors(input_num);

	for (long i = 0; i < p_factors.size(); i++) {
		std::cout << p_factors[i] << std::endl;
	}

}

