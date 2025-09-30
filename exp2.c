#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>   // for isalnum (checks if operand)
#include <string.h>

#define MAX 100

// Stack structure
char stack[MAX];
int top = -1;

// Stack functions
void push(char x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;
    }
}

char pop() {
    if (top == -1) {
        return -1;  // empty stack
    } else {
        return stack[top--];
    }
}

char peek() {
    if (top == -1) return -1;
    return stack[top];
}

// Function to define operator precedence
int precedence(char x) {
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int i, k = 0;
    char symbol;

    for (i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];

        // If operand → add to postfix
        if (isalnum(symbol)) {
            postfix[k++] = symbol;
        }
        // If '(' → push to stack
        else if (symbol == '(') {
            push(symbol);
        }
        // If ')' → pop until '('
        else if (symbol == ')') {
            while (peek() != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        // If operator
        else {
            while (peek() != -1 && precedence(peek()) >= precedence(symbol)) {
                postfix[k++] = pop();
            }
            push(symbol);
        }
    }

    // Pop remaining operators
    while (peek() != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0'; // end string
    printf("Postfix Expression: %s\n", postfix);
}

// Main
int main() {
    char infix[MAX];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
