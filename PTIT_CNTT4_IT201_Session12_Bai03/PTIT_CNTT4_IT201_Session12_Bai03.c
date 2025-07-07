#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
Node* createNode(int data) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void printList(Node* head) {
    while(head!=NULL) {
        if (head->next==NULL) {
            printf("%d -> ",head->data);
            break;
        }
        printf("%d <-> ",head->data);
        head=head->next;
    }
    printf("NULL");
}
Node* insertAtEnd(Node* head,int num) {
    if (head==NULL) {
        return NULL;
    }
    Node* current=head;
    while (current->next->next!=NULL) {
        current=current->next;
    }
    Node* newNode=createNode(num);
    Node* temp=current->next;
    temp->next=newNode;
    newNode->prev=temp;
    return head;
}
int main() {
    Node* head=createNode(10);
    Node* Node1=createNode(20);
    Node* Node2=createNode(30);
    Node* Node3=createNode(40);
    Node* Node4=createNode(50);
    head->next=Node1;
    Node1->prev=head;
    Node1->next=Node2;
    Node2->prev=Node1;
    Node2->next=Node3;
    Node3->prev=Node2;
    Node3->next=Node4;
    Node4->prev=Node3;
    head=insertAtEnd(head,70);
    printList(head);
    return 0;
}