#include <stdio.h>
int  main(int argc, char** argv)
{
    char ch;
    int c, f, a = 10, b = 20; //new variable called c to use it in the for loop

    for (c = 0; c < 5; ++c) {
        scanf(" %c", &ch); //a space before %c to let the scanf works for every loop.
        printf("ch = %c\n", ch);
        switch (ch) {
            case '+': f = a + b; printf("f = %d\n", f);
                break; //added break so it can break everytime the the case been called.
            case '-': f = a - b; printf("f = %d\n", f);
                break; //added break so it can break everytime the the case been called.
            case '*': f = a * b; printf("f = %d\n", f);
                break; //added break so it can break everytime the the case been called.
            case '/': f = a / b; printf("f = %d\n", f);
                break; //added break so it can break everytime the the case been called.
            default: printf("invalid operator\n");
        }
    }
}