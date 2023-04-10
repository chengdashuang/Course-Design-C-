#include "student.h"



//成绩信息录入功能: 可从磁盘文件导入学生成绩的信息，也可以单个录入。
void welcome() {
	system("cls");
	printf("************************\n");
	printf("**  学生成绩管理系统  **\n");
	printf("**      作者：程大双  **\n");
	printf("**                    **\n");
	printf("**  增加学生信息 ---1 **\n");
	printf("**  删除学生信息 ---2 **\n");
	printf("**  修改学生信息 ---3 **\n");
	printf("**  查询学生信息 ---4 **\n");
	printf("**  输出学生信息 ---5 **\n");
	printf("**  分类统计信息 ---6 **\n");
	printf("**  退出管理系统 ---0 **\n");

	printf("请输入对应的功能键（数字）: ");
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
//读取文件
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
	fclose(fpr);//关闭文件指针 
	return 1;
}

//键盘单个录入
int add(node* head)
{

	head->next = CreateNode();
	node* next = head;
	int i = 0;
	int n;
	printf("请输入你要录入的学生信息的个数是:\n");
	scanf("%d", &n);
	if (n == 0)
		return 0;
	printf("请按照以下格式输入学生信息\n");
	printf("|学号\t|姓名\t|C\t|数学\t|英语\t|总分\t|\n");
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
	printf("1.从磁盘文件导入\n");
	printf("2.单个录入\n");
	printf("请选择：");
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
	printf("请输入要删除的学生学号:");
	scanf("%d", &id);
	node* st = SearchStuInfoById(id, head);

	if (st == NULL) {
		printf("查无此人！");
		return;
	}

	printf("________________________________________________________\n");
	printf("|学号\t|姓名\t|C\t|数学\t|英语\t|总分\t|\n");
	printf("________________________________________________________\n");
	printf("|%d|%s\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->C, st->Math, st->Eng, st->sum);
	printf("________________________________________________________\n");

	delete(head, st);
	saveFile(head);
}
//删除学生信息
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
			cur = cur->next;//迭代
		}
		cur->next = del->next;

		//释放结点空间 
		free(del);
		del = NULL;
	}

}

//按学号查询
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

//按姓名进行查找 
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


