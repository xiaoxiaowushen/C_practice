#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

Node* create_node(int val)//返回一个node类型的指针 函数作用是新建一个节点
{
    Node *new_node = (Node*)malloc(sizeof(Node));//在这里开一片内存来存入node的值
    new_node -> data = val;//指向结构体的date 用来存数据
    new_node -> next = NULL;//new_node指向next(结构体里的指针成员，用来存放下一个节点的地址)，NULL代表空地址，意思：这个节点暂时不指向任何别的节点
    return new_node;//把这个新节点的地址返回给调用者
}
void list_append(Node **head,int val)//我在这个函数这里定义了一个叫 head 的二级指针指向 node 这个一级指针变量
{
    Node *new_node = create_node(val);//调用函数，新建一个节点，拿到新节点的地址存到 new_node

    if(*head == NULL)//如果这个head指向的链表是空的
    {
        *head = new_node;//把 new_node（新节点的地址，Node * 类型）赋值给main里的一级指针head 
        return;//作用：直接结束函数，提前退出，不是用来返回数据
    }
    Node *p = *head;//定义一个临时指针 来存放*head的地址
    while(p->next != NULL)
    {
        p = p->next;//把next的地址存到临时变量p里
    }
    p->next = new_node;//让 p 指向的这个节点的 next 指针，指向新节点。
}
void list_print(Node *head)//传进去的是链表第一个节点的地址
{
     Node *p = head;//拷贝 head 里面存的节点地址，放到 p 里面
     while(p != NULL)//判断：指针 p 的值不等于 NULL
     {
        printf("%d -> ", p->data);//读取p指向节点里面的data，打印
        p = p->next;// 拿当前节点里面存的下一个门牌号，更新p，走到下一个节点
     }
     printf("NULL\n");
}
void list_free(Node *head)
{
    Node *p = head;
    while(p != NULL)
    {
        Node *temp = p;//把 p 里面保存的地址，拷贝一份，存入 temp
        p = p->next;//p跳到下一个节点
        free(temp);//释放刚才备份的节点内存
    }
}
int main(void)
{
    Node *head = NULL;

    list_append(&head,10);
    list_append(&head,20);
    list_append(&head,30);
    list_append(&head,40);

    printf("brain chart:");
    list_print(head);

    list_free(head);
    head = NULL;
    return 0;
}
