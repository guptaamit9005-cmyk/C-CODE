
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert() {
    struct node *n, *t;
    n = malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &n->data);
    n->next = NULL;

    if (head == NULL)
        head = n;
    else {
        t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = n;
    }
}

void display() {
    struct node *t = head;

    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

void count() {
    struct node *t = head;
    int c = 0;

    while (t != NULL) {
        c++;
        t = t->next;
    }

    printf("Total nodes = %d\n", c);
}

int main() {
    int ch;

    do {
        printf("\n1.Insert End 2.Display 5.Count 0.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert(); break;
            case 2: display(); break;
            case 5: count(); break;
        }
    } while (ch != 0);

    return 0;
}
