
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

void insert() {
    struct Node *n, *t;
    int x;

    n = malloc(sizeof(struct Node));
    if (n == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &x);

    n->data = x;
    n->next = NULL;
    n->prev = NULL;

    if (head == NULL) {
        head = n;
    } else {
        t = head;
        while (t->next != NULL)
            t = t->next;

        t->next = n;
        n->prev = t;
    }
    printf("Inserted successfully.\n");
}

void display() {
    struct Node *t = head;

    if (t == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    while (t != NULL) {
        printf("%d <-> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

void deleteNode() {
    struct Node *t;
    int x;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &x);

    t = head;
    while (t != NULL && t->data != x)
        t = t->next;

    if (t == NULL) {
        printf("Value not found.\n");
        return;
    }

    if (t->prev != NULL)
        t->prev->next = t->next;
    else
        head = t->next;

    if (t->next != NULL)
        t->next->prev = t->prev;

    free(t);
    printf("Deleted successfully.\n");
}

void search() {
    struct Node *t = head;
    int x, pos = 1;

    printf("Enter value to search: ");
    scanf("%d", &x);

    while (t != NULL) {
        if (t->data == x) {
            printf("Found at position %d.\n", pos);
            return;
        }
        t = t->next;
        pos++;
    }

    printf("Value not found.\n");
}

void count() {
    struct Node *t = head;
    int c = 0;

    while (t != NULL) {
        c++;
        t = t->next;
    }

    printf("Total nodes = %d\n", c);
}

int main() {
    int ch;

    while (1) {
        printf("\n1.Insert  2.Display  3.Delete\n");
        printf("4.Search  5.Count  6.Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &ch) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (ch) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: deleteNode(); break;
            case 4: search(); break;
            case 5: count(); break;
            case 6:
                while (head != NULL) {
                    struct Node *t = head;
                    head = head->next;
                    free(t);
                }
                return 0;
            default: printf("Invalid choice.\n");
        }
    }
}
