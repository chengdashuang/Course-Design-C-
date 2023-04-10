#include "student.h"



//�ɼ���Ϣ¼�빦��: �ɴӴ����ļ�����ѧ���ɼ�����Ϣ��Ҳ���Ե���¼�롣
void welcome() {
	system("cls");
	printf("************************\n");
	printf("**  ѧ���ɼ�����ϵͳ  **\n");
	printf("**      ���ߣ��̴�˫  **\n");
	printf("**                    **\n");
	printf("**  ����ѧ����Ϣ ---1 **\n");
	printf("**  ɾ��ѧ����Ϣ ---2 **\n");
	printf("**  �޸�ѧ����Ϣ ---3 **\n");
	printf("**  ��ѯѧ����Ϣ ---4 **\n");
	printf("**  ���ѧ����Ϣ ---5 **\n");
	printf("**  ����ͳ����Ϣ ---6 **\n");
	printf("**  �˳�����ϵͳ ---0 **\n");

	printf("�������Ӧ�Ĺ��ܼ������֣�: ");
}

node List;


node* CreateNode()
{
	node* n = (node*)malloc(sizeof(node));
	n->C = n->Eng = n->Math = n->sum = 0;
	n->id = 0;
	n->next = NULL;
	n->name[0] = '\0';
	return n;
}
//��ȡ�ļ�
int readFile(node* head)
{
	FILE* fpr = fopen("C:\\Users\\Cds\\Desktop\\programming-homework-master\\StudentManagementSystem\\studentInfo.txt", "r");
	head->next = CreateNode();
	node* next = head->next;
	node* cur = head->next;
	if (fpr == NULL) {
		return 0;
	}
	else {
		//fcanf()


		while ((fscanf(fpr, "%d %s %d %d %d %d", &(next->id), next->name, &(next->C), &(next->Math), &(next->Eng), &(next->sum)) != EOF))
		{
			if (next != head)
				next->next = CreateNode();
			cur = next;
			next = next->next;
		}

	}
	fclose(fpr);//�ر��ļ�ָ�� 
	return 1;
}

//���̵���¼��
int add(node* head)
{

	head->next = CreateNode();
	node* next = head;
	int i = 0;
	int n;
	printf("��������Ҫ¼���ѧ����Ϣ�ĸ�����:\n");
	scanf("%d", &n);
	if (n == 0)
		return 0;
	printf("�밴�����¸�ʽ����ѧ����Ϣ\n");
	printf("|ѧ��\t|����\t|C\t|��ѧ\t|Ӣ��\t|�ܷ�\t|\n");
	while (i < n)
	{
		if (next != head)
			next->next = (node*)malloc(sizeof(node));
		next = next->next;
		scanf("%d %s %d %d %d %d", &(next->id), next->name, &(next->C), &(next->Math), &(next->Eng), &(next->sum));
		i++;
	}
	next->next = NULL;
	return 1;
}


void Input(node** head)
{
	int temp = 0;
	printf("1.�Ӵ����ļ�����\n");
	printf("2.����¼��\n");
	printf("��ѡ��");
	getchar();
	scanf("%d", &temp);

	if (temp == 1)
	{
		readFile(head);
	}
	if (temp == 2)
	{
		add(head);
	}

}


