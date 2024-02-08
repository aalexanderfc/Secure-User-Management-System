PROG = main
SRC = main.cpp 
CFLAGS = -g -std=c++20 -Wall -Wno-deprecated-declarations
LIBS = -L/opt/homebrew/opt/openssl@3/lib -lssl -lcrypto
INCLUDES = -I/opt/homebrew/opt/openssl@3/include
CC = g++
CPPCHECK = cppcheck

launch: all
	./$(PROG)

all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC) $(LIBS) $(INCLUDES)

clean:
	rm -f $(PROG)

.PHONY: all clean cppcheck

cppcheck:
	@$(CPPCHECK) --quiet --enable=all --error-exitcode=1 \
	--inline-suppr \
	$(SRC)
