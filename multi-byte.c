#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

int main(void)
{
    char* hmm = "äömarcelo módolo";
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
