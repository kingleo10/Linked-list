#include <stdio.h>
#include <stdlib.h>
  
struct node {
  int data;
  struct node *next;
} *head;
 
void initialize(){
    head = NULL;
}
 
void insert(int num) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = num;
    newNode->next = head;
    head = newNode;
}
 
int getLength(struct node *head){
    if (head == NULL) { 
       printf("Invalid\n");       
       return 2;  
    }
      
    int length =0;
    while(head != NULL){
        head = head->next;
        length++;
    }
    return length;
}
 
struct node* getNthLastNode(struct node* head, int n){
    struct node *front, *back;
    int i;
    front = back = head;
    if(n > getLength(head)){
        printf("Error: n is greater than length\n");
        return NULL;
    }
    for(i = 0; i < n-1; i++){
        front = front->next;
    }
    while(front->next != NULL){
        front = front->next;
        back = back->next;
    }
     
    return back;
}
void printLinkedList(struct node *nodePtr) {
  while (nodePtr != NULL) {
     printf("%d", nodePtr->data);
     nodePtr = nodePtr->next;
     if(nodePtr != NULL) printf(" ");
  }
}
  
int main() {
    int N;
    struct node *NthNode;
    initialize();
    insert(47);  
    insert(65); 
    insert(12); 
    insert(3);
    insert(29);
    insert(38);
     
    printf("Linked List:\n");
    printLinkedList(head);
    printf("\n\nEnter N value\n");
    scanf("%d", &N);
    NthNode = getNthLastNode(head, N);
    printf("Nth node from the end of the linked list: %d", NthNode->data);
    return 0;
}