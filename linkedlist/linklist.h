#ifndef _LINKLIST_H_
#define _LINKLIST_H_

// 链表节点
typedef struct Node
{
    int data;               // 存数据
    struct Node *next;      // 指向下一个节点的指针
}Node;

// 函数声明
Node* create_node(int val);         // 创建单个节点
void list_append(Node **head, int val); // 尾部追加节点
void list_print(Node *head);        // 遍历打印全部节点
void list_free(Node *head);         // 释放全部节点

#endif
