#include <stdlib.h>
#include <stdio.h>

struct node{
    int value;
    struct node *previous, *next;
};

struct list{
    struct node *head, *tail;
    unsigned int length;
};


int main(){
    int size;
    printf("Enter list size: ");
    scanf("%d", &size);

    struct list* linkedList = malloc (sizeof (struct list));
    struct node* head = malloc (sizeof(struct node));
    struct node* tail = malloc (sizeof(struct node));
    
    linkedList->head = head;
    linkedList->tail = tail;
    
    int i;
    struct node* previousNode = NULL;
    for(i = 0; i < size; i++){
        printf("Element[%d]: ", i);
        
        // Insert value into new node
        struct node* newNode = malloc (sizeof (struct node));
        
        scanf("%d", &(newNode->value));
        
        if(i == 0){
            //Adjust next and previous pointers
            linkedList->head->next= newNode;
            newNode->previous = linkedList->head;
            newNode->next = linkedList->tail;
            linkedList->tail->previous = newNode;
            
        }else{
            //Adjust net and previous pointers
            previousNode->next = newNode;
            linkedList->tail->previous = newNode;
            newNode->previous = previousNode;
            newNode->next = tail;
            
        }
        
        //Make newNode the previous node
        previousNode = newNode;
      
        linkedList->length ++;
      
    }
   //Print our values
    struct node* current = linkedList->head->next;
    
    while(current != linkedList->tail){
        printf("%d", current->value);
        printf("\n");
        current = current->next;
    }
    
    
    //Free up memory
    free(linkedList);
    free(head);
    free(tail);
    return 0;
}