//查询学生信息
void SearchStu(node* L)
{
	system("cls");
	int choice = 0;
	int id;
	char name[50];
	node* st;
	printf("按学号查询----- 1\n");
	printf("按姓名查询----- 2\n");
	printf("请输入查询方式：");
	scanf("%d", &choice);

	//按学号查询
	if (choice == 1) {
		printf("请输入要查询的学号：");
		scanf("%d", &id);
		st = SearchStuInfoById(id, L);

		if (st == NULL) {
			printf("查无此人！\n");
		}
		else {

			printf("________________________________________________________\n");
			printf("|学号\t|姓名\t|C语言\t|数学\t|英语\t|总分\t|\n");
			printf("________________________________________________________\n");
			printf("%d\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->C, st->Math, st->Eng, st->sum);
			printf("________________________________________________________\n");
		}
	}

	//按姓名查询
	else if (choice == 2) {
		printf("请输入要查询的姓名：");
		scanf("%s", name);
		st = SearchStuInfoByName(name, L);

		if (st == NULL) {
			printf("查无此人！\n");
		}
		else {
			printf("________________________________________________________\n");
			printf("|学号\t|姓名\t|C语言\t|数学\t|英语\t|总分\t|\n");
			printf("________________________________________________________\n");
			printf("%d\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->C, st->Math, st->Eng, st->sum);
			printf("________________________________________________________\n");
		}
	}

}

//信息修改
void modify(node* head)
{
	system("cls");


	int id;
	int choice = -1;

	printf("请输入要查找的学生学号");
	scanf("%d", &id);
	node* st = SearchStuInfoById(id, head);

	if (st == NULL) {
		printf("查无此人！");
		return;
	}
	while (1) {
		system("cls");
		printf("________________________________________________________\n");
		printf("|学号\t|姓名\t|C\t|数学\t|英语\t|总分\t|\n");
		printf("________________________________________________________\n");
		printf("%d\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->C, st->Math, st->Eng, st->sum);
		printf("________________________________________________________\n");
		printf("修改姓名---- 1\n");
		printf("修改C   ---- 2\n");
		printf("修改数学---- 3\n");
		printf("修改英语---- 4\n");

		printf("请输入要修改的信息: ");
		scanf("%d", &choice);


		switch (choice) {
		case 1:
			printf("请输入姓名：");
			scanf("%s", st->name);
			break;
		case 2:
			printf("请输入C成绩：");
			scanf("%d", &st->C);
			break;
		case 3:
			printf("请输入数学：");
			scanf("%d", &st->Math);
			break;
		case 4:
			printf("请输入英语：");
			scanf("%d", &st->Eng);
			break;
		}
		st->sum = st->C + st->Math + st->Eng;
		printf("是否继续修改学生信息?（yes:1 / no:0）\n");
		scanf("%d", &choice);
		if (choice == 0) {
			break;
		}
	}


	printf("________________________________________________________\n");
	printf("|学号\t|姓名\t|C\t|数学\t|英语\t|总分\t|\n");
	printf("________________________________________________________\n");
	printf("%d\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->C, st->Math, st->Eng, st->sum);
	printf("________________________________________________________\n");

	saveFile(head);
}


//输出所有学生的所有信息
void displayall(node* head)
{
	system("cls");
	//FILE* fpr = fopen("C:\\Users\\Cds\\Desktop\\programming-homework-master\\StudentManagementSystem\\studentInfo.txt", "w");

	node* next = head->next;
	printf("________________________________________________________\n");
	printf("|学号\t|姓名\t|C\t|数学\t|英语\t|总分\t|\n");
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

//链表的排序规则 是降序排列
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
//链表的冒泡排序
void SortByC(node* head)
{
	for (node* i = head->next; i != NULL; i = i->next) {

		for (node* j = i; j != NULL; j = j->next) {
			if (cmpByC(*i, *j) == true) {
				//交换数据域
				node temp = *i;
				*i = *j;
				*j = temp;
				//处理指针域
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
				//交换数据域
				node temp = *i;
				*i = *j;
				*j = temp;
				//处理指针域
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
				//交换数据域
				node temp = *i;
				*i = *j;
				*j = temp;
				//处理指针域
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
				//交换数据域
				node temp = *i;
				*i = *j;
				*j = temp;
				//处理指针域
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
//				//交换数据域
//				node temp = *i;
//				*i = *j;
//				*j = temp;
//				//处理指针域
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
	printf("90以上----A\n");
	printf("80~89-----B\n");
	printf("60~79-----C\n");
	printf("0~59------D\n");
	printf("请输入你要查询的分数段:\n");
	getchar();
	ch = getchar();
	if (ch == 'A' && choice != 4)
		printf("90分以上\n");
	else if (ch == 'B' && choice != 4)
		printf("80~89\n");
	else if (ch == 'C' && choice != 4)
		printf("60~79\n");
	else if (ch == 'D' && choice != 4)
		printf("60以下\n");


	if (ch == 'A' && choice == 4)
		printf("270分以上\n");
	else if (ch == 'B' && choice == 4)
		printf("240~270\n");
	else if (ch == 'C' && choice == 4)
		printf("180~240\n");
	else if (ch == 'D' && choice == 4)
		printf("180以下\n");


	printf("____________________________\n");
	if (choice == 1)
		printf("学号\t|姓名\t|C\t|\n");
	else if (choice == 2)
		printf("学号\t|姓名\t|数学\t|\n");
	else if (choice == 3)
		printf("学号\t|姓名\t|英语\t|\n");
	else
		printf("学号\t|姓名\t|总分\t|\n");
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
void ClassifyPrint(node* head)		//统计分类
{
	while (true)
	{
		system("cls");
		int choice = 0;
		printf("按C成绩排序输出-------1\n");
		printf("按高数成绩排序输出----2\n");
		printf("按英语成绩排序输出----3\n");
		printf("按总成绩排序输出------4\n");
		printf("请输入选择:");
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
		printf("是否继续分类统计？(yes:1 / no:0 )：");
		scanf("%d", &choice);
		if (choice == 0)
		{
			//SortById(head);
			system("cls");
			break;

		}

	}

}

//保存文件
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
	fclose(fpw);//关闭文件指针
	return 1;
}

//退出程序
void GoodBye()
{
	system("cls");
	printf("欢迎下次使用~\n");
	exit(0);//结束程序 
}

