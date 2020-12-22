#include<stdio.h> 
#include<stdlib.h> 
#include<assert.h> 
  
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
  
void MoveNode(struct Node** destRef, struct Node** sourceRef); 
  
struct Node* SortedMerge(struct Node* L1, struct Node* L2) 
{ 
    struct Node dummy; 
  
    struct Node* tail = &dummy; 
  
    dummy.next = NULL; 
    while (1) 
    { 
        if (L1 == NULL) 
        { 
            tail->next = L2; 
            break; 
        } 
        else if (L2 == NULL) 
        { 
            tail->next = L1; 
            break; 
        } 
        if (L1->data <= L2->data) 
            MoveNode(&(tail->next), &L1); 
        else
            MoveNode(&(tail->next), &L2); 
  
        tail = tail->next; 
    } 
    return(dummy.next); 
} 
  
void MoveNode(struct Node** destRef, struct Node** sourceRef) 
{ 
    struct Node* newNode = *sourceRef; 
    assert(newNode != NULL); 
  
    *sourceRef = newNode->next; 
  
    newNode->next = *destRef; 
  
    *destRef = newNode; 
} 
  
  
void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = 
        (struct Node*) malloc(sizeof(struct Node)); 
  
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
    struct Node* res = NULL; 
    struct Node* L1 = NULL; 
    struct Node* L2 = NULL; 
  
    push(&L1, 98); 
    push(&L1, 46); 
    push(&L1, 32); 
  
    push(&L2, 72); 
    push(&L2, 16); 
    push(&L2, 7); 
  
    res = SortedMerge(L1, L2); 
  
    printf("Merged Linked List: \n"); 
    printList(res); 
  
    return 0; 
} 