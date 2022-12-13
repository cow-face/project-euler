#include <iostream>
#include <sstream>
#include <algorithm>

int main() {
	const long max = 998001;
	int palindrome_base = 997;
	std::string palindrome_base_s = std::to_string(palindrome_base);


	for ( ; palindrome_base > 100; palindrome_base--) {
		palindrome_base_s = std::to_string(palindrome_base);
		std::string reversed(palindrome_base_s);
		std::reverse(reversed.begin(), reversed.end());
		std::string palindrome_s(palindrome_base_s);
		palindrome_s.insert(palindrome_s.end(), reversed.begin(), reversed.end());

		int palindrome = stoi(palindrome_s);
		for (int j = 999; j > 100; j--) {
			if (palindrome % j == 0 && std::to_string(palindrome/j).length() == 3) {
				std::cout << palindrome << std::endl;
				std::cout << j << std::endl;
				std::cout << palindrome/j << std::endl;
				return 0;
			}
		}

	}
}