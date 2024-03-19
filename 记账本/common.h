#pragma once
// 引入相应的库，定义出需要的全局变量，以及声明绘制菜单和读取键盘输入的通用函数。

#include<iostream>
#include<string>
#include<fstream>
#include<vector>

// 保存用户数据
# define FILENAME "D:\\temp\\accounts.txt"
# define INCOME "收入"
# define EXPAND "支出"


using namespace std;

// 读取键盘输入并校验的通用函数
char readMenuSelection(int options);
int readAmount();
char readQuitConfirm();

// 绘制菜单的函数
void showMainMenu();
void showAccountingMenu();
void showQueryMenu();