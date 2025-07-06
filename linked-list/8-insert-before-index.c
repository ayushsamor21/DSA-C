#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

struct Node* append(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printLinkedList(struct Node* head){
    while (head != NULL){
        printf("%d", head->data);
        if(head->next != NULL){
            printf("->");
        }
        head = head->next;
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

struct Node* insertBeforeIndex(struct Node* head, int targetIndex, int newValue){
    struct Node* newNode = createNode(newValue);

    if (targetIndex < 0) {
        printf("Invalid index!\n");
        free(newNode);
        return head;
    }

    if (targetIndex == 0){
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    int currentIndex = 0;

    while (current != NULL && currentIndex < targetIndex - 1){
        current = current->next;
        currentIndex++;
    }

    if (current == NULL){
        printf("Index out of bounds!\n");
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

int main(){
    int times, num, targetIndex, newValue;

    printf("Please enter the number of elements: ");
    scanf("%d", &times);

    struct Node* head = NULL;
    for(int i = 0; i < times; i++){
        printf("Please enter the elements: ");
        scanf("%d", &num);
        head = append(head, num);
    }

    printf("The original linked list: ");
    printLinkedList(head);
    printf("\n");

    printf("Please enter the target index: ");
    scanf("%d", &targetIndex);

    printf("Please enter the new value: ");
    scanf("%d", &newValue); 

    head = insertBeforeIndex(head, targetIndex, newValue);
    printLinkedList(head);

    freeList(head);
}
