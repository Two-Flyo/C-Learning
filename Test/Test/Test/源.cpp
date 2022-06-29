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
//struct PeopleInfo //ͨѶ¼��һ����Ҫ�洢����Ϣ
//{
//	char name[NAME_LENGTH];
//	int age;
//	char sex[SEX_LENGTH];
//	char tel[TEL_LENGTH];
//	char address[ADDRESS_LENGTH];
//};
//
////ͨѶ¼ ��̬�����İ汾
//struct PhoneBook
//{
//	struct PeopleInfo* data;
//	int num_people;//ͨѶ¼�е�ǰ�洢������
//	int capacity;//ͨѶ¼�ĵ�ǰ�������
//};
//
//
//
////����
//void CheckCapacity(struct PhoneBook* pb);
//
//
////��ʼ��ͨѶ¼
//void InitPhoneBook(struct PhoneBook* pb);
//
////�����ϵ��
//void AddPeople(struct PhoneBook* pb);
//
////չʾ��ϵ����Ϣ
//void ShowPhoneBook(const struct PhoneBook* pb);
//
////ɾ����ϵ��
//void DelPeople(struct PhoneBook* pb);
//
////������ϵ��
//void SearchPeople(const struct PhoneBook* pb);
//
////�޸�ָ����ϵ��
//void ModifyPeople(struct PhoneBook* pb);
//
////����ͨѶ¼
//void DestoryPhoneBook(struct PhoneBook* pb);
//
////������Ϣ��ͨѶ¼��
//void SavePhoneBook(struct PhoneBook* pb);
//
////�����ļ���Ϣ��ͨѶ¼��
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
//			printf("���ݳɹ�!\n");
//		}
//		else
//		{
//			perror("ͨѶ¼����ʧ��!");
//			exit(-1);
//		}
//	}
//}
//
//
////��̬�汾
//void InitPhoneBook(struct PhoneBook* pb)
//{
//	pb->num_people = 0;
//	pb->data =(struct PeopleInfo*)malloc(DEFAULT_SIZE * sizeof(struct PeopleInfo));
//	pb->capacity = DEFAULT_SIZE;
//
//	//�����ļ���Ϣ��ͨѶ¼��
//	LoadPhoneBook(pb);
//}
//
//
////��̬�汾
//void AddPeople(struct PhoneBook* pb)
//{
//	CheckCapacity(pb);
//	printf("����������:>");
//	scanf("%s", pb->data[pb->num_people].name);
//	printf("����������:>");
//	scanf("%d", &pb->data[pb->num_people].age);
//	printf("�������Ա�:>");
//	scanf("%s", pb->data[pb->num_people].sex);
//	printf("������绰:>");
//	scanf("%s", pb->data[pb->num_people].tel);
//	printf("�������ַ:>");
//	scanf("%s", pb->data[pb->num_people].address);
//
//	printf("��ӳɹ�!\n");
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
//		printf("ͨѶ¼Ϊ��!\n");
//		return;
//	}
//	char name[NAME_LENGTH] = { 0 };
//	printf("������Ҫɾ���˵�����:>");
//	scanf("%s", name);
//	//����ɾ����
//	int pos = FindPeopleByName(pb, name);
//	if (pos == -1)
//	{
//		printf("����ϵ�˲�����!\n");
//	}
//	//ɾ��
//	else
//	{
//		for (int i = pos; i <= pb->num_people - 1; i++)
//		{
//			pb->data[i] = pb->data[i + 1];
//		}
//		pb->num_people--;
//		printf("ɾ���ɹ�!\n");
//	}
//}
//
//void SearchPeople(const struct PhoneBook* pb)
//{
//	char name[NAME_LENGTH] = { 0 };
//	printf("����Ҫ�����˵�����:>");
//	scanf("%s", name);
//	int pos = FindPeopleByName(pb, name);
//	if (pos == -1)
//		printf("����ϵ�˲�����!\n");
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
//	printf("����Ҫ�޸ĵ���ϵ�˵�����:>");
//	scanf("%s", name);
//	int pos = FindPeopleByName(pb, name);
//	if (pos == -1)
//		printf("����ϵ�˲�����!\n");
//	else
//	{
//		printf("������������:>");
//		scanf("%s", pb->data[pos].name);
//		printf("����������:>");
//		scanf("%d", &pb->data[pos].age);
//		printf("�������Ա�:>");
//		scanf("%s", pb->data[pos].sex);
//		printf("������绰:>");
//		scanf("%s", pb->data[pos].tel);
//		printf("�������ַ:>");
//		scanf("%s", pb->data[pos].address);
//
//		printf("�޸ĳɹ�!\n");
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
//	//���ļ�
//	FILE* pf = fopen("phonebook.txt", "wb+");
//	if (pf == NULL)
//	{
//		perror("Savephonebook::fopen");
//		return;
//	}
//	//д����
//	for (int i = 0; i < pb->num_people; i++)
//	{
//		//fwrite(&(pb->data), sizeof(struct PeopleInfo), 1, pf);
//		fwrite(pb->data + i, sizeof(struct PeopleInfo), 1, pf);//����д������
//
//	}
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//}
//
//void LoadPhoneBook(struct PhoneBook* pb)
//{
//	//���ļ�
//	FILE* pf = fopen("phonebook.txt", "rb+");
//	if (pf == NULL)
//	{
//		perror("LoadPhoneBook::fopen");
//		return;
//	}
//	//���ļ�
//	struct PeopleInfo tmp = { 0 };
//	while (fread(&tmp, sizeof(struct PeopleInfo), 1, pf))
//	{
//		CheckCapacity(pb);//�����������������
//		pb->data[pb->num_people] = tmp;
//		pb->num_people++;
//	}
//
//	//�ر��ļ�
//	fclose(pf);
//	pf == NULL;
//}
//
//void menu()
//{
//	printf("*********************************\n");
//	printf("**********1.�½���ϵ��***********\n");
//	printf("**********2.ɾ����ϵ��***********\n");
//	printf("**********3.������ϵ��***********\n");
//	printf("**********4.�޸���ϵ��***********\n");
//	printf("**********5.��ʾ��Ϣ  ***********\n");
//	printf("**********0.�˳�      ***********\n");
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
//	//����һ��ͨѶ¼
//	struct PhoneBook phonebook;
//	InitPhoneBook(&phonebook);
//	do
//	{
//		menu();
//		printf("��ѡ��:>");
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
//			printf("�˳�ͨѶ¼\n");
//			break;
//		default:
//			printf("ѡ�����\n");
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
bool used[N];   // true��ʾ�ù���false��ʾ��δ�ù�
long long res[1000000];//��ŷ��������Ҳ��ظ��Ľ��
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
    ll r = 0;//ö�ٽ��
    if (u >= n) // �߽�
    {
        for (ll i = 0; i < n; i++) //123
        {
            r = r * 10 + ret[i];
        }
        if (r % m == 0 && r < e && !IsExist(r)) //r���ڽ��������
        {
            res[I] = r;
            I++;
            (*count)++;
            cout << r << endl;
        }
        return;
    }
    // ����ö��ÿ����֧������ǰλ�ÿ�������Щ��
    for (ll i = 0; i < n; i++)
    {
        if (!used[i])
        {
            ret[u] = num[i];
            used[i] = true;
            dfs(u + 1, n,e,m,num,count);
            // �ָ��ֳ�
            ret[u] = 0;
            used[i] = false;
        }
    }
}
int main()
{
    ll c = 0;//������������
    cin >> c;
    long long e = 0;
    ll m = 0;
    ll num[N];//����������Ȼ��e��ÿһλ��
    while (c--)
    {
        ll count = 0;//������
        cin >> e >> m;
        ll i = 0;
        ll n = 1;
        ll tmp = e;
        while (tmp/= 10) 
            n++;//���e��λ��
        tmp = e;
        while (tmp)
        {
            num[i] = tmp % 10;
            tmp /= 10;
            i++;
        }
        dfs(0, n, e,m, num,&count);
        cout << count << endl;
        cout <<"������Ϊ��" << count % 1000000007 << endl;

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
////		bool flag = true;//�ж��Ƿ�������
////		for (int j = 0; j < l - 1 - i; j++)
////		{
////			if (a[j] > a[j + 1])
////			{
////				swap(a[j], a[j + 1]);
////				count++;
////				flag = false;
////			}
////		}
////		if (flag == true)//�Ѿ�������ֱ�ӽ���
////			break;
////	}
////	cout<<"��������Ϊ��" << count << endl;
////
////}
////
////int main()
////{
////	int a[6] = { 10,41,52,18,29,26 };
////	sort(a, 6);
////	return 0;
////}