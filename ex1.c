#include <stdio.h>

/* This is a comment. */
int main(/*@unused@*/ int argc, /*@unused@*/ char *argv[]) {
#pragma unused (argc)
#pragma unused (argv)

	int distance = 100;

	// this is also a comment
	printf("You are %d miles away.\n", distance);

	return 0;
}
