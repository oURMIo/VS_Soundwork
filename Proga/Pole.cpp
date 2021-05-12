#include <iostream>
#include <conio.h>
#include "audiere-1.9.4-win32\include\audiere.h"
#include <Windows.h>

using namespace std;

using namespace audiere;


int main()
{
	setlocale(0, "Russian");

	cout << "������� ��������� 1,2,3.	||	S-stop	||	X-ext - ��� ������" << endl;
	AudioDevicePtr device = OpenDevice();

	OutputStreamPtr one = OpenSound(device, "Kalimba.mp3", false); //����� �� �������� �������� ������� �� ������� ����������� ������
	OutputStreamPtr two = OpenSound(device, "Maid with the Flaxen Hair.mp3", false);
	OutputStreamPtr there = OpenSound(device, "Sleep Away.mp3", false);
	 //����������� ������� - ����� ���� ��, �� ��� ��������� ������

	char key ='0';

	while (key != 'x' || key != '�') //���� �����������, ���� �� ������ ������� "x"
	{
		key = _getch();
		if (key == 27) return 0;
		if (key == '1') one->play();
		if (key == '2') two->play();
		if (key == '3') there->play();
		if (key == 's' || key == '�'){
			one->stop();
			two->stop();
			there->stop();
		}
	}
	return 0;
}