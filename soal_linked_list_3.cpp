#include <stdio.h>
#include <stdlib.h> 
 
struct Node
{
    int data;
    struct Node *next;
};
 
void push(struct Node **head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data = new_data;  
    new_node->next = (*head_ref);  
    (*head_ref) = new_node;  
} 
 
void printMiddle(struct Node *head)
{
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;
 
    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element of the linked list is %d\n", slow_ptr->data);
    }
}
 
int main() 
{ 
    struct Node* head = NULL; 
  
    push(&head, 45); 
    push(&head, 86); 
    push(&head, 39); 
    push(&head, 47);
    push(&head, 24); 
    printMiddle(head); 
  
    return 0; 
}