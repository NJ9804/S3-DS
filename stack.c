#include<stdio.h>
#include<stdlib.h>
int ch,
void push();
void pop();
void main()
{
    while(1)
    {
        printf("1--PUSH/t/t2--POP\n");
         printf("Enter your choice\n");
         scanf("%d",&ch);
         switch(ch)
            {
                case 1 : push();
                        break;
                case 2 : pop();
                        break;
                 default: printf("Invalid choice\n");
                         break;
            }
    }
    
}
void push()












#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE]; // Stack implemented as an array
int top = -1;        // Initialize the top of the stack to -1

// Function to push an item onto the stack
void push(int item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow: Cannot push item onto the stack\n");
    } else {
        top++;
        stack[top] = item;
        printf("Pushed %d onto the stack\n", item);
    }
}

// Function to pop an item from the stack
int pop() {
    int item;
    if (top == -1) {
        printf("Stack Underflow: Cannot pop item from an empty stack\n");
        return -1; // Return a sentinel value indicating an error
    } else {
        item = stack[top];
        top--;
        return item;
    }
}

// Function to display the contents of the stack
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack contents: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    // Push some items onto the stack
    push(10);
    push(20);
    push(30);

    // Display the stack contents
    display();

    // Pop an item from the stack
    int popped_item = pop();
    if (popped_item != -1) {
        printf("Popped item: %d\n", popped_item);
    }

    // Display the updated stack contents
    display();

    return 0;
}
