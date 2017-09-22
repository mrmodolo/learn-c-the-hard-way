#include <stdio.h>
#include <ctype.h>

int valid_identifier_start(char ch)
{
	return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
			printf("ERROR: You need one argument.\n");
			// this is how you abort a program
			return 1;
	}

	char letter = '\0';

	for (int i = 0; letter = argv[1][i], letter != '\0'; i++) {

		if (! valid_identifier_start(letter)) {
			printf("%d: %d is not a vowel\n", i, (unsigned char)letter);
			continue;
		}

		if (islower(letter)) {
			letter = toupper(letter);
		}

		switch (letter) {
			case 'A':
				printf("%d: 'A'\n", i);
				break;

			case 'E':
				printf("%d: 'E'\n", i);
				break;

			case 'I':
				printf("%d: 'I'\n", i);
				break;

			case 'O':
				printf("%d: 'O'\n", i);
				break;

			case 'U':
				printf("%d: 'U'\n", i);
				break;

			case 'Y':
				if (i > 2) {
					// it's only sometimes Y
					printf("%d: 'Y'\n", i);
				}
				break;

			default:
				printf("%d: '%c' is not a vowel\n", i, letter);
		}
	}

	return 0;
}
