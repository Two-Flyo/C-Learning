//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//#define DEFAULT_SIZE 3
//
//#define NAME_LENGTH 20
//#define SEX_LENGTH 5
//#define TEL_LENGTH 12
//#define ADDRESS_LENGTH 30
//
//#define CAPACITY 1000
//struct PeopleInfo //通讯录中一个人要存储的信息
//{
//	char name[NAME_LENGTH];
//	int age;
//	char sex[SEX_LENGTH];
//	char tel[TEL_LENGTH];
//	char address[ADDRESS_LENGTH];
//};
//
////通讯录 动态增长的版本
//struct PhoneBook
//{
//	struct PeopleInfo* data;
//	int num_people;//通讯录中当前存储的人数
//	int capacity;//通讯录的当前最大容量
//};
//
//
//
////增容
//void CheckCapacity(struct PhoneBook* pb);
//
//
////初始化通讯录
//void InitPhoneBook(struct PhoneBook* pb);
//
////添加联系人
//void AddPeople(struct PhoneBook* pb);
//
////展示联系人信息
//void ShowPhoneBook(const struct PhoneBook* pb);
//
////删除联系人
//void DelPeople(struct PhoneBook* pb);
//
////查找联系人
//void SearchPeople(const struct PhoneBook* pb);
//
////修改指定联系人
//void ModifyPeople(struct PhoneBook* pb);
//
////销毁通讯录
//void DestoryPhoneBook(struct PhoneBook* pb);
//
////保存信息到通讯录中
//void SavePhoneBook(struct PhoneBook* pb);
//
////加载文件信息到通讯录中
//void LoadPhoneBook(struct PhoneBook* pb);
//
//void CheckCapacity(struct PhoneBook* pb)
//{
//	if (pb->num_people == pb->capacity)
//	{
//		struct PeopleInfo* tmp = (struct PeopleInfo*)realloc(pb->data, (pb->capacity + 2) * sizeof(struct PeopleInfo));
//		if (tmp != NULL)
//		{
//			pb->data = tmp;
//			pb->capacity += 2;
//			printf("增容成功!\n");
//		}
//		else
//		{
//			perror("通讯录增容失败!");
//			exit(-1);
//		}
//	}
//}
//
//
////动态版本
//void InitPhoneBook(struct PhoneBook* pb)
//{
//	pb->num_people = 0;
//	pb->data =(struct PeopleInfo*)malloc(DEFAULT_SIZE * sizeof(struct PeopleInfo));
//	pb->capacity = DEFAULT_SIZE;
//
//	//加载文件信息到通讯录中
//	LoadPhoneBook(pb);
//}
//
//
////动态版本
//void AddPeople(struct PhoneBook* pb)
//{
//	CheckCapacity(pb);
//	printf("请输入名字:>");
//	scanf("%s", pb->data[pb->num_people].name);
//	printf("请输入年领:>");
//	scanf("%d", &pb->data[pb->num_people].age);
//	printf("请输入性别:>");
//	scanf("%s", pb->data[pb->num_people].sex);
//	printf("请输入电话:>");
//	scanf("%s", pb->data[pb->num_people].tel);
//	printf("请输入地址:>");
//	scanf("%s", pb->data[pb->num_people].address);
//
//	printf("添加成功!\n");
//	pb->num_people++;
//}
//
//
//
//void ShowPhoneBook(const struct PhoneBook* pb)
//{
//	printf("%15s\t%5s\t%8s\t%15s\t%30s\n\n", "name", "age", "sex", "tel", "address");
//	for (int i = 0; i < pb->num_people; i++)
//	{
//		printf("%15s\t%5d\t%8s\t%15s\t%30s\n", pb->data[i].name, pb->data[i].age,
//			pb->data[i].sex, pb->data[i].tel, pb->data[i].address);
//	}
//}
//int FindPeopleByName(const struct PhoneBook* pb, const char* name)
//{
//	for (int i = 0; i < pb->num_people; i++)
//	{
//		if (strcmp(pb->data[i].name, name) == 0)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//
//void DelPeople(struct PhoneBook* pb)
//{
//	if (pb->num_people == 0)
//	{
//		printf("通讯录为空!\n");
//		return;
//	}
//	char name[NAME_LENGTH] = { 0 };
//	printf("请输入要删除人的名字:>");
//	scanf("%s", name);
//	//查找删除人
//	int pos = FindPeopleByName(pb, name);
//	if (pos == -1)
//	{
//		printf("该联系人不存在!\n");
//	}
//	//删除
//	else
//	{
//		for (int i = pos; i <= pb->num_people - 1; i++)
//		{
//			pb->data[i] = pb->data[i + 1];
//		}
//		pb->num_people--;
//		printf("删除成功!\n");
//	}
//}
//
//void SearchPeople(const struct PhoneBook* pb)
//{
//	char name[NAME_LENGTH] = { 0 };
//	printf("输入要查找人的名字:>");
//	scanf("%s", name);
//	int pos = FindPeopleByName(pb, name);
//	if (pos == -1)
//		printf("该联系人不存在!\n");
//	else
//	{
//		printf("%15s\t%5s\t%8s\t%15s\t%30s\n\n", "name", "age", "sex", "tel", "address");
//		printf("%15s\t%5d\t%8s\t%15s\t%30s\n", pb->data[pos].name, pb->data[pos].age,
//			pb->data[pos].sex, pb->data[pos].tel, pb->data[pos].address);
//	}
//}
//
//void ModifyPeople(struct PhoneBook* pb)
//{
//	char name[NAME_LENGTH] = { 0 };
//	printf("输入要修改的联系人的名字:>");
//	scanf("%s", name);
//	int pos = FindPeopleByName(pb, name);
//	if (pos == -1)
//		printf("该联系人不存在!\n");
//	else
//	{
//		printf("请输入新名字:>");
//		scanf("%s", pb->data[pos].name);
//		printf("请输入年领:>");
//		scanf("%d", &pb->data[pos].age);
//		printf("请输入性别:>");
//		scanf("%s", pb->data[pos].sex);
//		printf("请输入电话:>");
//		scanf("%s", pb->data[pos].tel);
//		printf("请输入地址:>");
//		scanf("%s", pb->data[pos].address);
//
//		printf("修改成功!\n");
//	}
//}
//
//void DestoryPhoneBook(struct PhoneBook* pb)
//{
//	free(pb->data);
//	pb->data = NULL;
//}
//
//
//void SavePhoneBook(struct PhoneBook* pb)
//{
//	//打开文件
//	FILE* pf = fopen("phonebook.txt", "wb+");
//	if (pf == NULL)
//	{
//		perror("Savephonebook::fopen");
//		return;
//	}
//	//写数据
//	for (int i = 0; i < pb->num_people; i++)
//	{
//		//fwrite(&(pb->data), sizeof(struct PeopleInfo), 1, pf);
//		fwrite(pb->data + i, sizeof(struct PeopleInfo), 1, pf);//两种写法均可
//
//	}
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//}
//
//void LoadPhoneBook(struct PhoneBook* pb)
//{
//	//打开文件
//	FILE* pf = fopen("phonebook.txt", "rb+");
//	if (pf == NULL)
//	{
//		perror("LoadPhoneBook::fopen");
//		return;
//	}
//	//读文件
//	struct PeopleInfo tmp = { 0 };
//	while (fread(&tmp, sizeof(struct PeopleInfo), 1, pf))
//	{
//		CheckCapacity(pb);//如果容量不够，增容
//		pb->data[pb->num_people] = tmp;
//		pb->num_people++;
//	}
//
//	//关闭文件
//	fclose(pf);
//	pf == NULL;
//}
//
//void menu()
//{
//	printf("*********************************\n");
//	printf("**********1.新建联系人***********\n");
//	printf("**********2.删除联系人***********\n");
//	printf("**********3.查找联系人***********\n");
//	printf("**********4.修改联系人***********\n");
//	printf("**********5.显示信息  ***********\n");
//	printf("**********0.退出      ***********\n");
//	printf("*********************************\n");
//}
//enum Option
//{
//	EXIT,
//	ADD,
//	DEL,
//	SEARCH,
//	MODIFY,
//	SHOW,
//	SORT
//};
//
//int main()
//{
//	int input = 0;
//	//创建一个通讯录
//	struct PhoneBook phonebook;
//	InitPhoneBook(&phonebook);
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case ADD:
//			AddPeople(&phonebook);
//			break;
//		case DEL:
//			DelPeople(&phonebook);
//			break;
//		case SEARCH:
//			SearchPeople(&phonebook);
//			break;
//		case MODIFY:
//			ModifyPeople(&phonebook);
//			break;
//		case SHOW:
//			ShowPhoneBook(&phonebook);
//			break;
//		case EXIT:
//			SavePhoneBook(&phonebook);
//			DestoryPhoneBook(&phonebook);
//			printf("退出通讯录\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}
#include<stdbool.h>
#include <iostream>

