//
//  SingleLinkedList.h
//  SingleLinkedList
//
//  Created by zhangwen on 2016/12/12.
//  Copyright © 2016年 zhangwen. All rights reserved.
//

#ifndef SingleLinkedList_h
#define SingleLinkedList_h

// 链表的元素
typedef struct ListElmt_ {
    void *data;
    struct ListElmt_ *next;
}ListElmt;

// 链表
typedef struct List_ {
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    ListElmt *head;
    ListElmt *tail;
}List;

/* 链表的接口 */
//初始化，并不分配内存，只是初始化变量
void list_init(List *list, void (*destroy)(void *data));
//销毁每个元素，清空list，并不释放list的内存
void list_destroy(List *list);
//插入一个数据到指定元素之后
int list_ins_next(List *list, ListElmt *element, const void *data);
//删除指定元素之后的数据
int list_rem_next(List *list, ListElmt *element, void **data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)

#endif /* SingleLinkedList_h */
