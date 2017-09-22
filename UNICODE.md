Experimentando com UNICODE
==========================

Usando iconv e hexdump
---------------------------

```
$ printf "Módolo\n" | iconv -f utf-8 -t utf-16 | hexdump
0000000 feff 004d 00f3 0064 006f 006c 006f 000a
0000010

$ printf "Módolo\n" | iconv -f utf-8 -t utf-16 | hexdump -C
00000000  ff fe 4d 00 f3 00 64 00  6f 00 6c 00 6f 00 0a 00  |..M...d.o.l.o...|
00000010

```

how to get hexdump of a structure data <https://stackoverflow.com/questions/7775991/how-to-get-hexdump-of-a-structure-data>
```
#include <stdio.h>

void hexDump (char *desc, void *addr, int len) {
    int i;
    unsigned char buff[17];
    unsigned char *pc = (unsigned char*)addr;

    // Output description if given.
    if (desc != NULL)
        printf ("%s:\n", desc);

    if (len == 0) {
        printf("  ZERO LENGTH\n");
        return;
    }
    if (len < 0) {
        printf("  NEGATIVE LENGTH: %i\n",len);
        return;
    }

    // Process every byte in the data.
    for (i = 0; i < len; i++) {
        // Multiple of 16 means new line (with line offset).

        if ((i % 16) == 0) {
            // Just don't print ASCII for the zeroth line.
            if (i != 0)
                printf ("  %s\n", buff);

            // Output the offset.
            printf ("  %04x ", i);
        }

        // Now the hex code for the specific character.
        printf (" %02x", pc[i]);

        // And store a printable ASCII character for later.
        if ((pc[i] < 0x20) || (pc[i] > 0x7e))
            buff[i % 16] = '.';
        else
            buff[i % 16] = pc[i];
        buff[(i % 16) + 1] = '\0';
    }

    // Pad out last line if not exactly 16 characters.
    while ((i % 16) != 0) {
        printf ("   ");
        i++;
    }

    // And print the final ASCII bit.
    printf ("  %s\n", buff);
}

int main (int argc, char *argv[]) {
    char my_str[] = "a char string greater than 16 chars";
    hexDump ("my_str", &my_str, sizeof (my_str));
    return 0;
}
```

iterating through a char array with non standard chars <https://stackoverflow.com/questions/14083706/iterating-through-a-char-array-with-non-standard-chars>

```
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(void)
{
    char* hmm = "äö";
    int off = 0;
    int len;
    int max = strlen(hmm);

    setlocale(LC_ALL, "");

    printf("<<%s>>\n", hmm);
    printf("%zi\n", strlen(hmm));

    while (hmm[off] != '\0' && (len = mblen(&hmm[off], max - off)) > 0)
    {
        printf("<<%.*s>>\n", len, &hmm[off]);
        off += len;
    }

    return 0;
}
```

Referências
===========

Why is hexdump of UTF-16 string when passed in as a command line argument different from what it is directly on the terminal? <https://stackoverflow.com/questions/21058436/why-is-hexdump-of-utf-16-string-when-passed-in-as-a-command-line-argument-differ>

Unicode in C and C++: What You Can Do About It Today <https://www.cprogramming.com/tutorial/unicode.html>

C: Using scanf and wchar_t to read and print UTF-8 strings <https://linuxprograms.wordpress.com/2012/05/12/using-scanf-and-wchar_t-to-read-and-print-utf-8-strings/>

Converting Multibyte and Wide Character Strings <https://www.gnu.org/software/libc/manual/html_node/Converting-Strings.html#Converting-Strings>

GNU libunistring <https://www.gnu.org/software/libunistring/manual/libunistring.html#Top>

iterating through a char array with non standard chars <https://stackoverflow.com/questions/14083706/iterating-through-a-char-array-with-non-standard-chars>

MBSTOWCS(3) <http://man7.org/linux/man-pages/man3/mbstowcs.3.html>
