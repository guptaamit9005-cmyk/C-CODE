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
        printf("Memory Full\n");
        return;
    }

    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

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

    printf("Element inserted\n");
}

void delete() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node *temp = front;

    printf("Deleted element: %d\n", temp->data);

    front = front->next;
    free(temp);
}

void display() {
    struct Node *temp = front;

    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("Data: %d, Priority: %d\n",
               temp->data, temp->priority);
        temp = temp->next;
    }
}

int main() {
    insert(10, 2);
    insert(20, 1);
    insert(30, 3);

    printf("Priority Queue:\n");
    display();

    delete();

    printf("After deletion:\n");
    display();

    return 0;
}