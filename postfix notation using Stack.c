#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

// Stack structure to store operands
struct Stack {
    int items[MAX];
    int top;
};

// Stack operations
void push(struct Stack* s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int pop(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char* exp) {
    struct Stack s;
    s.top = -1;
    int i;

    // Scan all characters in the expression
    for (i = 0; exp[i] != '\0'; i++) {
        // If the character is a digit, push it to the stack
        if (isdigit(exp[i])) {
            push(&s, exp[i] - '0');  // Convert char to int by subtracting '0'
        }
        // If the character is an operator, pop two operands, apply the operator, and push the result
        else {
            int val1 = pop(&s);
            int val2 = pop(&s);

            switch (exp[i]) {
                case '+': push(&s, val2 + val1); break;
                case '-': push(&s, val2 - val1); break;
                case '*': push(&s, val2 * val1); break;
                case '/': push(&s, val2 / val1); break;
            }
        }
    }
    
    // The final result is the remaining item in the stack
    return pop(&s);
}

// Driver function
int main() {
    char exp[MAX];
    
    printf("Enter a postfix expression (with single-digit operands): ");
    gets(exp);

    int result = evaluatePostfix(exp);
    printf("Result of the postfix expression: %d\n", result);

    return 0;
}
