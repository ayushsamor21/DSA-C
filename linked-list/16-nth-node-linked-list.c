#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void nthNodePrinting(struct Node* head){
    int targetIndex, currentIndex = 0;
    bool isPresent = false;
    printf("Please enter the target Index: ");
    scanf("%d", &targetIndex);

    if (head == NULL){
        printf("The Nth index : -1\n");
        return;
    }

    if (targetIndex < 0) {
        printf("The Nth index : -1\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL){
        if (targetIndex == currentIndex){
            printf("Value %d at Nth index %d\n", temp->data, currentIndex);
            isPresent = true;
            break;
        }
        temp = temp->next;
        currentIndex++;
    }
    if (!isPresent){
        printf("The Nth index : -1\n");
    }
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
        printf("Enter element %d: ", i + 1);
        scanf("%d", &num);
        head = append(head, num);
    }
    printLinkedList(head);
    nthNodePrinting(head);
    freeList(head);
}
