
#include <stdio.h>
#define MAX 5

int q[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is Full!\n");
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX;
        q[rear] = x;
        printf("%d inserted\n", x);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is Empty!\n");
    } else {
        printf("%d deleted\n", q[front]);

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }

    int i = front;
    printf("Queue: ");

    while (1) {
        printf("%d ", q[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int ch, x;

    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
