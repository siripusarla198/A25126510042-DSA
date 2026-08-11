/*An expression-processing application receives an arithmetic expression in infix form. Write a C
program using a stack to convert it to postfix form while correctly handling parentheses and
operator precedence for +, -, *, / and ^. Test the program using an expression containing multiple
operators and parentheses.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int prec(char c){
    if(c=='^')
        return 3;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='+' || c=='-')
        return 1;
    else
        return -1;
}
int infixToPostfix(char* exp, char* output) {
    int k = 0; 
    char stack[100]; 
    int top = -1; 
    for (int i = 0; exp[i]; i++) {
        if (isalnum(exp[i])) {
            output[k++] = exp[i];
        } else if (exp[i] == '(') {
            stack[++top] = exp[i];
        } else if (exp[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                output[k++] = stack[top--];
            }
            if (top != -1 && stack[top] == '(')
                top--; 
        } else {
            while (top != -1 && prec(stack[top]) >= prec(exp[i])) {
                output[k++] = stack[top--];
            }
            stack[++top] = exp[i];
        }
    }

    while (top != -1) {
        output[k++] = stack[top--];
    }
    output[k] = '\0'; 
    printf("Postfix Expression: %s\n", output);
    return 0;
}
int main() {
    char exp[100], output[100];
    printf("Enter an infix expression: ");
    scanf("%s", exp);
    infixToPostfix(exp, output);
    return 0;
}