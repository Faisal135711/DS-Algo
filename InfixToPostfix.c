#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* stack;
int top = -1;

int precedence(char ch)
{
    if(ch == '+' || ch == '-'){
        return 1;
    }
    else if(ch == '*' || ch == '/'){
        return 2;
    }
    else{
        return 0;
    }
}
char* convert(char* infix)
{
    int i, j = 0, char_precedence, top_precedence;
    char* postfix;

    postfix = (char*)malloc(sizeof(char)*strlen(infix));
    for(i = 0; i < strlen(infix); i++){
        if(infix[i] >= 'a' && infix[i] <= 'z'){
            postfix[j] = infix[i];
            j++;
        }
        else if(infix[i] >= 'A' && infix[i] <= 'Z'){
            postfix[j] = infix[i];
            j++;
        }
        else if(infix[i] == '('){
            stack[++top] = infix[i];
        }
        else if(infix[i] == ')'){
            while(stack[top] != '('){
                postfix[j] = stack[top];
                top--;
                j++;
            }
            top--;
        }
        else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/'){
            int char_precedence = precedence(infix[i]);
            int top_precedence = precedence(stack[top]);

            while(top_precedence >= char_precedence){
                postfix[j] = stack[top];
                j++;
                top--;

                top_precedence = precedence(stack[top]);
            }
            
            stack[++top] = infix[i];
        }
    }

    while(top >= 0){

        postfix[j] = stack[top];
        j++;
        top--;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char* infix, *postfix;
    int i;

    infix = (char*)malloc(sizeof(char)*1000);

    printf("Enter infix expression: ");
    gets(infix);

    stack = (char*)malloc(sizeof(char)*strlen(infix));
    postfix = (char*)malloc(sizeof(char)*strlen(infix));

    postfix = convert(infix);

    printf("Postfix Expression: %s\n", postfix);

    free(postfix);
    free(stack);
    free(infix);

    return 0;
}
