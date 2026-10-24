
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

void insert() {
    struct node *n, *t;
    n = malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &n->data);
    n->next = NULL;
    n->prev = NULL;

    if (head == NULL)
        head = n;
    else {
        t = head;
        while (t->next)
            t = t->next;
        t->next = n;
        n->prev = t;
    }
}

void display() {
    struct node *t = head;
    while (t) {
        printf("%d <-> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

void delete_node() {
    struct node *t = head;
    int x;
    printf("Enter value: ");
    scanf("%d", &x);

    while (t && t->data != x)
        t = t->next;

    if (!t) {
        printf("Not found\n");
        return;
    }

    if (t->prev)
        t->prev->next = t->next;
    else
        head = t->next;

    if (t->next)
        t->next->prev = t->prev;

    free(t);
}

void search() {
    struct node *t = head;
    int x, p = 1;
    printf("Enter value: ");
    scanf("%d", &x);

    while (t) {
        if (t->data == x) {
            printf("Found at position %d\n", p);
            return;
        }
        t = t->next;
        p++;
    }
    printf("Not found\n");
}

void count() {
    struct node *t = head;
    int c = 0;
    while (t) {
        c++;
        t = t->next;
    }
    printf("Count = %d\n", c);
}

void reverse() {
    struct node *t = head;
    if (!t) return;

    while (t->next)
        t = t->next;

    while (t) {
        printf("%d <-> ", t->data);
        t = t->prev;
    }
    printf("NULL\n");
}

int main() {
    int ch;
    do {
        printf("\n1.Insert 2.Display 3.Delete");
        printf("\n4.Search 5.Count 6.Reverse 0.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: delete_node(); break;
            case 4: search(); break;
            case 5: count(); break;
            case 6: reverse(); break;
        }
    } while (ch != 0);

    return 0;
}
 