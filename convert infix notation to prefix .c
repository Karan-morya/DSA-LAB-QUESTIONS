#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
struct Stack {
    int top;
    char items[MAX];
};

// Stack operations
void push(struct Stack* s, char x) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = x;
}

char pop(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

char peek(struct Stack* s) {
    if (s->top == -1) {
        return -1;
    }
    return s->items[s->top];
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Utility function to check if character is an operand
int isOperand(char ch) {
    return isalnum(ch);
}

// Utility function to return precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return 0;
}

// Utility function to reverse a string
void reverse(char* exp) {
    int length = strlen(exp);
    for (int i = 0; i < length / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[length - i - 1];
        exp[length - i - 1] = temp;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack s;
    s.top = -1;
    int k = 0;

    for (int i = 0; infix[i]; i++) {
        // If the character is an operand, add it to the result
        if (isOperand(infix[i])) {
            postfix[k++] = infix[i];
        }
        // If the character is '(', push it to the stack
        else if (infix[i] == '(') {
            push(&s, infix[i]);
        }
        // If the character is ')', pop and output from the stack until '(' is found
        else if (infix[i] == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s); // pop '('
        }
        // If the character is an operator
        else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(infix[i])) {
                postfix[k++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }

    // Pop all the remaining operators from the stack
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0'; // Null terminate the result
}

// Function to convert infix to prefix
void infixToPrefix(char* infix, char* prefix) {
    int length = strlen(infix);

    // Reverse the infix expression
    reverse(infix);

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < length; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    // Convert reversed infix to postfix
    char postfix[MAX];
    infixToPostfix(infix, postfix);

    // Reverse postfix to get prefix
    reverse(postfix);

    // Copy the result to the prefix array
    strcpy(prefix, postfix);
}

// Driver function
int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter the infix expression: ");
    gets(infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
