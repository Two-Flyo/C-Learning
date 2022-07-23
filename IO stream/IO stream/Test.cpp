#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
#include<sstream>
#include<fstream>
using namespace std;

struct PersonInfo
{
	string _name;
	int _age;
};

int main()
{
	PersonInfo info = { "lrf",20 };
	ostringstream oss;
	oss << info._name<<" "<< info._age;
	string str = oss.str();
	//cout << str << endl;
	istringstream iss(str);
	string name;
	int age;
	iss >> name >> age;
	cout<<name<<age;
	return 0;
}

//struct ServerInfo
//{
//	char _ip[32];
//	int _port;
//	Date _date;
//};
//
//class Date
//{ 
//private:
//	friend ofstream& operator<<(ofstream& ofs,Date& d);
//
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(_year),_month(month),_day(day)
//	{}
//	
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//ofstream& operator<<(ofstream& ofs,Date& d)
//{
//	ofs << d._year << " " << d._month << " " << d._day << endl;
//	return ofs;
//}
//
//class ConfigManager
//{
//public:
//	ConfigManager(const char* filename)
//		:_filename(filename)
//	{}
//
//	void WriteBin(const ServerInfo& info)
//	{
//		ofstream ofs(_filename.c_str(), ios_base::out | ios_base::binary);
//		ofs.write((const char*)&info, sizeof(ServerInfo));
//	}
//
//	void ReadBin(ServerInfo& info)
//	{
//		ifstream ifs(_filename.c_str(), ios_base::in | ios_base::binary);
//		ifs.read((char*)&info, sizeof(ServerInfo));
//	}
//
//	void WriteText(const ServerInfo& info)
//	{
//		ofstream ofs(_filename.c_str());
//		ofs << info._ip <<" " << info._port<<info._date;
//	}
//
//	void ReadText(ServerInfo& info)
//	{
//		ifstream ifs(_filename.c_str());
//		ifs >> info._ip >> info._port;
//	}
//
//
//private:
//	string _filename;
//};
//
//
//int main()
//{
//	ServerInfo winfo = { "192.1.1.0",80};
//	ServerInfo rinfo;
//	//ConfigManager cm("config.bin");
//
//	//cm.WriteBin(info);
//	//cm.ReadBin(winfo);
//	ConfigManager cm("config.txt");
//	cm.WriteText(winfo);
//	cm.ReadText(rinfo);
//
//	cout << winfo._ip << winfo._port << endl;
//	return 0;
//  }

//void TestC_RW_Bin()
//{
//	ServerInfo info = { "127.0.0.1",80};
//	FILE* fout = fopen("test.bin", "wb");
//	assert(fout);
//	fwrite(&info, sizeof(info), 1, fout);
//	fclose(fout);
//}
//
//
//void TestC_R_Bin()
//{
//	FILE* fout = fopen("test.bin", "rb");
//	assert(fout);
//	ServerInfo info;
//	fread(&info, sizeof(info), 1, fout);
//	fclose(fout);
//
//	printf("%s %d", info._ip, info._port);
//}

//void TestC_W_Text()
//{
//	ServerInfo info = { "127.0.0.1",80 };
//	FILE* fin = fopen("test.txt", "w");
//	assert(fin);
//	fprintf(fin,"%s %d",info._ip,info._port);
//	fclose(fin);
//}
//
//
//void TestC_R_Text()
//{
//	FILE* fout = fopen("test.txt", "r");
//	assert(fout);
//	ServerInfo info;
//	fscanf(fout,"%s %d", info._ip, &info._port);
//	fclose(fout);
//	printf("%s:%d", info._ip, info._port);
//}
//int main()
//{
//	//fopen fclose 打开、关闭文件
//	//二进制读写 fwrite/fread
//	//文本读写   fprintf/fscanf
//	//TestC_RW_Bin();
//	//TestC_R_Bin();	
//	TestC_W_Text();
//	TestC_R_Text();
//	return 0;
//}

//class B
//{
//public:
//	operator bool()
//	{
//		return a != 0;
//	}
//	int a;
//};
//
//int main()
//{
//	B b;
//	while (b)
//	{
//		cin >> b.a;
//	}
//	return 0;
//}

//int main()
//{
//	string str;
//	//cin >> str;
//	while (cin>>str)   //operator>>(cin,str)
//	{
//		//···
//		cout << str << " ";
//	}
//	return 0;
//}