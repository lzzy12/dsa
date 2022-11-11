#include "stdbool.h"
#include "stdio.h"
int stack[100];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

bool empty(){
    return top == -1;
}

int peek(){
    return stack[top];
}
int pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}


char getOppositeBracket(char c){
    if (c == '(')
       return ')';
    if (c == '[')
        return ']';
    if (c == '{')
        return '}';
    if (c == ')')
        return '(';
    if (c == ']')
        return '[';
    if (c == '}')
        return '{';
    return '\0';
}

 int isValid(char s[]) {
        for (int i = 0; s[i] != '\0'; i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                push(s[i]);
            } else{
                if (empty() || peek() != getOppositeBracket(s[i]))
                    return i;
                pop();
            }
        }
        return  -1;
}

int main(){
    char str[100];
    printf("Enter the expression : ");
    scanf("%s",str);
    printf("\n");
    int result = isValid(str);
    if (result == -1)
        printf("Valid expression\n");
    else
        printf("Invalid at index %d\n", result);
    return 0;
}