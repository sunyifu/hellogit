#include <cstdlib>			//����������������������׼���У�
#include <ctime>			//����ϵͳʱ�亯���������׼���У�
#include <iostream>
using namespace std;

char check_input(char request);

int main()
{
	int num[6], n = 0, w = 0, i, j, k;			//����һ�������������飬��n��w�ֱ��ʾ���Ӯ�ľ�����
	char request;							

	srand(time(NULL));							//������������ӣ�

	num[0] = rand() % 10;						//��������0��9�Ĳ�ͬ�������
	do {
		num[1] = rand() % 10;					
	} while (num[1] == num[0]);
	do {
		num[2] = rand() % 10;
	   } while (num[2] == num[0] || num[2] == num[1]);

	cout << "��Ҫ����Ϸ��Y/N��? ";

	request = check_input(request);
	while (request == 'Y' || request == 'y') {
	++n;
	for (i = 0; i < 7; ++i) {						//���ÿ����Ϸֻ���ߴλ��᣻
	cout << "��������²�����֣�";
	cin >> num[3] >> num[4] >> num[5];

	int count1 = 0, count2 = 0;						//count1,count2�ֱ����������ȷ��λ����ȷ�����ָ�����������ȷ��λ�ò���ȷ�����ָ�����

	for (j = 0; j < 3; ++j) {
	if (num[j+3] == num[j]) ++count1;
	else {
		for (k = 0; k < 3; ++k) {
		if (num[j+3] == num[k]) ++count2;
								}
		 }
						   }
	if (count1 == 3) {							//�����Ϊ3A0Bʱ�����Ӯ�������Ϸ��
	++w; break;
					 }
	else cout << count1 << 'A' << count2 << 'B' << endl;
						   }
	if (i == 7) cout << "���ź�����û���ڹ涨�����ڲ¶ԡ�����" << num[0] << num[1] << num[2];
	else cout << "��ϲ����¶���" << endl;

	cout << "��Ҫ����Ϸ��Y/N��? ";

	request = check_input(request);}
	cout << "��һ������" << n << "�֣�Ӯ��" << w << "�֣�����" << n-w << "��" << endl;		//�����ҵ���Ϸ�����

	system("pause");

	return 0;
}

char check_input(char request)
{
	cin >> request;

	try {
		if (request != 'Y' && request != 'N' && request != 'y' && request != 'n') throw request;
	} catch (char) {
		cout << endl << "The request is invalid." << endl << " Please enter a new one:";
		request = check_input(request);}				// the computer should only accept four possible inputs;

	return request;
}