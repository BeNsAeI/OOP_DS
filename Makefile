src = main.cpp tree.cpp
test = test.cpp tree.cpp
obj = $(src:.c=.o)
compiler = g++
LDFLAGS = -Wall

all:
	make Test

compile: $(src)
	$(compiler) $(src) -o out.out $(LDFLAGS)
	./out.out

Test: $(src)
	$(compiler) $(test) -o test.out $(LDFLAGS)
	./test.out

clean:
	rm *.out
