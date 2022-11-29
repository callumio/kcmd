# Do all
all: aasm jimulator kcmd

kcmd: src/kcmdSrc/kcmd.cpp
	g++ $^ -o bin/kcmd -std=c++17 -pthread

# Compile the jimulator binary.
jimulator: src/jimulatorSrc/jimulator.cpp
	g++ $^ -w -o bin/jimulator -Wall -Wextra -O3 -std=c++17

# Compile aasm binary.
aasm: src/aasmSrc/aasm.c
	gcc -w -O2 -o bin/aasm $^
	cp src/aasmSrc/mnemonics bin/mnemonics

clean:
	rm bin/{jimulator,aasm,kcmd,mnemonics}
