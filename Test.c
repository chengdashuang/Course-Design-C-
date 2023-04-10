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


#include "student.h"
int main()
{
	node* head = CreateNode();

	int choice = 0;
	while (true) {

		welcome();
		scanf("%d", &choice);
		switch (choice) {
		case 1://增加学生信息 
			Input(head);
			break;
		case 2://删除学生信息
			PrintDeleteStuInfo(head);
			break;
		case 3://修改学生信息 
			modify(head);
			break;
		case 4://查询学生信息
			SearchStu(head);
			break;
		case 5://输出学生信息
			displayall(head);
			break;
		case 6:
			ClassifyPrint(head);
			break;
		case 0://退出程序 
			GoodBye();
			break;
		}
		printf("是否需要继续操作？(yes:1 / no:0 )：");
		scanf("%d", &choice);
		if (choice == 0) {
			break;
		}
	}
	return 0;

}