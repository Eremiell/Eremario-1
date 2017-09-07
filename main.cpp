#include <iostream>
#include <chrono>
#include <random>

int main() {
	std::mt19937_64 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> dist(0, 100);
	int secret = dist(mt);
	bool guessed = false;
	while (!guessed) {
		std::cout << "Guess a number from 0 to 100: ";
		int guess;
		std::cin >> guess;
		if (guess == secret) {
			std::cout << "RIGHT!\n";
			guessed = true;
		}
		else if (guess > secret) {
			std::cout << "LOWER!\n";
		}
		else {
			std::cout << "GREATER!\n";
		}
	}
	return 0;
}