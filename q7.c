#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void reverseString() {
    char str[MAX];
    top = -1;

    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
        push(str[i]);

    for (int i = 0; str[i] != '\0'; i++)
        str[i] = pop();

    printf("%s\n", str);
}

int isMatching(char a, char b) {
    if (a == '(' && b == ')') return 1;
    if (a == '{' && b == '}') return 1;
    if (a == '[' && b == ']') return 1;
    return 0;
}

void checkBalanced() {
    char exp[MAX];
    top = -1;

    scanf("%s", exp);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (isEmpty() || !isMatching(pop(), exp[i])) {
                printf("Not Balanced\n");
                return;
            }
        }
    }

    if (isEmpty())
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
}

int main() {
    int choice;

    while (1) {
        printf("1 Reverse String\n");
        printf("2 Check Balanced Brackets\n");
        printf("3 Exit\n");
        scanf("%d", &choice);

        if (choice == 1)
            reverseString();
        else if (choice == 2)
            checkBalanced();
        else
            break;
    }

    return 0;
}
