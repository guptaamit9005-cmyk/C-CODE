
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Invalid Expression!\n");
        exit(1);
    }
    return stack[top--];
}

int main() {
    char exp[MAX];
    int i = 0, a, b;

    printf("Enter postfix expression: ");
    fgets(exp, MAX, stdin);

    while (exp[i] != '\0') {
        if (isspace((unsigned char)exp[i])) {
            i++;
            continue;
        }

        if (isdigit((unsigned char)exp[i])) {
            int num = 0;

            while (isdigit((unsigned char)exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
            continue;
        }

        if (exp[i] == '+' || exp[i] == '-' ||
            exp[i] == '*' || exp[i] == '/') {

            b = pop();
            a = pop();

            switch (exp[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;

                case '/':
                    if (b == 0) {
                        printf("Division by zero!\n");
                        return 1;
                    }
                    push(a / b);
                    break;
            }
        } else {
            printf("Invalid character!\n");
            return 1;
        }

        i++;
    }

    if (top != 0) {
        printf("Invalid Expression!\n");
    } else {
        printf("Result = %d\n", pop());
    }

    return 0;
}
