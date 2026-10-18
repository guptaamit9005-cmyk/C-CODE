
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1) {
        stack[++top] = ch;
    }
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main() {
    char exp[MAX];
    int i, balanced = 1;

    printf("Enter an expression: ");
    fgets(exp, MAX, stdin);

    for (i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            if (top == MAX - 1) {
                balanced = 0;
                break;
            }
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            char open = pop();

            if (open == '\0' || !isMatching(open, ch)) {
                balanced = 0;
                break;
            }
        }
    }

    if (top != -1) {
        balanced = 0;
    }

    if (balanced) {
        printf("Parentheses are Balanced.\n");
    } else {
        printf("Parentheses are Not Balanced.\n");
    }

    return 0;
}
