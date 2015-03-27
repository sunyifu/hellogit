#include <cstdlib>			//随机数生成器函数在这个标准库中；
#include <ctime>			//调用系统时间函数在这个标准库中；
#include <iostream>
using namespace std;

void main()
{
	int num[6], n = 0, w = 0, i, j, k;			//定义一个六个数的数组，用n和w分别表示玩和赢的局数；
	char request;							

	srand(time(NULL));							//生成随机数种子；

	num[0] = rand() % 10;						//生成三个0到9的不同随机数；
	do {
		num[1] = rand() % 10;					
	} while (num[1] == num[0]);
	do {
		num[2] = rand() % 10;
	   } while (num[2] == num[0] || num[2] == num[1]);

	cout << "需要玩游戏吗（Y/N）? ";			
	cin >> request;

	while (request == 'Y') {
	++n;
	for (i = 0; i < 7; ++i) {						//玩家每局游戏只有七次机会；
	cout << "请输入你猜测的数字：";
	cin >> num[3] >> num[4] >> num[5];

	int count1 = 0, count2 = 0;						//count1,count2分别计数数字正确且位置正确的数字个数和数字正确但位置不正确的数字个数；

	for (j = 0; j < 3; ++j) {
	if (num[j+3] == num[j]) ++count1;
	else {
		for (k = 0; k < 3; ++k) {
		if (num[j+3] == num[k]) ++count2;
								}
		 }
						   }
	if (count1 == 3) {							//当结果为3A0B时，玩家赢得这局游戏；
	++w; break;
					 }
	else cout << count1 << 'A' << count2 << 'B' << endl;
						   }
	if (i == 7) cout << "很遗憾，你没有在规定次数内猜对。答案是" << num[0] << num[1] << num[2];
	else cout << "恭喜，你猜对了" << endl;
	cout << "需要玩游戏吗（Y/N）? ";
	cin >> request;
						  }
	if (request == 'N') cout << "你一共玩了" << n << "局，赢了" << w << "局，输了" << n-w << "局";		//输出玩家的游戏结果；
	else cout << "输入有误！";				//输入检查；
	
	system("pause");
}
