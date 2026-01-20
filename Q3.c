#include <stdio.h>

#define MAX 10

int stack[MAX];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

void push(int val) {
    if (!isFull()) {
        stack[++top] = val;
    }
}

int pop() {
    if (!isEmpty()) {
        return stack[top--];
    }
    return -1;
}

void display() {
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    printf("%d\n", pop());
    printf("%d\n", isEmpty());
    printf("%d\n", isFull());

    return 0;
}
