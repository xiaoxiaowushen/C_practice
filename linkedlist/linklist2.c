#include "linklist.h"
#include<stdio.h>
#include<stdlib.h>

Node* create_node(int val)//函数返回值类型是 Node*（指向 Node 结构体的指针）
{
    Node* new_node = (Node*)malloc(sizeof(Node));//定义指针变量 new_node，类型是指向 Node 结构体的指针
    //sizeof(Node)：计算一个 Node 结构体需要多少字节内存\
    //malloc(sizeof(Node))：在堆上申请对应大小的一块内存，返回 void（通用地址）
    //(Node*)：强制类型转换，把 malloc 返回的 void * 地址，转为 Node，然后赋值给指针变量 new_node。
    new_node ->data = val;
    //new_node 这个指针变量指向结构体中的 data 然后把 val (形参）的值赋进这个 data
    new_node ->next = NULL;
    //new_node 指针变量指向结构体里的 next 把 NULL 赋给 next 让这里是空的
    return new_node;
}
void list_append(Node **head,int val)//
{
    Node *new_node = create_node(val);//create_node 返回的【节点地址】，赋值给指针变量 new_node 本身
    if(*head == NULL)
    //head：对二级指针 head 解引用，拿到 main 函数里的头指针变量,== NULL 意味着指针的值是空地址
    {
        *head = new_node;
        return;
    }
    Node *p = *head;//如果*head 里面有地址了 那么就建立一个临时指针变量 p 来存放*head 的地址
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = new_node;
}
//找到链表最后一个节点 p，修改 p 节点内部 next 成员，让 next 里面存放 new_node 的地址。

void list_print(Node*head)//形参head`是Node*一级结构体指针，接收链表头节点的地址。
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
    Node*p = head;
    while(p != NULL)
    {
        Node*temp = p;
        p = p->next;
        free(temp);
    }
}

Node *list_search(Node *head, int target)
{
    Node *p = head;
    while(p != NULL)
    {
        if(p->data == target)//p 当前指向节点的 data 成员，保存节点的数据；
        {
            return p; //找到匹配数据，返回这个节点地址
        }
        p = p->next;
    }
    return NULL; //遍历完没找到，返回空指针
}

void list_delete(Node **head, int target)//形参Node head：二级指针，接收 main 中 head 指针变量的地址
//为什么这里要用二级指针：有可能我们要删除的是头节点，此时需要修改 main 里面头指针变量本身的值，所以必须传&head。
{
    Node *p = *head;
    //head 是对二级指针解引用，拿到 main 头指针里存的头节点地址，赋值给临时指针`p`，p 用来遍历找要删除的目标节点
    Node *prev = NULL;
    //定义前驱指针prev，初始赋值为NULL。prev的任务：一直跟着 p，保存 p 当前节点的前一个节点地址。

    while(p != NULL && p->data != target)
    {
        prev = p;
        p = p->next;
        //先把当前 p 节点保存给 prev，再移动 p
    }
    if(p == NULL)
    {
    return;
    }
    if(prev == NULL)
    {
    *head = p->next;
    }
    else
    {
    prev->next = p->next;
    }
    free(p);

}

int main(void)
{
    Node *head = NULL; // 头指针，初始链表为空

    list_append(&head, 10);
    list_append(&head, 20);
    list_append(&head, 30);
    list_append(&head, 40);

    printf("neirong");
    list_print(head);

    Node *result = list_search(head, 30);
if(result != NULL)
{
    printf("找到了，数值是：%d", result->data);
}
else
{
    printf("没有找到");
}


    list_free(head);
    head = NULL;

    
    return 0;
}
//list_delete演示
//删除节点链表20
// 初始：head→[10]→[20]→[30]→NULL
// 调用 list_delete(&head,20);
// 1. p拿到head地址（节点10），prev=NULL
// 2. while(p != NULL && p->data !=20)：
// prev=p; // prev保存节点10地址
// p=p->next; // p移动到节点20
// 循环停止（p->data ==20）
// 3. prev != NULL，执行 prev->next = p->next;
// 节点10的next指向节点30。链表断开节点20。
// 4. free(p); 释放节点20内存。

//删除头链表10
// 初始：head→[10]→[20]→[30]→NULL
// 调用 list_delete(&head,10);
// 1. p拿到head地址（节点10），prev=NULL
// 2. while判断：p->data ==10，循环不进入。
// 3. prev == NULL，执行 *head = p->next;
// main的head指向节点20。
// 4. free(p);释放节点10。
