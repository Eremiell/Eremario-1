#include <iostream>
#include <limits>
#include <vector>
#include <string>

void view(std::vector<std::string> &list) {
	for (std::size_t i = 0; i < list.size(); ++i) {
		std::cout << '[' << (i + 1) << "] " << list.at(i) << '\n';
	}
	return;
}

void add(std::vector<std::string> &list) {
	std::cout << "Input item to add to list: ";
	std::string s;
	std::getline(std::cin, s);
	list.emplace_back(s);
	return;
}

void del(std::vector<std::string> &list) {
	view(list);
	std::cout << "Enter item number to delete: ";
	std::size_t item;
	std::cin >> item;
	if (item <= list.size() && item > 0) {
		list.erase(list.begin() + item - 1);
	}
	else {
		std::cout << "Wrong item number: " << item << "\n";
	}
	return;
}

int main() {
	std::vector<std::string> list;
	bool again = true;
	while (again) {
		bool read = false;
		while (!read) {
			std::cout << "Add[A]/Delete[D]/View[V]/Quit[Q]: ";
			char input;
			std::cin >> input;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			switch (input) {
				case 'a':
				case 'A':
					read = true;
					add(list);
					break;
				case 'd':
				case 'D':
					read = true;
					del(list);
					break;
				case 'v':
				case 'V':
					read = true;
					view(list);
					break;
				case 'q':
				case 'Q':
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