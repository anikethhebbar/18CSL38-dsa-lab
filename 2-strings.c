#include <stdio.h>
char STR[100], PAT[100], REP[100], ANS[100];
int temp, s, p, r, a, flag = 0;
void read();
void replace();
void print();
int main()
{
    read();
    replace();
    print();
    return 0;
}
void read()
{
    printf("Enter Main String :\n ");
    scanf("%s", STR);
    printf("Enter Pattern String :\n ");
    scanf("%s", PAT);
    printf("Enter Replace String :\n ");
    scanf("%s", REP);
} 
void replace()
{
    temp = s = p = r = a = 0;
    while (STR[temp] != '\0')
    {
        if (STR[s] == PAT[p])
        {
            p++;
            s++;
            if (PAT[p] == '\0')
            {
                for (r = 0; REP[r] != '\0'; r++, a++)
                    ANS[a] = REP[r];
                flag = 1;
                p = 0;
                temp = s;
            }
        }
        else
        {
            ANS[a] = STR[temp];
            temp++;
            a++;
            s = temp;
            p = 0;
        }
    }
}
void print()
{
    if (flag == 0)
        printf("Pattern not found\n");
    else
    {
        ANS[a] = '\0';
        printf("The Resultant String is : \n %s \n", ANS);
    }
}