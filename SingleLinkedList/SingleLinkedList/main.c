//
//  main.c
//  SingleLinkedList
//
//  Created by zhangwen on 2016/12/12.
//  Copyright © 2016年 zhangwen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SingleLinkedList.h"

//学生
typedef struct Student_{
    char *name;
    int  age;
    char *documents;
}Student;

//打印学生信息
void printStudent(Student *student) {
    printf("姓名:%s, 年龄:%d, 是否建档:%s\n",
           student->name,
           student->age,
           student->documents == NULL ? "否": "是");

}

//销毁parents对象
void destroy(void *data){
    if (data == NULL) {
        return;
    }
    
    Student *stu = (Student *)data;
    if (stu->documents != NULL){
        free(stu->documents);
    }
    
    free(stu);
}

int main(int argc, const char * argv[]) {

    //创建一个学生黎明
    Student *liming = malloc(sizeof(Student));
    liming->name = "Li Ming";
    liming->age = 22;
    liming->documents = (char *)malloc(100);
    
    //创建一个学生王莹
    Student *wangyin = malloc(sizeof(Student));
    wangyin->name = "Wang Yin";
    wangyin->age = 20;
    wangyin->documents = (char *)malloc(100);
    
    //创建一个学生周杰伦
    Student *jayzhou = malloc(sizeof(Student));
    jayzhou->name = "Jay Zhou";
    jayzhou->age = 23;
    jayzhou->documents = NULL;
    
    printStudent(liming);
    printStudent(wangyin);
    printStudent(jayzhou);
    
    List *list = (List *)malloc(sizeof(List));
    
    //创建链表
    list_init(list, destroy);

    list_ins_next(list, NULL, liming);
    list_ins_next(list, NULL, jayzhou);
    list_ins_next(list, NULL, wangyin);
    
    printf("%d",list->size);

    //销毁链表
    list_destroy(list);
    
    //释放list
    free(list);
    
    return 0;
}
