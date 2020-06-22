// BOJ_1427.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//!< 소트인사이드
//!< 목표 25분 : 결과 8분 50초 : 20.06.22 : 1트 - 처음에 무식하게 나눗셈 및 선택 정렬로 풀어본 결과, 재귀로 변경할 수 있을 것 같아 변경하였다. string으로 푸는 방법도 있다.
using namespace std;

//!< 재귀
vector<int> vec;
void RecursiveMethod( int quotient )
{
	int remainder = 0; //!< 나머지
	remainder = quotient % 10;
	vec.push_back( remainder );
	quotient = quotient / 10;

	if ( quotient > 0 )
		RecursiveMethod( quotient );
}

//!< sort 내림차순
bool Desc( int a, int b )
{
	return a > b;
}

//!< 재귀 + sort 기존 알고리즘 이용
void RecursiveSort()
{
	int x;
	cin >> x;
	RecursiveMethod( x );
	sort( vec.begin(), vec.end(), Desc );
}

//!< 선택정렬 + 나눗셈
void Division()
{
	int x;
	cin >> x;

	int quotient = x; //!< 몫
	int remainder; //!< 나머지

	while ( quotient > 0 )
	{
		remainder = quotient % 10;
		vec.push_back( remainder );
		quotient = quotient / 10;
	}

	for ( int i = 0; i < vec.size(); i++ )
	{
		for ( int j = i + 1; j < vec.size(); j++ )
		{
			if ( vec[ i ] < vec[ j ] )
			{
				int temp = 0;
				temp = vec[ i ];
				vec[ i ] = vec[ j ];
				vec[ j ] = temp;
			}
		}
	}
}

//!< 문자열 이용
void GetStringResult()
{
	string n;
	cin >> n;
	for ( int i = 9; i >= 0; i-- )
	{
		for ( char x : n )
		{
			if ( x - '0' == i ) //!<  x - '0' : char -> int 형 변환
				cout << i;
		}
	}
}

int main()
{
	//!< 선택정렬 + 나눗셈
	Division();
	
	//!< 재귀 + sort 기존 알고리즘 이용
	RecursiveSort();

	for ( int i = 0; i < vec.size(); i++ )
	{
		cout << vec[ i ];
	}

	//!< 스트링 이용
	GetStringResult();
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
