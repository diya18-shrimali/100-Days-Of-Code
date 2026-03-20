#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

int isEmpty() {
    return top == -1;
}

void push(char c) {
    if (top == MAX - 1) return; // overflow protection
    stack[++top] = c;
}

char pop() {
    if (isEmpty()) return -1; // underflow protection
    return stack[top--];
}

char peek() {
    if (isEmpty()) return -1;
    return stack[top];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixToPostfix(char* infix) {
    char postfix[MAX];
    int k = 0;

    for (int i = 0; infix[i]; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[k++] = c;
        } 
        else if (c == '(') {
            push(c);
        } 
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        } 
        else {
            while (!isEmpty() &&
                  (precedence(peek()) > precedence(c) ||
                  (precedence(peek()) == precedence(c) && c != '^'))) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    while (!isEmpty()) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
    printf("%s\n", postfix);
}

int main() {
    char infix[MAX];
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}