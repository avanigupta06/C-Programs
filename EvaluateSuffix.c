#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<math.h>

#define MAX_SIZE 100

//function declarition
int isOperator(char ch);
int evaluateSuffix(char *suffix);

//main function
int main() {
    char suffix[MAX_SIZE];
    printf("Enter suffix expression: ");
    scanf("%s", suffix);

    int result = evaluateSuffix(suffix);
    printf("Result: %d\n", result);

    return 0;
}

//function defination
int isOperator(char ch){
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='^');
}
int evaluateSuffix(char *suffix){
    int stack[MAX_SIZE];
    int top = -1;
    int len = strlen(suffix);

    for(int i =0;i< len; i++){
        if(suffix[i] == ' ' || suffix[i]=='\t'){
            continue;
        }
        if(isdigit(suffix[i])){
            int operand = suffix[i]-'0';
            stack[++top] = operand;
        }
        else if (isOperator(suffix[i])) {
            int operand2 = stack[top--];
            int operand1 = stack[top--];

            switch (suffix[i]) {
                case '+':
                    stack[++top] = operand1 + operand2;
                    break;
                case '-':
                    stack[++top] = operand1 - operand2;
                    break;
                case '*':
                    stack[++top] = operand1 * operand2;
                    break;
                case '/':
                    stack[++top] = operand1 / operand2;
                    break;
                case '^':
                    stack[++top] = (int)pow(operand1, operand2);
                    break;
                case '%':
                    stack[++top] = operand1 % operand2;
                    break;
            }
        }
    }
    return stack[top];
}
