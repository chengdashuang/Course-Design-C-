//��Ŀ��ѧ���ɼ�����ϵͳ
//����һ���ɼ���Ϣ����ϵͳ��ÿ��ѧ����Ϣ����ѧ�š�������C���Գɼ��������ɼ���Ӣ��ɼ����ܳɼ��ȡ�
//���ܣ�
//��1��	ϵͳ�Բ˵���ʽ���� : Ҫ������������Ѻá����ۡ����á�
//��2��	�ɼ���Ϣ¼�빦�� : �ɴӴ����ļ�����ѧ���ɼ�����Ϣ��Ҳ���Ե���¼�롣
//��3��	��Ϣ������� : ��������гɼ�����Ϣ; Ҫ�������ʽ���������ۡ�
//��4��	��ѯ���� : �ɰ�ѧ�Ż���������ĳһѧ���ĳɼ���Ϣ; ������ѯ������
//��5��	ͳ�ƹ��� : ����������ʾѧ����Ϣ, �ɽ������η�Ϊ60�����¡�60~79�֡�80~89�֡�90�����ϡ�
//��6��	��Ϣɾ�� : Ҫ���ܹ�ɾ��ĳһָ��ѧ������Ϣ, ����ɾ����ѧ����Ϣ���̡�
//��7��	��Ϣ�޸� : Ҫ���ܹ��޸�ĳһָ��ѧ������Ϣ, �����޸ĺ�ѧ����Ϣ���̡�
//��8��	������չ : ����Ϊ������ɵĻ������ܣ���ҿ����ڴ˻����Ͻ�һ����������չ��


#pragma once
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
typedef struct Node {
	int  id;//ѧ�� 
	char name[50];//���� 
	int C, Math, Eng;//����Ӣ 
	int sum;//�ܷ� 

	struct Node* next;//ָ���� 
}node;

//������
node* CreateNode();

//��ӭ����
void welcome();

//�ɼ���Ϣ¼�빦��
void Input(node* head);
//��ȡ�ļ�
int readFile(node* head);
//���̵���¼��
int Add(node* head);


//��ѯ����
void SearchStu(node* head);
//��ѧ�Ž��в��� 
node* SearchStuInfoById(int id, node* head);
//���������в��� 
node* SearcgStyInfoByName(char name[], node* head);



//ɾ��ѧ����Ϣ
void delete(node* head);
void PrintDeleteStuInfo(node* head);


//�޸�ѧ����Ϣ
void modify(node* head);

//���ѧ����Ϣ	
void displayall(node* head);



//ͳ�Ʒ��๦��

//���򷽷�
bool cmpByC(node a, node b);
bool cmpByMath(node a, node b);
bool cmpByEng(node a, node b);
bool cmpBysum(node a, node b);

//ð������
void SortByC(node* head);
void SortByMath(node* head);
void SortByEng(node* head);
void SortBysum(node* head);
void DisplayByclassify(node* head, int choice);

//�����ӡ
void ClassifyPrint(node* head);




//�����ļ�
int SaveFile(node* L);
//�˳�����
void GoodBye();





