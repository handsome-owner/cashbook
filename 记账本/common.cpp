#include "common.h"

// 通用函数（比如读取键盘输入）


// 获取用户的输入数据 并将对应的char返回
char readMenuSelection(int options) {
	string str;
	while (true) {
		getline(cin,str);
		if (str.size() > 1 || str[0] - '0' < 0 || str[0] - '0' > options) {
			cout << "输入的选项有误，请重新输入" << endl;
		}
		else {
			return str[0];
		}
	}

}

// 读取键盘输入的金额数  在此处全部使用整数
int readAmount() {
	int account;
	string str;
	while (true) {
		getline(cin, str);
		// 类型转换
		try {
			return stoi(str);
		}
		catch (invalid_argument e) {
			cout << "请输入正确的数字" << endl;
		}
	}
}


// 读取退出字符 限制用户其他输入
char readQuitConfirm() {
	char flag;
	string str;
	while (true) {
		getline(cin, str);
		if (str.empty()) {
			continue;
		}
		flag = toupper(str[0]);
		if (flag != 'Y' && flag != 'N'){
			cout << "请输出正确的选项 Y/N" << endl;
		}
		else {
			return flag;
		}
	}
}


