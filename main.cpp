#include <iostream>
#include <chrono>
#include <random>
#include <limits>

int main() {
	std::mt19937_64 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> dist(0, 100);
	bool again = true;
	while (again) {
		int secret = dist(mt);
		bool guessed = false;
		int turns = 0;
		while (!guessed) {
			std::cout << "Guess a number from 0 to 100: ";
			int guess;
			std::cin >> guess;
			++turns;
			if (guess == secret) {
				std::cout << "RIGHT!\nIt took " << turns << " turns to guess the right number.\n";
				guessed = true;
			}
			else if (guess > secret) {
				std::cout << "LOWER!\n";
			}
			else {
				std::cout << "GREATER!\n";
			}
		}
		bool read = false;
		while (!read) {
			std::cout << "Play again (Y/N)? ";
			char input;
			std::cin >> input;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			switch (input) {
				case 'y':
				case 'Y':
					read = true;
					break;
				case 'n':
				case 'N':
					read = true;
					again = false;
					break;
				default:
					std::cout << "Wrong option selected: " << input << '\n';
					break;
			}
		}
	}
	return 0;
}