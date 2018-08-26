.PHONY: all

all: test.o minimal.o local-address.o

test.o: .inferconfig

%.o: %.c
	infer --quandary run -- clang -c $< -o $@
	
