#include <stdio.h>
#include <stdlib.h>

struct node{
	char value;
	struct node *next;
} typedef Node;

printList(Node* n){
    while (n != NULL) {
        printf("%c",n->value);
        n = n->next;
    }
}

int getSize(Node* n){
	int size=0;
    while (n != NULL) {
        size++;
        n = n->next;
    }
    return size;
}

char pop(Node **head, int index){
	Node *temp1 = *head;
	char popped;
	if(index == 1){
		*head = temp1->next;
    popped = temp1->value;
		free(temp1);
		return popped;
	}
	
	for(int i=0;i<index-2;i++){
		temp1 = temp1->next;
	}
	
	Node *temp2 = temp1->next;
	temp1->next = temp2->next;
  popped = temp2->value;
	free(temp2);
  return popped;
}

void add(Node **head, char value, int index){
	Node * temp1 = (Node*)malloc(sizeof(Node));
	temp1->value = value;
	temp1->next = NULL;
	if(index==1){
		temp1->next = *head;
		*head = temp1;
		return;
	}
	Node * temp2 = *head;
	for(int i=0; i<index-2;i++){
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}

void pushHead(Node **head, char value){
	return add(head,value,1);
}

void pushTail(Node **head, char value){
	return add(head,value,getSize(*head)+1);
}

char popHead(Node **head){
	return pop(head,1);
}
char popTail(Node **head){
	return pop(head,getSize(*head));
}

int main(void) {
	Node *queue = NULL;
	pushTail(&queue, 'A');
	pushTail(&queue, 'B');
	pushTail(&queue, 'C');
	pushTail(&queue, 'D');
	pushTail(&queue, 'E');
	int initialSize = getSize(queue);
	for(int i=initialSize;i>=0;i--){
		int currentSize = getSize(queue);
		if(i<initialSize){
			printf("\nProcessing queue...");
		}else{
			printf("Initial Queue");
		}
		
		printf("\nQueue: ");
		printList(queue);
		printf("\nSize: %d", currentSize);
		if(currentSize>0){
			popHead(&queue);
		}
		
	}
  return 0;
}
