//
//  SingleLinkedList.c
//  SingleLinkedList
//
//  Created by zhangwen on 2016/12/12.
//  Copyright © 2016年 zhangwen. All rights reserved.
//

#include "SingleLinkedList.h"
#include <stdlib.h> // malloc/free
#include <string.h> // memset
//初始化
void list_init(List *list, void (*destroy)(void *data))
{
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    list->destroy = destroy;
}

//销毁
void list_destroy(List *list)
{
    void *data;
    //删除每个元素
    while (list_size(list) > 0) {
        if (list_rem_next(list, NULL, (void **)&data) == 0 &&
            list->destroy != NULL) {
            //调用用户定义的销毁函数
            list->destroy(data);
        }
    }
    
    //清空整个list
    memset((void *)list, 0, sizeof(List));
}

//插入元素
int list_ins_next(List *list, ListElmt *element, const void *data)
{
    ListElmt *new_element;
    
    //给新元素分配内存
    if((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL) {
        return -1;
    }
    
    //插入元素到链表中
    new_element->data = (void *)data;
    if(element == NULL) {
        
        //插入到链表的头部
        if (list_size(list) == 0) {
            list->tail = new_element;
        }
        
        new_element->next = list->head;
        list->head = new_element;
    }
    else {
        
        //插入到非头部的地方
        if (element->next == NULL) {
            list->tail = new_element;
        }
        
        new_element->next = element->next;
        element->next = new_element;
    }
    
    //链表大小修改
    list->size ++;
    return 0;
}

//删除元素
int list_rem_next(List *list, ListElmt *element, void **data)
{
    ListElmt *old_element;
    
    //链表为空时非法
    if (list_size(list) == 0) {
        return -1;
    }
    
    if (element == NULL) {
        
        //删除链表的头部
        *data = list->head->data;
        old_element = list->head;
        list->head= list->head->next;
        
        if (list_size(list) == 1) {
            list->tail = NULL;
        }
    } else {
        
        //删除非头部的地方
        if (element->next == NULL) {
            return -1;
        }
        
        *data = element->next->data;
        old_element = element->next;
        element->next = element->next->next;
        
        if (element->next == NULL) {
            list->tail = element;
        }
    }
    
    //释放内存
    free(old_element);
    
    //大小减一
    list->size --;
    
    return 0;
}
