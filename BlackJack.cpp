#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void shuffle(int card[ ]);				// shuffle;
double player_s_turn(double sum1, int card[ ]);				// player's turn to deal;					
double deal(double sum, int card[ ], int k);				// deal;
double check(int card[ ], int k);				// check;
char check_input(char request);				// check the input;
double computer_s_turn(double sum2, int card[ ], double sum1);				// computer's turn to deal;

int i = 0, j = 0;				// we count the number of cards by using two global variables i, j;
								// however, this may lead to unexpected changes to their values;							
int main()						// i tried to construct a function which returns several values, yet failed, you can improve it;
{					
	int card[52];				// each number represents a card;
	double sum1 = 0, sum2 = 0;					// sum1, sum2 count the sum of cards in player's hands and computer's hands respectively;
	char request;

	shuffle(card);
	sum1 = player_s_turn(sum1, card);
	if (sum1 > 21) cout << endl << "You lose" << endl;
	else sum2 = computer_s_turn(sum2, card, sum1);

	cout << endl << endl << "Play again(y/n): ";

	request = check_input(request);
	while (request == 'y' || request == 'Y') {
	cout << endl << endl; main();			 }

	system("pause");

	return 0;
}

void shuffle(int card[ ])
{
	int num[52], randNum;

	srand(time(NULL));

	for (int k = 0; k < 52; ++k) num[k] = k;
	for (int k = 0; k < 52; ++k) {
		randNum = rand() % (52 - k);
		card[k] = num[randNum];
		num[randNum] = num[51 - k];}				// the same card should not repeat twice;
	
	system("pause");
}

double player_s_turn(double sum1, int card[ ])
{	
	char request;

	cout << "Player's turn to deal" << endl;
	cout << "Cards in player's hands: ";

	for (i = 0; i < 2; ++i)
		sum1 = deal(sum1, card, i); 

	cout << endl << endl << "Do you want another deal(y/n): ";

	request = check_input(request);
	while (request == 'y' || request == 'Y') {
		cout << endl << "Another deal: ";
		for (int k = 0; k < i; ++k)
			check(card, k);		
		sum1 = deal(sum1, card, i++);
		if (sum1 > 21) break;
		else {
			cout << endl << endl << "Do you want another deal(y/n): ";
			request = check_input(request);}  }

	return sum1;
}

double deal(double sum, int card[ ], int k)
{	
	sum += check(card, k);

	return sum;
}

double check(int card[ ], int k)
{	
	double value[52];

	switch (card[k] / 13) {
	case 0: cout << "spades"; break;
	case 1: cout << "hearts"; break;
	case 2: cout << "clubs"; break;
	case 3: cout << "diamonds"; break;
	}
	switch (card[k] % 13) {
	case 0: cout << " Ace "; value[k] = 1; break;
	case 1: cout << " two "; value[k] = 2; break;
	case 2: cout << " three "; value[k] = 3; break;
	case 3: cout << " four "; value[k] = 4; break;
	case 4: cout << " five "; value[k] = 5; break;
	case 5: cout << " six "; value[k] = 6; break;
	case 6: cout << " seven "; value[k] = 7; break;
	case 7: cout << " eight "; value[k] = 8; break;
	case 8: cout << " nine "; value[k] = 9; break;
	case 9: cout << " ten "; value[k] = 10; break;
	case 10: cout << " Jack "; value[k] = 0.5; break;
	case 11: cout << " Queen "; value[k] = 0.5; break;
	case 12: cout << " King "; value[k] = 0.5; break;
	}

	return value[k];
}

char check_input(char request)
{
	cin >> request;

	try {
		if (request != 'y' && request != 'n' && request != 'Y' && request != 'N') throw request;
	} catch (char) {
		cout << endl << "The request is invalid." << endl << " Please enter a new one:";
		request = check_input(request);}				// the computer should only accept four possible inputs;

	return request;
}

double computer_s_turn(double sum2, int card[ ], double sum1)
{
	cout << endl << endl << "Computer's turn to deal" << endl;
	cout << "Cards in computer's hands: ";

	for (j = 0; j < 2; ++j)
		sum2 = deal(sum2, card, i + j);
	while (sum2 < sum1 || sum2 == sum1 && j < i) {
	cout << endl << "Another deal: ";
	for (int k = 0; k < j; ++k)
		check(card, k + i);		
	sum2 = deal(sum2, card, i + j++);			 }
	if (sum2 > 21) {
		cout << endl << endl << "You win" << endl;}
	else if (sum2 == sum1 && j == i) {
		cout << endl << endl << "draw" << endl;		 }
	else {
	cout << endl << endl << "You lose" << endl;}

	return sum2;
}
