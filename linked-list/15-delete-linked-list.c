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

struct Node* append(struct Node* head, int value){
    struct Node* newNode = createNode(value);
    if(head == NULL){
        head = newNode;
        return head;
    }
    struct Node* temp = head;
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

void deleteLinkedList(struct Node* head){
    while(head!= NULL){
        struct Node* temp = head->next;
        free(head);
        head = temp;
    }
}

int main(){
    int num, times;
    
    printf("Please enter the number of element: ");
    scanf("%d", &times);

    struct Node* head = NULL;
    for(int i = 0; i < times; i++){
        printf("Enter the %d element: ", i + 1);
        scanf("%d", &num);
        head = append(head, num);
    }
    printf("The original linked list: ");
    printLinkedList(head);
    printf("\n");

    printf("The deleted linked list: ");
    deleteLinkedList(head);
    head = NULL; 
    
    printLinkedList(head);
}