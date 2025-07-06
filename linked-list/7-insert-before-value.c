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

struct Node* insertBeforeValue(struct Node* head, int targetValue, int newValue){
    struct Node* newNode = createNode(newValue);
    if (head == NULL){
        printf("Error in operation");
        return head;
    }
    if (head->data == targetValue){
        newNode->next = head;
        return head;
    }

    struct Node* current = head;
    while(current->next != NULL && current->next->data != targetValue){
        current = current->next;
    }

    if(current->next == NULL){
        printf("Target not found !!!"); 
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
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
    int times, num, target, newValue;

    printf("Please enter the number of elements : ");
    scanf("%d", &times);

    struct Node* head = NULL;
    for(int i = 0; i < times; i++){
        printf("Please enter the elements : ");
        scanf("%d", &num);
        head = append(head, num);
    }
    printLinkedList(head);

    printf("Please enter target value : ");
    scanf("%d", &target);

    printf("Please enter new value : ");
    scanf("%d", &newValue);

    head = insertBeforeValue(head, target, newValue);
    printLinkedList(head);

    freeList(head);
}
