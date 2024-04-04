#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 100
// declaring function
int isOperator(char ch);
int getPrecedence(char operator);
void infixToPostfix(char* infix, char* postfix);

int main(){
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE] = "";
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s", postfix);

    return 0;
}
// defing function
//function to check if th scanned ch is op
int isOperator(char ch){
    return(ch=='+' || ch=='-' || ch=='*' || ch=='/'|| ch=='%'|| ch=='^');
}
//check precedence of op
int getPrecedence(char operator){
    if(operator =='^')
        return 3;
    else if(operator =='*'|| operator =='/'|| operator =='%')
        return 2;
    else if(operator =='+'|| operator =='-')
        return 1;
    else 
        return 0;
}
// function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    char stack[MAX_SIZE];
    int top = -1;
    int len = strlen(infix);

    for (int i = 0; i < len; i++) {
        char currentChar = infix[i];
        if (isalnum(currentChar)) {
            postfix[strlen(postfix)] = currentChar;
        } else if (currentChar == '(') {
            stack[++top] = currentChar;
        } else if (currentChar == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[strlen(postfix)] = stack[top];
                top--;
            }
            // Pop the '('
            top--;
        } else if (isOperator(currentChar)) {
            while (top >= 0 && getPrecedence(stack[top]) >= getPrecedence(currentChar)) {
                postfix[strlen(postfix)] = stack[top];
                top--;
            }
            // Push the current operator onto the stack
            stack[++top] = currentChar;
        }
    }
    
}