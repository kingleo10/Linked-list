#include<stdio.h> 
#include<stdlib.h> 
  
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
  
void removeDuplicate(struct Node* head) 
{ 
    struct Node* current = head; 
    struct Node* next_next;  
    if (current == NULL)  return;  
  
    while (current->next != NULL)  
    { 
       if (current->data == current->next->data)  
       {        
           next_next = current->next->next; 
           free(current->next); 
           current->next = next_next;   
       } 
       else current = current->next;  
    } 
} 
  
void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next = (*head_ref);      
    (*head_ref)    = new_node; 
} 
  
void printList(struct Node *node) 
{ 
    while (node!=NULL) 
    { 
       printf("%d ", node->data); 
       node = node->next; 
    } 
}  
  
int main() 
{ 
    struct Node* head = NULL; 
    
    push(&head, 5); 
    push(&head, 5); 
    push(&head, 4);   
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 2);                                     
  
    printf("Linked list before duplicates removed\n"); 
    printList(head);  
    
    removeDuplicate(head);  
  
    printf("\nLinked list after duplicates removed\n");          
    printList(head);             
    
    return 0; 
} 