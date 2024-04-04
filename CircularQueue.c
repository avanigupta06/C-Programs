#include <stdio.h>
#include <stdlib.h>

#define MAX 5

char circularQueue[MAX];
int front = -1, rear = -1;

//Function declare
int isFull();
int isEmpty();
void insert(char element);
void delete();
void display();

int main() {
    int choice;
    char element;
    
    while (1) {
        printf("\nCircular Queue Menu:\n");
        printf("1. Insert an Element\n");
        printf("2. Delete an Element\n");
        printf("3. Display Queue Status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (rear == MAX - 1 && front == 0 || rear == front - 1) {
                    printf("Queue Overflow\n");
                } else {
                    printf("Enter the element to insert: ");
                    scanf(" %c", &element);
                    insert(element);
                }
                break;
            case 2:
                if (isEmpty()) {
                    printf("Queue Underflow\n");
                } else {
                    delete();
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}


//Function defination
int isFull(){
    return((front ==0 && rear==MAX-1)|| (front ==rear+1));
}
int isEmpty(){
    return (front ==-1);
}
void insert(char element){
    if(isFull()){
        printf("Overflow");
        return;
    }
    if(front == -1){
        front =0;
    }
    rear = (rear+1) % MAX;
    circularQueue[rear] = element;
    printf("%c inserted into the Queue\n",element);
}
void delete(){
    if(isEmpty()){
        printf("Queue Underflow\n");
        return;
    }
    char temp= circularQueue[front];
    if(front == rear){
        front =-1;
        rear = -1;
    }else{
        front = (front+1)% MAX;
    }
    printf("%c delete from Queue\n",temp);
}
void display(){
    if(isEmpty()){
        printf("Queue is Empty\n");
        return;
    }
    int i = front;
    while(1){
        printf("%c ",circularQueue[i]);
        if(i==rear){
            break;
        }
        i=(i+1)% MAX;
    }
}
