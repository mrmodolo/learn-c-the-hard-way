#include <stdio.h>

int main(int argc, char *argv[])
{
#pragma unused(argc)
#pragma unused(argv)
		int i = 24;
		while (i >= 0) {
				printf("%d\n", i);
				i--;
		}

		return 0;
}
