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

struct Node* replaceByValue(struct Node* head, int newValue, int targetValue){
    struct Node* temp = head;
    bool isPresent = false;
    while (temp != NULL){
        if (temp->data == targetValue){
            temp->data = newValue;
            isPresent = true;
            break;
        }
        temp = temp->next;
    }
    if(!isPresent){
        printf("Error the value %d is not present!!\n", targetValue);
        printf("The linked list remains unchanged.\n");
    }
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
    int times, num, newValue, targetValue;

    printf("Please enter the number of elements : ");
    scanf("%d", &times);

    struct Node* head = NULL;
    for(int i = 0; i < times; i++){
        printf("Please enter the elements : ");
        scanf("%d", &num);
        head = append(head, num);
    }
    printf("The original linked list: ");
    printLinkedList(head);
    printf("\n");

    printf("Please enter the target value: ");
    scanf("%d", &targetValue);

    printf("Please enter the new value: ");
    scanf("%d", &newValue); 

    head = replaceByValue(head, newValue, targetValue);
    printf("The Linked List: ");
    printLinkedList(head);

    freeList(head);
}
