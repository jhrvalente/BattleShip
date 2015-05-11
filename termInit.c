#include <stdio.h>
#include <string.h>

char termInitData[] = {
    145, 145, 145, 145, 145, 145, 145, 145, 132, 128, 128, 136, 136, 136, 136,
    136, 136, 136, 136, 128, 136, 136, 136, 136, 136, 136, 132, 132, 132, 132,
    132, 132, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 132,
    128, 145, 132, 128, 145, 145, 132, 132, 132, 132, 132, 145, 128, 132, 132,
    132, 132, 132, 132, 128, 128, 128, 132, 132, 145, 128, 132, 145, 145, 145,
    145, 145, 145, 145, 145, 132, 128, 145, 145, 128, 145, 132, 132, 128, 145,
    145, 145, 145, 145, 128, 136, 132, 145, 145, 145, 132, 128, 128, 128, 128,
    132, 128, 128, 145, 145, 136, 145, 145, 145, 145, 145, 145, 132, 128, 145,
    145, 145, 145, 132, 128, 145, 132, 136, 136, 136, 128, 128, 132, 145, 128,
    145, 145, 136, 145, 132, 132, 132, 132, 132, 145, 145, 132, 132, 136, 132,
    145, 145, 145, 132, 128, 145, 145, 132, 128, 128, 132, 145, 145, 128, 128,
    145, 132, 128, 128, 128, 136, 136, 145, 145, 145, 136, 136, 128, 128, 128,
    145, 128, 128, 145, 128, 128, 128, 136, 136, 132, 136, 145, 145, 132, 128,
    145, 132, 132, 145, 128, 128, 145, 128, 128, 145, 145, 132, 145, 132, 132,
    145, 145, 145, 145, 136, 132, 145, 145, 132, 132, 128, 128, 128, 136, 132,
    145, 136, 136, 136, 145, 145, 136, 145, 128, 136, 145, 128, 136, 132, 132,
    132, 132, 132, 128, 145, 136, 145, 132, 132, 132, 145, 145, 145, 128, 136,
    136, 132, 145, 145, 145, 132, 145, 145, 132, 136, 136, 136, 145, 145, 145,
    128, 145, 145, 136, 132, 132, 136, 145, 145, 128, 128, 128, 136, 132, 132,
    145, 145, 128, 145, 128, 128, 128, 128, 145, 145, 132, 132, 128, 128, 136,
    145, 136, 128, 145, 145, 128, 132, 145, 145, 145, 145, 145, 128, 132, 128,
    136, 128, 136, 132, 132, 136, 132, 145, 128, 128, 136, 128, 128, 136, 128,
    128, 128, 136, 145, 132, 136, 136, 136, 136, 128, 145, 145, 145, 145, 128,
    132, 145, 145, 145, 145, 145, 132, 128, 136, 132, 145, 128, 136, 136, 136,
    136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136,
    136, 136, 145, 145, 145, 145, 145, 145, 145, 128, 132, 132, 145, 145, 145,
    128, 132, 128, 128, 132, 136, 145, 145, 145, 145, 145, 136, 145, 145, 136,
    145, 145, 136, 145, 136, 145, 132, 128, 145, 136, 132, 145, 145, 145, 145,
    145, 145, 145, 145, 145, 128, 132, 145, 145, 145, 128, 132, 132, 145, 128,
    128, 132, 132, 136, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 132,
    145, 145, 145, 136, 132, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
    128, 128, 132, 132, 145, 145, 128, 128, 132, 132, 145, 145, 145, 132, 132,
    132, 132, 132, 132, 132, 145, 128, 132, 132, 145, 145, 145, 136, 145, 145,
    145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 128, 128, 128,
    132, 132, 132, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
    128, 145, 145, 132, 128, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
    145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 128, 128, 132, 132,
    132, 132, 132, 132, 132, 132, 132, 132, 132, 132, 128, 145, 145, 145, 145,
    132, 132, 132, 145, 145, 132, 132, 132, 132, 145, 145, 145, 132, 132, 132,
    145, 145, 132, 132, 132, 132, 145, 145, 132, 132, 145, 145, 145, 132, 132,
    132, 145, 132, 132, 145, 145, 145, 132, 136, 145, 136, 136, 145, 136, 136,
    145, 136, 136, 145, 136, 136, 145, 136, 136, 145, 136, 136, 132, 136, 128,
    145, 136, 136, 145, 145, 145, 136, 136, 132, 145, 136, 136, 136, 132, 136,
    136, 136, 128, 128, 145, 145, 136, 136, 128, 136, 132, 145, 136, 136, 145,
    136, 136, 145, 136, 136, 145, 136, 136, 145, 136, 136, 145, 145, 145, 136,
    136, 128, 145, 136, 136, 128, 136, 128, 136, 136, 145, 145, 145, 145, 136,
    136, 145, 136, 136, 145, 128, 136, 132, 136, 128, 145, 136, 136, 136, 136,
    128, 145, 136, 136, 136, 136, 145, 136, 136, 136, 145, 136, 136, 145, 145,
    145, 136, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
    145, 145, 145, 145, 145, 145, 132, 132, 132, 132, 145, 145, 145, 145, 145,
    145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
    145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 132, 136, 136, 136,
    128, 128, 128, 136, 136, 132, 145, 145, 145, 145, 145, 145, 145, 145, 145,
    145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
    145, 145, 145, 145, 136, 136, 136, 145, 145, 145, 145, 145, 136, 136, 136,
    145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
    145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
    145, 132, 132, 132, 136, 136, 128, 145, 145, 145, 145, 145, 145, 145, 145,
    145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
    145, 145, 145, 145, 145, 145, 145, 145, 136, 136, 128, 128, 145, 145, 145,
    145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
    145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
    145, 136, 136, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
    145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
    145, 145, 145, 145, 145, 145, 145, 145, 145, 132, 132, 145, 145, 145, 145,
    145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
    145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
    145, 145, 128, 128, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145, 145,
    145, 145, 145, 145, 145, 145
};

void initTerm(void)
{
int i, j, k;

    for (i=0; i<27; i++)
    {
        for (j=0; j<38; j++) printf("\xe2\x96%c", termInitData[38*i + j]);
        printf("\n");
    }

}
