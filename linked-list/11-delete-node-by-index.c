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

struct Node* deleteNodeByIndex(struct Node* head, int targetIndex){
    struct Node* temp = head;
    struct Node* previous = NULL;
    int currentIndex = 0;

    //Linked List is empty
    if(head == NULL){
        printf("Error in operation!!\n");
        return head;
    }

    if (targetIndex < 0){
        printf("Invalid Index!!\n");
        return head;
    }

    //deleting head
    if (targetIndex == 0){
        struct Node* newHead = head->next;
        free(temp);
        return newHead;
    }
    
    //Traverse List
    while(temp != NULL && currentIndex != targetIndex){
        previous = temp;
        temp = temp->next;
        currentIndex++;
    }

    //value not found
    if (temp == NULL) {
        printf("Index out of bounds!\n");
        return head;
    }
    
    //Skip case
    previous->next = temp->next;
    free(temp);
    return head;
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
    int times, num, targetIndex;

    printf("Please enter the number of elements : ");
    scanf("%d", &times);

    struct Node* head = NULL;
    for(int i = 0; i < times; i++){
        printf("Please enter the elements : ");
        scanf("%d", &num);
        head = append(head, num);
    }
    printf("Original linked list: ");
    printLinkedList(head);

    printf("Please enter the index you want to delete: ");
    scanf("%d", &targetIndex);

    printf("The new linked list: ");
    head = deleteNodeByIndex(head, targetIndex);
    printLinkedList(head);
    freeList(head);
}
