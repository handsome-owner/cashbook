#pragma once
// ������Ӧ�Ŀ⣬�������Ҫ��ȫ�ֱ������Լ��������Ʋ˵��Ͷ�ȡ���������ͨ�ú�����

#include<iostream>
#include<string>
#include<fstream>
#include<vector>

// �����û�����
# define FILENAME "D:\\temp\\accounts.txt"
# define INCOME "����"
# define EXPAND "֧��"


using namespace std;

// ��ȡ�������벢У���ͨ�ú���
char readMenuSelection(int options);
int readAmount();
char readQuitConfirm();

// ���Ʋ˵��ĺ���
void showMainMenu();
void showAccountingMenu();
void showQueryMenu();