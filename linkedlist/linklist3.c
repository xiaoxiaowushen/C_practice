#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

Node* create_node(int val)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node ->data = val;
    new_node ->next = NULL;
    return new_node;
}
void list_append(Node **head,int val)
{
    Node* new_node = create_node(val);
    if(*head == NULL)
    {
        *head = new_node;
        return;
    }
    Node* p = *head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = new_node;
}
void list_print(Node*head)
{
    Node*p=head;
    while(p != NULL)
    {
        printf("%d->",p->data);
        p = p->next;
    }
    printf("NULL\n");
}
void list_free(Node*head)
{
    Node* p = head;
    while(p != NULL)
    {
        Node*temp = p;
        p = p->next;
        free(temp);
    }
}
Node* list_search(Node *head,int target)
{
    Node* p = head;
    while(p != NULL)
    {
        if(p->data == target)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
void list_delete(Node**head,int target)
{
    Node* p = *head;
    Node* prev = NULL;
    while(p != NULL && p->data != target)
    {
        prev = p;
        p=p->next;
    }
    if(p == NULL)
    {
        return;
    }
    if(prev == NULL)
    {
        *head = p->next;
    }else{
        prev->next = p->next;//修改前驱节点内部的地址值，重新搭桥
    }
    free(p);//释放这个被孤立节点的内存
}

int main(void)
{
    Node *head = NULL;

    list_append(&head,10);
    list_append(&head,15);
    list_append(&head,20);
    list_append(&head,30);
    list_append(&head,35);
    list_append(&head,40);

    list_print(head);

    Node* result = list_search(head,30);
    if(result != NULL)
    {
        printf("discover!number is:%d\n",result->data);
    }else{
        printf("no find");
    }
    list_delete(&head,20);
    list_print(head);
    list_append(&head,30);
    list_delete(&head,10);
    list_print(head);

    list_free(head);
    return 0;
}