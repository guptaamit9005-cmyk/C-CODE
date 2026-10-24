#include<stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(){
    int value;

    if(top == MAX-1){
        printf("Stack Overflow\n");
    }else{
        printf("Enter value:");
        scanf("%d", &value);
        
    }
}