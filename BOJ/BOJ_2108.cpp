// BOJ_2108.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int arr[8001];

using namespace std;
int main()
{
	int x;
	cin >> x;

	int sum = 0;
	int index = 0;
	int max = 0;
	vector<int> list;
	for (int i = 0; i < x; i++)
	{
		int num;
		cin >> num;
		sum += num;

		if (num <= 0)
			index = -num;
		else
			index = 4000 + num;

		arr[index]++;

		if (arr[index] > max)
			max = arr[index];

		list.push_back(num);
	}

	// 평균, 소수점 이하 첫째 자리 반올림
	float avg = sum / (float)x;
	cout << round(avg) << '\n';

	// 중앙값
	sort(list.begin(), list.end());
	cout << list[list.size()/2] << '\n';

	// 최빈값
	//#1
	bool flag = false;
	int result = 0;
	for (int i = -4000; i < 4001; i++)
	{
		if (i <= 0)
			index = -i;
		else
			index = 4000 + i;

		if (arr[index] == max)
		{
			result = i;

			if (flag)
				break;
			flag = true;
		}
	}

	//#2
	//int curNum = 8000;
	//int curCount = 1;
	//int result = 0;
	//int minCount = 0;
	//int sameCount = 0;
	//for (int i = 0; i < list.size(); i++)
	//{
	//	if (list[i] != curNum)
	//	{
	//		curNum = list[i];
	//		curCount = 1;
	//	}
	//	else if (list[i] == curNum)
	//	{
	//		curCount++;
	//	}

	//	if (curCount > minCount)
	//	{
	//		minCount = curCount;
	//		result = list[i];
	//		sameCount = 0;
	//	}
	//	else if (curCount == minCount && sameCount < 1)
	//	{
	//		sameCount++;
	//		result = list[i];
	//	}
	//}

	cout << result << '\n';

	// 범위
	cout << list[list.size() - 1] - list[0];
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