typedef long long ll;

using namespace std;
const int N = 20;
long long ret[N];
bool used[N];   // true表示用过，false表示还未用过
long long res[1000000];//存放符合条件且不重复的结果
ll I = 0;


bool IsExist(ll r)
{
    for (ll i = 0; i <=N; i++)
    {
        if (r == res[i])
            return true;
    }
    return false;
}

void dfs(ll u,ll n,ll e,ll m,ll *num,ll *count)
{
    ll r = 0;//枚举结果
    if (u >= n) // 边界
    {
        for (ll i = 0; i < n; i++) //123
        {
            r = r * 10 + ret[i];
        }
        if (r % m == 0 && r < e && !IsExist(r)) //r不在结果数组中
        {
            res[I] = r;
            I++;
            (*count)++;
            cout << r << endl;
        }
        return;
    }
    // 依次枚举每个分支，即当前位置可以填哪些数
    for (ll i = 0; i < n; i++)
    {
        if (!used[i])
        {
            ret[u] = num[i];
            used[i] = true;
            dfs(u + 1, n,e,m,num,count);
            // 恢复现场
            ret[u] = 0;
            used[i] = false;
        }
    }
}
int main()
{
    ll c = 0;//测试用例个数
    cin >> c;
    long long e = 0;
    ll m = 0;
    ll num[N];//存放输入的自然数e的每一位数
    while (c--)
    {
        ll count = 0;//方案数
        cin >> e >> m;
        ll i = 0;
        ll n = 1;
        ll tmp = e;
        while (tmp/= 10) 
            n++;//求出e的位数
        tmp = e;
        while (tmp)
        {
            num[i] = tmp % 10;
            tmp /= 10;
            i++;
        }
        dfs(0, n, e,m, num,&count);
        cout << count << endl;
        cout <<"方案数为：" << count % 1000000007 << endl;

    }

    return 0;
}
//
////#include<iostream>
////
////using namespace std;
////
////void sort(int* a, int l) 
////{
////	int count = 0;
////	for (int i = 0; i < l - 1; i++)
////	{
////		bool flag = true;//判断是否有序了
////		for (int j = 0; j < l - 1 - i; j++)
////		{
////			if (a[j] > a[j + 1])
////			{
////				swap(a[j], a[j + 1]);
////				count++;
////				flag = false;
////			}
////		}
////		if (flag == true)//已经有序则直接结束
////			break;
////	}
////	cout<<"交换次数为：" << count << endl;
////
////}
////
////int main()
////{
////	int a[6] = { 10,41,52,18,29,26 };
////	sort(a, 6);
////	return 0;
////}