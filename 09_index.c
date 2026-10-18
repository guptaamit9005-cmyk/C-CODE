
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert() {
    int value;
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Node inserted successfully.\n");
}

void deleteNode() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- SINGLY LINKED LIST ---\n");
        printf("1. Insert\n");
        printf("2. Delete (Beginning)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                deleteNode();
                break;

            case 3:
                display();
                break;

            case 4:
                while (head != NULL) {
                    struct Node *temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
