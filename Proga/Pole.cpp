#include <iostream>
#include <conio.h>
#include "audiere-1.9.4-win32\include\audiere.h"
#include <Windows.h>

using namespace std;

using namespace audiere;


int main()
{
	setlocale(0, "Russian");

	cout << "Играйте клавишами 1,2,3.	||	S-stop	||	X-ext - для выхода" << endl;
	AudioDevicePtr device = OpenDevice();

	OutputStreamPtr one = OpenSound(device, "Kalimba.mp3", false); //здесь мы начинаем создание потоков со звуками определённой высоты
	OutputStreamPtr two = OpenSound(device, "Maid with the Flaxen Hair.mp3", false);
	OutputStreamPtr there = OpenSound(device, "Sleep Away.mp3", false);
	 //заканчиваем октавой - вновь нота до, но уже следующей октавы

	char key ='0';

	while (key != 'x' || key != 'ч') //цикл выполняется, пока не нажата клавиша "x"
	{
		key = _getch();
		if (key == 27) return 0;
		if (key == '1') one->play();
		if (key == '2') two->play();
		if (key == '3') there->play();
		if (key == 's' || key == 'ы'){
			one->stop();
			two->stop();
			there->stop();
		}
	}
	return 0;
}