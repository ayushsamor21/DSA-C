#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

struct Node* append(struct Node* head, int value){
    struct Node* newNode = createNode(value);
    if (head == NULL){                        
        head = newNode;
        return head;
    }
    struct Node* temp;                       
    temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode; 
    return head;
}

void printLinkedList(struct Node* head){
    struct Node* temp = head;
    while (temp != NULL){
        printf("%d", temp->data);
        if (temp->next != NULL){
            printf("->");
        }
        temp = temp->next;
    }
    printf("\n");
}

void length(struct Node* head){
    struct Node* temp;
    temp = head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    printf("The length of Linked List :  %d\n", length);
}

void freeList(struct Node* head){
    struct Node* temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    int times, num;

    printf("Please enter the number of elements : ");
    scanf("%d", &times);

    struct Node* head = NULL;
    for(int i = 0; i < times; i++){
        printf("Please enter the elements : ");
        scanf("%d", &num);
        head = append(head, num);
    }
    printLinkedList(head);
    length(head);
    freeList(head);
}
