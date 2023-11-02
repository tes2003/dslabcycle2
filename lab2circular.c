#include <stdio.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;


int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}


int isEmpty() {
  if (front == -1) return 1;
  return 0;
}


void enQueue(int element) {
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n Inserted -> %d", element);
  }
}


int deQueue() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    // Q has only one element, so we reset the 
    // queue after dequeing it. ?
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}

// Display the queue
void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d and element=%d \n", front,items[front]);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear -> %d and element=%d\n", rear,items[rear]);
  }
}

int main() {
int x,choice;
  while(choice != 4)  {  
        printf("\nEnter the choice(1.Insert 2.Delete 3.Display 4.Exit): ");  

        scanf("%d",&choice);  
        switch(choice) {  
            case 1:  {
                printf("enter the element to insert");
                scanf("%d",&x);
                   
                enQueue(x);  
                break;  
            }  
            case 2:  {  
                deQueue();  
                break;  
            }  
            case 3:{  
                display();  
                break;  
            }  
            case 4:{  
                printf("Exit\n");  
                break;   
            }  
            default:{  
                printf("Enter valid option"); 
            }}}  
return 0;
}

