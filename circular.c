
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

     if (head == NULL) {
        head = n;
        n->next = head;
    } else {
        t = head;
        while (t->next != head)
            t = t->next;
        t->next = n;
        n->next = head;
    }
}

void display() {
    struct node *t = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    do {
        printf("%d -> ", t->data);
        t = t->next;
    } while (t != head);
    printf("(back to head)\n");
}

void delete_node() {
    struct node *t = head, *p = NULL;
    int x;
    printf("Enter value to delete: ");
    scanf("%d", &x);

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    do {
        if (t->data == x)
            break;
        p = t;
        t = t->next;
    } while (t != head);

    if (t->data != x) {
        printf("Not found\n");
        return;
    }

    if (t->next == head && t == head)
        head = NULL;
    else {
        if (t == head) {
            struct node *last = head;
            while (last->next != head)
                last = last->next;
            head = head->next;
            last->next = head;
        } else {
            p->next = t->next;
        }
    }
    free(t);
}

void search() {
    struct node *t = head;
    int x, pos = 1;
    printf("Enter value: ");
    scanf("%d", &x);

    if (head != NULL) {
        do {
            if (t->data == x) {
                printf("Found at position %d\n", pos);
                return;
            }
            t = t->next;
            pos++;
        } while (t != head);
    }
    printf("Not found\n");
}

void count() {
    struct node *t = head;
    int c = 0;
    if (head != NULL) {
        do {
            c++;
            t = t->next;
        } while (t != head);
    }
    printf("Total nodes = %d\n", c);
}

int main() {
    int ch;
    do {
        printf("\n1.Insert 2.Display 3.Delete");
        printf("\n4.Search 5.Count 0.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: delete_node(); break;
            case 4: search(); break;
            case 5: count(); break;
        }
    } while (ch != 0);

    return 0;
}
 