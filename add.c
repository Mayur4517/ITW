#include <stdio.h>

int main()
{
    int a, b;
    printf("Enter two numbers :");
    scanf("%d%d", &a, &b);
    printf("%d", a + b);

    void print()
    {
        printf("Hello World");
    }
    void multiply(int A, int B)
    {
        int z;
        z = A * B;
        printf("Multiplication of Two Numbers : %d", z);
    }
}