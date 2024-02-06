#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define len 10

char stack[len],infix[len],postfix[len];
int top=-1;
int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
 void push(char c){
    top++;
    stack[top]=c;
 }

 char pop(){
   char item=stack[top];
    int top=top-1;
    return item;
 }
 int precedence(char symbol){
    switch(symbol){
        case '^':return 3;
        break;
        case'*':
        case'/':
        return 2;
        break;
        case'+':
        case'-':
        return 1; 
        break;
        default: return 0;
    }
 }
 void infixtopost(){
    int j=0;
    char value;
    for(int i=0;i<strlen(infix);i++){
        char symbol=infix[i];
        switch(symbol){
            case'(':push(symbol);
            break;
            case ')':while((value=pop())!='('){
                postfix[j]=value;
                j++;
            }
            break;
            case '^':
            case'*':
            case'/':
            case'+':
            case'-':
            while(!isEmpty()&&precedence(stack[top])>=precedence(symbol)){
                char data=pop();
                postfix[j]=data;
                j++;
            }
            push(symbol);
            break;
            default:postfix[j]=symbol;
            j++;
            break;
            
        }
    }
    while(!isEmpty()){
        int j=0;
    postfix[j]=pop();
    j++;
    }
    postfix[j]='\0';
 }
 

 void main(){
    int j;
    printf("Enter the infix expression:");
    gets(infix);
    infixtopost();
   for(int i=0;postfix[j]!='\0';j++){
    printf("%c",postfix[j]);
   }
    }
    

/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define len 10

char stack[len], infix[len], postfix[len];
int top = -1;

int isEmpty() {
    return top == -1;
}

void push(char c) {
    top++;
    stack[top] = c;
}

char pop() {
    char item = stack[top];
    top = top - 1;
    return item;
}

int precedence(char symbol) {
    switch (symbol) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void infixtopost() {
    int j = 0;
    char value;
    for (int i = 0; i < strlen(infix); i++) {
        char symbol = infix[i];
        switch (symbol) {
            case '(': push(symbol); break;
            case ')':
                while ((value = pop()) != '(') {
                    postfix[j] = value;
                    j++;
                }
                break;
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
                while (!isEmpty() && precedence(stack[top]) >= precedence(symbol)) {
                    char data = pop();
                    postfix[j] = data;
                    j++;
                }
                push(symbol);
                break;
            default:
                postfix[j] = symbol;
                j++;
                break;
        }
    }
    while (!isEmpty()) {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
}

int main() {
    int j;
    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infixtopost();
    for (j = 0; postfix[j] != '\0'; j++) {
        printf("%c", postfix[j]);
    }
    return 0;
}
*/
