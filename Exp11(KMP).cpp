#include <stdio.h>
#include <string.h>

void ComputePrefixFunction(char P[], int m, int pi[])
{
    int i, k;

    pi[1] = 0;
    k = 0;

    for (i = 2; i <= m; i++)
    {
        while (k > 0 && P[k + 1] != P[i])
            k = pi[k];

        if (P[k + 1] == P[i])
            k = k + 1;

        pi[i] = k;
    }

     // Print Prefix Table
    printf("\nPrefix Table:\n");

    for (i = 1; i <= m; i++)
    {
        printf("%d ", pi[i]);
    }

    printf("\n");
}

void KMP_Matcher(char T[], char P[])
{
    int n, m;
    int pi[100];
    int i, q;

    n = strlen(T) - 1;
    m = strlen(P) - 1;

    ComputePrefixFunction(P, m, pi);

    q = 0;

    for (i = 1; i <= n; i++)
    {
        while (q > 0 && P[q + 1] != T[i])
            q = pi[q];

        if (P[q + 1] == T[i])
            q = q + 1;

        if (q == m)
        {
            printf("Pattern occurs with shift %d\n", i - m);
            q = pi[q];
        }
    }
}

int main()
{
    char T[100], P[100];
    char text[100], pattern[100];

    printf("Enter Text: ");
    scanf(" %[^\n]", text);

    printf("Enter Pattern: ");
    scanf(" %[^\n]", pattern);

    // Store from index 1
    strcpy(T + 1, text);
    strcpy(P + 1, pattern);

    KMP_Matcher(T, P);

    return 0;
}