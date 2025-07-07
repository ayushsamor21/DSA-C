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

struct Node* kthNode(struct Node* head){
    int kthIndex, currentIndex = 1;

    printf("Please enter the Kth index: ");
    scanf("%d", &kthIndex);

    if (kthIndex == 1){
        return head;
    }

    if (kthIndex <= 0) {
        printf("Invalid K value. Must be greater than 0.\n");
        return NULL;
    }

    struct Node* temp = head;
    struct Node* kthList = NULL;

    while (temp != NULL){
        if (currentIndex % kthIndex == 0){
            kthList = append(kthList, temp->data);
        }
        temp = temp->next;
        currentIndex++;
    }
    return kthList;
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

    printf("The original linked list: ");
    printLinkedList(head);
    printf("\n");

    struct Node* newLinkedList = kthNode(head);
    printf("Kth linked list: ");
    printLinkedList(newLinkedList);

    freeList(head);
    freeList(newLinkedList);
}
