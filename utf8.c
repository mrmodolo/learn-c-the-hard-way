#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include<stdlib.h>

int main(int argc, char *argv[]) 
{
#pragma unused(argc)
	setlocale(LC_ALL, "");
	printf("%s\n", argv[1]);
	return 0;
}
