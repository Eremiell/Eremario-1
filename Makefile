#!/usr/bin/make -f

list:	list.cpp
	g++ -std=c++14 -O2 -Wall -Wextra -Wpedantic -olist list.cpp
bin:	main.cpp
	g++ -std=c++14 -O2 -Wall -Wextra -Wpedantic -oeremario-1 main.cpp
clang:	main.cpp
	g++ -std=c++14 -O2 -Wall -Wextra -Wpedantic -oeremario-1 main.cpp
clean:
	rm -f eremario-1
.PHONY:	bin	clang	clean