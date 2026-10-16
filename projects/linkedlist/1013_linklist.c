#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

// // 链表节点
// typedef struct Node
// {
//     int data;               // 存数据
//     struct Node *next;      // 指向下一个节点的指针
// }Node;

// 创建一个新节点，存入val，next置NULL
Node* create_node(int val)
//返回一个类型node* 就是新建节点的类型 
//形参：`int val`，就是我们要存入节点的数据
{
    Node *new_node = (Node*)malloc(sizeof(Node));
// 1. `sizeof(Node)`：算出一个 `Node` 结构体占多少字节（`int` + 指针）
// 2. `malloc(sizeof(Node))`：在**堆内存**申请一块大小刚好等于 Node 的内存空间，返回这块空间的起始地址（`void*`）
// 3. `(Node*)`：强制类型转换，把 void * 转成`Node*`，告诉编译器：这块内存用来存放 Node 结构体
// 4. `Node *new_node`：定义指针变量`new_node`，保存刚刚 malloc 拿到的节点首地址
    new_node->data = val;
//  `new_node` 是结构体指针，访问成员用 `->`

// - `new_node->data`：节点里面存数据的成员
// - `= val`：把传入过来的值 val，放进这个节点的数据域
    new_node->next = NULL;
// `new_node->next`：节点里面的指针成员，用来存**下一个节点的地址**
// - `NULL` 代表空地址，意思：**这个节点暂时不指向任何别的节点**
// 新建节点默认没有后继节点，所以初始化为 NULL，防止野指针。

    return new_node;
    // 把这个新节点的地址返回给调用者，外面拿到这个地址，就可以把节点串进链表。
}

// 在链表尾部添加元素
// head是头指针的地址（二级指针），因为链表为空时要修改头指针本身
void list_append(Node **head, int val)
{
    Node *new_node = create_node(val);
    if(*head == NULL)
    {
        *head = new_node;
        return;
    }
    Node *p = *head;
    while(p->next != NULL)
    {
        p = p->next;//把**下一个节点的地址**拿出来，放到临时指针变量 p。
    }
    p->next = new_node;
}

// 从头到尾遍历打印
void list_print(Node *head)
{
    Node *p = head;
    while(p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// 释放链表所有节点，防止内存泄漏
void list_free(Node *head)
{
    Node *p = head;
    while(p != NULL)
    {
        Node *temp = p;
        p = p->next;
        free(temp);
    }
}

int main(void)
{
    Node *head = NULL; // 头指针，初始链表为空

    list_append(&head, 10);
    list_append(&head, 20);
    list_append(&head, 30);
    list_append(&head, 40);

    printf("链表内容：");
    list_print(head);

    list_free(head);
    head = NULL;
    return 0;
}
