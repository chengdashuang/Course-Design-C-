//题目：学生成绩管理系统
//编制一个成绩信息管理系统。每个学生信息包括学号、姓名、C语言成绩、高数成绩、英语成绩、总成绩等。
//功能：
//（1）	系统以菜单方式工作 : 要求界面清晰、友好、美观、易用。
//（2）	成绩信息录入功能 : 可从磁盘文件导入学生成绩的信息，也可以单个录入。
//（3）	信息浏览功能 : 能输出所有成绩的信息; 要求输出格式清晰、美观。
//（4）	查询功能 : 可按学号或姓名查找某一学生的成绩信息; 并将查询结果输出
//（5）	统计功能 : 按分数段显示学生信息, 可将分数段分为60分以下、60~79分、80~89分、90分以上。
//（6）	信息删除 : 要求能够删除某一指定学生的信息, 并在删除后将学生信息存盘。
//（7）	信息修改 : 要求能够修改某一指定学生的信息, 并在修改后将学生信息存盘。
//（8）	功能扩展 : 以上为必须完成的基本功能，大家可以在此基础上进一步做功能扩展。


#pragma once
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
typedef struct Node {
	int  id;//学号 
	char name[50];//姓名 
	int C, Math, Eng;//语数英 
	int sum;//总分 

	struct Node* next;//指针域 
}node;

//创造结点
node* CreateNode();

//欢迎界面
void welcome();

//成绩信息录入功能
void Input(node* head);
//读取文件
int readFile(node* head);
//键盘单个录入
int Add(node* head);


//查询功能
void SearchStu(node* head);
//按学号进行查找 
node* SearchStuInfoById(int id, node* head);
//按姓名进行查找 
node* SearcgStyInfoByName(char name[], node* head);



//删除学生信息
void delete(node* head);
void PrintDeleteStuInfo(node* head);


//修改学生信息
void modify(node* head);

//输出学生信息	
void displayall(node* head);



//统计分类功能

//排序方法
bool cmpByC(node a, node b);
bool cmpByMath(node a, node b);
bool cmpByEng(node a, node b);
bool cmpBysum(node a, node b);

//冒泡排序
void SortByC(node* head);
void SortByMath(node* head);
void SortByEng(node* head);
void SortBysum(node* head);
void DisplayByclassify(node* head, int choice);

//分类打印
void ClassifyPrint(node* head);




//保存文件
int SaveFile(node* L);
//退出程序
void GoodBye();





