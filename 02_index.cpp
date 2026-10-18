
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into stack.\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }

    struct Node *temp = top;

    printf("%d popped from stack.\n", top->data);

    top = top->next;
    free(temp);
}

void display() {
    struct Node *temp = top;

    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements:\n");

    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- STACK USING LINKED LIST ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");

            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");

                if (scanf("%d", &value) != 1) {
                    printf("Invalid value!\n");

                    while (getchar() != '\n');
                    break;
                }

                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                while (top != NULL) {
                    struct Node *temp = top;
                    top = top->next;
                    free(temp);
                }

                printf("Program exited successfully.\n");
                return 0;

            default:
                printf("Invalid choice! Please choose 1-4.\n");
        }
    }

    return 0;
}
