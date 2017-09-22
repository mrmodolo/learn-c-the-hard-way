#include <stdio.h>
#include <wchar.h>

int main(int argc, char *argv[])
{
	if (argc > 1) {
		printf("%ls\n", (wchar_t *)argv[1]);
	}

	return 0;
}
