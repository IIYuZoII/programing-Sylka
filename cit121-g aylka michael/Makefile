CC = clang
C_OPTS = -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla $(LAB_OPTS)

clean:
	rm -rf dist
prep:
	mkdir dist
compile: task1.bin task2.bin task3.bin

task1.bin: src/task1.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
task2.bin: src/task2.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
task3.bin: src/task3.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
run: clean prep compile
	./dist/task1.bin
doxygen:
	doxygen Doxyfile
check:
	clang-format --verbose -dry-run --Werror src/*
	cppcheck --enable=all --inconclusive --addon=cert --error-exitcode=1  -v --suppress=unreadVariable:*/task1.c --suppress=knownConditionTrueFalse:*/task1.c --check-config  --suppress=unmatchedSuppression:*/task1.c .

all: clean prep compile check

# TODO: clang-tidy; scan-build
