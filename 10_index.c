
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert() {
    struct Node *newNode, *temp;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    printf("Node inserted successfully.\n");
}

void deleteNode() {
    struct Node *temp, *last;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    if (head->next == head) {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    last = head;

    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;

    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void display() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(Back to Head)\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }

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
                while (head != NULL)
                    deleteNode();
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
