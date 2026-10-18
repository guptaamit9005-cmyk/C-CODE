
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted into queue.\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow!\n");
        return;
    }

    struct Node *temp = front;

    printf("%d deleted from queue.\n", front->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void display() {
    struct Node *temp = front;

    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- QUEUE USING LINKED LIST ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
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

                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                while (front != NULL) {
                    struct Node *temp = front;
                    front = front->next;
                    free(temp);
                }

                rear = NULL;
                printf("Program exited successfully.\n");
                return 0;

            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    }

    return 0;
}
