#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int compute(char symbol, int op1, int op2)
{
    switch (symbol)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;

    case '/':
        return op1 / op2;
    case '%':
        return (op1) % (op2);
    case '^':
        return pow(op1, op2);
    }
}
int main()
{
    float s[20];
    float res;
    float op1;
    float op2;
    int top;
    int i;
    char postfix[20];
    char symbol;
    printf("Enter the postfix expression\n");
    scanf("%s", postfix);
    top = -1;
    for (i = 0; i < strlen(postfix); i++)
    {
        symbol = postfix[i];
        if (isdigit(symbol))
            s[++top] = symbol - '0';
        else
        {
            op2 = s[top--];
            op1 = s[top--];
            res = compute(symbol, op1, op2);
            s[++top] = res;
        }
    }
    res = s[top--];
    printf("the result is %f\n", res);
    return 0;
}