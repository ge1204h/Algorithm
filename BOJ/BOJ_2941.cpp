// BOJ_2941.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <string>

// 크로아티아 알파벳
using namespace std;
int CheckCount(string str)
{
	int charCount = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'c')
		{ 
			if (str[i + 1] == '=' || str[i + 1] == '-')
				++i;
		}
		else if (str[i] == 'd')
		{
			if (str[i + 1] == '-')
				++i;
			else if (str[i + 1] == 'z' && str[i + 2] == '=')
			{
				i = i + 2;
			}
		}
		else if (str[i] == 'l')
		{
			if (str[i + 1] == 'j')
				++i;
		}
		else if (str[i] == 'n')
		{
			if (str[i + 1] == 'j')
				++i;
		}
		else if (str[i] == 's')
		{
			if (str[i + 1] == '=')
				++i;
		}
		else if (str[i] == 'z')
		{
			if (str[i + 1] == '=')
				++i;
		}
		++charCount;
	}
	return charCount;
}

int main()
{
	string str;
	cin >> str;

	//#1
	//cout << CheckCount(str);

	//#2
	int idx;
	string arr[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	for (int i = 0; i < 8; ++i)
	{
		while (true)
		{
			idx = str.find(arr[i]);
			if (idx == string::npos)
				break;

			str.replace(idx, arr[i].length(), "a");
		}
	}
	cout << str.length();
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
