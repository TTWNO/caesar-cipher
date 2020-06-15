default: all

caesar:
	$(CC) -o caesar caesar.c common.c

decaesar:
	$(CC) -DDECAESAR -o decaesar caesar.c common.c

test:
	$(CC) -o test test.c common.c

clean:
	rm decaesar caesar test

all: caesar decaesar