void PrintDeleteStuInfo(node* head) {
	system("cls");
	int id;
	printf("������Ҫɾ����ѧ��ѧ��:");
	scanf("%d", &id);
	node* st = SearchStuInfoById(id, head);

	if (st == NULL) {
		printf("���޴��ˣ�");
		return;
	}

	printf("________________________________________________________\n");
	printf("|ѧ��\t|����\t|C\t|��ѧ\t|Ӣ��\t|�ܷ�\t|\n");
	printf("________________________________________________________\n");
	printf("|%d|%s\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->C, st->Math, st->Eng, st->sum);
	printf("________________________________________________________\n");

	delete(head, st);
	saveFile(head);
}
//ɾ��ѧ����Ϣ
void delete(node* head, node* del)
{
	node* cur = head->next;
	if (cur == del)
	{
		head->next = cur->next;
		free(del);
	}
	else
	{
		while (cur->next != del)
		{
			cur = cur->next;//����
		}
		cur->next = del->next;

		//�ͷŽ��ռ� 
		free(del);
		del = NULL;
	}

}

//��ѧ�Ų�ѯ
node* SearchStuInfoById(int id, node* head)
{
	node* cur = head->next;

	while (cur != NULL) {

		if (cur->id == id) {
			return cur;
		}

		cur = cur->next;
	}
	return NULL;
}

//���������в��� 
node* SearchStuInfoByName(char name[], node* head)
{
	node* cur = head->next;

	while (cur->next != NULL) {

		if (strcmp(name, cur->name) == 0) {
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}


//��ѯѧ����Ϣ
void SearchStu(node* L)
{
	system("cls");
	int choice = 0;
	int id;
	char name[50];
	node* st;
	printf("��ѧ�Ų�ѯ----- 1\n");
	printf("��������ѯ----- 2\n");
	printf("�������ѯ��ʽ��");
	scanf("%d", &choice);

	//��ѧ�Ų�ѯ
	if (choice == 1) {
		printf("������Ҫ��ѯ��ѧ�ţ�");
		scanf("%d", &id);
		st = SearchStuInfoById(id, L);

		if (st == NULL) {
			printf("���޴��ˣ�\n");
		}
		else {

			printf("________________________________________________________\n");
			printf("|ѧ��\t|����\t|C����\t|��ѧ\t|Ӣ��\t|�ܷ�\t|\n");
			printf("________________________________________________________\n");
			printf("%d\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->C, st->Math, st->Eng, st->sum);
			printf("________________________________________________________\n");
		}
	}

	//��������ѯ
	else if (choice == 2) {
		printf("������Ҫ��ѯ��������");
		scanf("%s", name);
		st = SearchStuInfoByName(name, L);

		if (st == NULL) {
			printf("���޴��ˣ�\n");
		}
		else {
			printf("________________________________________________________\n");
			printf("|ѧ��\t|����\t|C����\t|��ѧ\t|Ӣ��\t|�ܷ�\t|\n");
			printf("________________________________________________________\n");
			printf("%d\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->C, st->Math, st->Eng, st->sum);
			printf("________________________________________________________\n");
		}
	}

}

//��Ϣ�޸�
void modify(node* head)
{
	system("cls");


	int id;
	int choice = -1;

	printf("������Ҫ���ҵ�ѧ��ѧ��");
	scanf("%d", &id);
	node* st = SearchStuInfoById(id, head);

	if (st == NULL) {
		printf("���޴��ˣ�");
		return;
	}
	while (1) {
		system("cls");
		printf("________________________________________________________\n");
		printf("|ѧ��\t|����\t|C\t|��ѧ\t|Ӣ��\t|�ܷ�\t|\n");
		printf("________________________________________________________\n");
		printf("%d\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->C, st->Math, st->Eng, st->sum);
		printf("________________________________________________________\n");
		printf("�޸�����---- 1\n");
		printf("�޸�C   ---- 2\n");
		printf("�޸���ѧ---- 3\n");
		printf("�޸�Ӣ��---- 4\n");

		printf("������Ҫ�޸ĵ���Ϣ: ");
		scanf("%d", &choice);


		switch (choice) {
		case 1:
			printf("������������");
			scanf("%s", st->name);
			break;
		case 2:
			printf("������C�ɼ���");
			scanf("%d", &st->C);
			break;
		case 3:
			printf("��������ѧ��");
			scanf("%d", &st->Math);
			break;
		case 4:
			printf("������Ӣ�");
			scanf("%d", &st->Eng);
			break;
		}
		st->sum = st->C + st->Math + st->Eng;
		printf("�Ƿ�����޸�ѧ����Ϣ?��yes:1 / no:0��\n");
		scanf("%d", &choice);
		if (choice == 0) {
			break;
		}
	}


	printf("________________________________________________________\n");
	printf("|ѧ��\t|����\t|C\t|��ѧ\t|Ӣ��\t|�ܷ�\t|\n");
	printf("________________________________________________________\n");
	printf("%d\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->C, st->Math, st->Eng, st->sum);
	printf("________________________________________________________\n");

	saveFile(head);
}


//�������ѧ����������Ϣ
void displayall(node* head)
{
	system("cls");
	//FILE* fpr = fopen("C:\\Users\\Cds\\Desktop\\programming-homework-master\\StudentManagementSystem\\studentInfo.txt", "w");

	node* next = head->next;
	printf("________________________________________________________\n");
	printf("|ѧ��\t|����\t|C\t|��ѧ\t|Ӣ��\t|�ܷ�\t|\n");
	printf("________________________________________________________\n");

	while (next != NULL)
	{
		printf("%d\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n", next->id, next->name, next->C, next->Math, next->Eng, next->sum);
		printf("________________________________________________________\n");
		//fprintf(fpr, "%d %s  %d %d %d %d\n", next->id, next->name, next->C, next->Math, next->Eng, next->sum);
		if (next->next != NULL)
			next = next->next;
		else
			break;
	}


	return;

}

//������������ �ǽ�������
bool cmpByC(node a, node b) {
	return a.C < b.C;
}

bool cmpByMath(node a, node b) {
	return a.Math < b.Math;
}
bool cmpByEng(node a, node b) {
	return a.Eng < b.Eng;
}
bool cmpBysum(node a, node b) {
	return a.sum < b.sum;
}
//�����ð������
void SortByC(node* head)
{
	for (node* i = head->next; i != NULL; i = i->next) {

		for (node* j = i; j != NULL; j = j->next) {
			if (cmpByC(*i, *j) == true) {
				//����������
				node temp = *i;
				*i = *j;
				*j = temp;
				//����ָ����
				temp.next = i->next;
				i->next = j->next;
				j->next = temp.next;
			}
		}

	}
}
void SortByMath(node* head)
{
	for (node* i = head->next; i != NULL; i = i->next) {

		for (node* j = i; j != NULL; j = j->next) {
			if (cmpByMath(*i, *j) == true) {
				//����������
				node temp = *i;
				*i = *j;
				*j = temp;
				//����ָ����
				temp.next = i->next;
				i->next = j->next;
				j->next = temp.next;
			}
		}
	}
}
void SortByEng(node* head)
{
	for (node* i = head->next; i != NULL; i = i->next) {

		for (node* j = i; j != NULL; j = j->next) {
			if (cmpByEng(*i, *j) == true) {
				//����������
				node temp = *i;
				*i = *j;
				*j = temp;
				//����ָ����
				temp.next = i->next;
				i->next = j->next;
				j->next = temp.next;
			}
		}
	}
}
void SortBysum(node* head)
{

	for (node* i = head->next; i != NULL; i = i->next) {

		for (node* j = i; j != NULL; j = j->next) {
			if (cmpBysum(*i, *j) == true) {
				//����������
				node temp = *i;
				*i = *j;
				*j = temp;
				//����ָ����
				temp.next = i->next;
				i->next = j->next;
				j->next = temp.next;
			}
		}
	}
}
//void SortById(node* head)
//{
//	for (node* i = head->next; i != NULL; i = i->next) {
//
//		for (node* j = i; j != NULL; j = j->next) {
//			if (i->id > j->id) {
//				//����������
//				node temp = *i;
//				*i = *j;
//				*j = temp;
//				//����ָ����
//				temp.next = i->next;
//				i->next = j->next;
//				j->next = temp.next;
//			}
//		}
//	}
//}
void DisplayByclassify(node* head, int choice)
{
	system("cls");
	node* next = head->next;
	char ch;
	printf("90����----A\n");
	printf("80~89-----B\n");
	printf("60~79-----C\n");
	printf("0~59------D\n");
	printf("��������Ҫ��ѯ�ķ�����:\n");
	getchar();
	ch = getchar();
	if (ch == 'A' && choice != 4)
		printf("90������\n");
	else if (ch == 'B' && choice != 4)
		printf("80~89\n");
	else if (ch == 'C' && choice != 4)
		printf("60~79\n");
	else if (ch == 'D' && choice != 4)
		printf("60����\n");


	if (ch == 'A' && choice == 4)
		printf("270������\n");
	else if (ch == 'B' && choice == 4)
		printf("240~270\n");
	else if (ch == 'C' && choice == 4)
		printf("180~240\n");
	else if (ch == 'D' && choice == 4)
		printf("180����\n");


	printf("____________________________\n");
	if (choice == 1)
		printf("ѧ��\t|����\t|C\t|\n");
	else if (choice == 2)
		printf("ѧ��\t|����\t|��ѧ\t|\n");
	else if (choice == 3)
		printf("ѧ��\t|����\t|Ӣ��\t|\n");
	else
		printf("ѧ��\t|����\t|�ܷ�\t|\n");
	printf("____________________________\n");
	while (next != NULL && next->id != 0)
	{
		if (choice == 1)
		{
			if (ch == 'A')
			{
				if (next->C >= 90)
				{
					printf("%d\t|%s\t|%d\t|\n", next->id, next->name, next->C);
					printf("____________________________\n");
				}
				if (next->next != NULL)
					next = next->next;
				else
				{
					break;
				}

			}
			else if (ch == 'B')
			{
				if (next->C >= 80 && next->C < 90)
				{
					printf("%d\t|%s\t|%d\t|\n", next->id, next->name, next->C);
					printf("____________________________\n");
				}
				;
				if (next->next != NULL)
					next = next->next;
				else
				{
					break;
				}

			}
			else if (ch == 'C')
			{
				if (next->C >= 60 && next->C < 80)
				{
					printf("%d\t|%s\t|%d\t|\n", next->id, next->name, next->C);
					printf("____________________________\n");;
				}
				;
				if (next->next != NULL)
					next = next->next;
				else
					break;
			}
			else if (ch == 'D')
			{
				if (next->C < 60)
				{
					printf("%d\t|%s\t|%d\t|\n", next->id, next->name, next->C);
					printf("____________________________\n");
				}
				;
				if (next->next != NULL)
					next = next->next;
				else
				{
					break;
				}

			}
		}
		if (choice == 2)
		{
			if (ch == 'A')
			{
				if (next->Math >= 90)
				{
					printf("%d\t|%s\t|%d\t|\n", next->id, next->name, next->Math);
					printf("____________________________\n");
				}
				;
				if (next->next != NULL)
					next = next->next;
				else
				{
					break;
				}

			}
			else if (ch == 'B')
			{
				if (next->Math >= 80 && next->Math < 90)
				{
					printf("%d\t|%s\t|%d\t|\n", next->id, next->name, next->Math);
					printf("____________________________\n");
				}
				;
				if (next->next != NULL)
					next = next->next;
				else
				{
					break;
				}

			}
			else if (ch == 'C')
			{
				if (next->Math >= 60 && next->Math < 80)
				{
					printf("%d\t|%s\t|%d\t|\n", next->id, next->name, next->Math);
					printf("____________________________\n");
				}
				;
				if (next->next != NULL)
					next = next->next;
				else
				{
					break;
				}

			}
			else if (ch == 'D')
			{
				if (next->Math < 60)
				{

					printf("%d\t|%s\t|%d\t|\n", next->id, next->name, next->Math);
					printf("____________________________\n");
				}
				;
				if (next->next != NULL)
					next = next->next;
				else
				{

					break;
				}

			}
		}
		if (choice == 3)
		{
			if (ch == 'A')
			{
				if (next->Eng >= 90)
				{
					printf("%d\t|%s\t|%d\t|\n", next->id, next->name, next->Eng);
					printf("____________________________\n");
				}
				;
				if (next->next != NULL)
					next = next->next;
				else
				{
					printf("\n");
					break;
				}
			}
			else if (ch == 'B')
			{
				if (next->Eng >= 80 && next->Eng < 90)
				{
					printf("%d\t|%s\t|%d\t|\n", next->id, next->name, next->Eng);
					printf("____________________________\n");
				}
				;
				if (next->next != NULL)
					next = next->next;
				else
				{
					printf("\n");
					break;
				}

			}
			else if (ch == 'C')
			{
				if (next->Eng >= 60 && next->Eng < 80)
				{
					printf("%d\t|%s\t|%d\t|\n", next->id, next->name, next->Eng);
					printf("____________________________\n");
				}
				;
				if (next->next != NULL)
					next = next->next;
				else
				{
					printf("\n");
					break;
				}

			}
			else if (ch == 'D')
			{
				if (next->Eng < 60)
				{
					printf("%d\t|%s\t|%d\t|\n", next->id, next->name, next->Eng);
					printf("____________________________\n");
				}
				;
				if (next->next != NULL)
					next = next->next;
				else
				{
					printf("\n");
					break;
				}

			}
		}
		if (choice == 4)
		{
			if (ch == 'A')
			{
				if (next->sum >= 270)
				{
					printf("%d\t|%s\t|%d\t|\n", next->id, next->name, next->sum);
					printf("____________________________\n");
				}
				;
				if (next->next != NULL)
					next = next->next;
				else
				{
					printf("\n");
					break;
				}

			}
			else if (ch == 'B')
			{
				if (next->sum >= 240 && next->sum < 270)
				{
					printf("%d\t|%s\t|%d\t|\n", next->id, next->name, next->sum);
					printf("____________________________\n");
				}
				;
				if (next->next != NULL)
					next = next->next;
				else
				{
					printf("\n");
					break;
				}

			}
			else if (ch == 'C')
			{
				if (next->sum >= 180 && next->sum < 250)
				{
					printf("%d\t|%s\t|%d\t|\n", next->id, next->name, next->sum);
					printf("____________________________\n");
				}
				;
				if (next->next != NULL)
					next = next->next;
				else
				{
					printf("\n");
					break;
				}

			}
			else if (ch == 'D')
			{
				if (next->sum < 180)
				{
					printf("%d\t|%s\t|%d\t|\n", next->id, next->name, next->sum);
					printf("____________________________\n");
				}
				;
				if (next->next != NULL)
					next = next->next;
				else
				{
					printf("\n");
					break;
				}

			}
		}
	}
}
void ClassifyPrint(node* head)		//ͳ�Ʒ���
{
	while (true)
	{
		system("cls");
		int choice = 0;
		printf("��C�ɼ��������-------1\n");
		printf("�������ɼ��������----2\n");
		printf("��Ӣ��ɼ��������----3\n");
		printf("���ܳɼ��������------4\n");
		printf("������ѡ��:");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			SortByC(head);
			break;
		case 2:
			SortByMath(head);
			break;
		case 3:
			SortByEng(head);
			break;
		case 4:
			SortBysum(head);
			break;
		}
		DisplayByclassify(head, choice);
		printf("�Ƿ��������ͳ�ƣ�(yes:1 / no:0 )��");
		scanf("%d", &choice);
		if (choice == 0)
		{
			//SortById(head);
			system("cls");
			break;

		}

	}

}

//�����ļ�
int saveFile(node* head)
{
	FILE* fpw = fopen("C:\\Users\\Cds\\Desktop\\programming-homework-master\\StudentManagementSystem\\studentInfo.txt", "w");
	if (fpw == NULL) return 0;

	//fprintf(fpw,"xxx",);
	node* next = head->next;

	while (next != NULL) {

		fprintf(fpw, "%d %s %d %d %d %d\n", next->id, next->name, next->C, next->Math, next->Eng, next->sum);
		next = next->next;
	}
	fclose(fpw);//�ر��ļ�ָ��
	return 1;
}

//�˳�����
void GoodBye()
{
	system("cls");
	printf("��ӭ�´�ʹ��~\n");
	exit(0);//�������� 
}

