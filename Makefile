install:
	sudo apt install -y clang-format clang-tidy

uninstall:
	sudo apt remove -y clang-format clang-tidy

cppformat:
	clang-format -i *.cpp

hppformat:
	clang-format -i *.hpp

cpplint: cppformat
	clang-tidy --config-file=.clang-tidy --warnings-as-errors=* --quiet *.cpp -- -Wall -Wextra -Werror -std=c++98 
		
hpplint: hppformat
	clang-tidy --config-file=.clang-tidy --warnings-as-errors=* --quiet *.hpp -- -Wall -Wextra -Werror -std=c++98 

.PHONY: install uninstall cppformat hppformat cpplint hpplint
