CC=gcc
CFLAGS=-I.

# Object files
OBJ = main.o adduser.o showfiles.o viewfile.o updatefile.o

# Header dependencies
DEPS = adduser.h showfiles.h viewfile.h updatefile.h

# Rule for object files
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Linking
safe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# Clean the build
.PHONY: clean
clean:
	rm -f *.o *~ core safe

# Install the program
.PHONY: install
install: safe
	cp safe /usr/local/bin
	chmod +x /usr/local/bin/safe
