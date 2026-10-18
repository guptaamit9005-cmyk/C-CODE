
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data, priority;
    struct Node *next;
};

struct Node *front = NULL;

void insert(int data, int priority) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = data;
    newNode->priority = priority;

    if (front == NULL || priority < front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        struct Node *temp = front;

        while (temp->next != NULL &&
               temp->next->priority <= priority) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Element inserted successfully.\n");
}

void delete() {
    if (front == NULL) {
        printf("Priority Queue is empty!\n");
        return;
    }

    struct Node *temp = front;
    printf("Deleted element: %d\n", temp->data);

    front = front->next;
    free(temp);
}

void display() {
    struct Node *temp = front;

    if (front == NULL) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Data\tPriority\n");

    while (temp != NULL) {
        printf("%d\t%d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main() {
    int choice, data, priority;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);

                printf("Enter priority (1 = highest): ");
                scanf("%d", &priority);

                insert(data, priority);
                break;

            case 2:
                delete();
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
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
