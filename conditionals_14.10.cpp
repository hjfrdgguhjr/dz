#include <iostream>

int main()
{
	setlocale(LC_ALL, "RU");
	int num;
	std::cout << "������� 1\n";
	std::cout << "������� ������������ ����� -> ";
	std::cin >> num;
	int fhalf = num / 1000;
	int shalf = num % 1000;
	int fsum = (fhalf / 100) + (fhalf / 10 % 10) + (fhalf % 10);
	int ssum = (shalf / 100) + (shalf / 10 % 10) + (shalf % 10);
	if (num < 100000 || num > 999999)
	{
		std::cout << "����� �� ������������" << "\n";
	}

	if (fsum == ssum) 
	{
		std::cout << "���������� �����" << "\n";
	}
	else 
	{
		std::cout << "�� ���������� �����" << "\n";
	}





	std::cout << "������� 2\n";
	std::cout << "������� �������������� ����� -> ";
	std::cin >> num;

	if (num < 1000 || num > 9999) 
	{
		std::cout << "����� �� ��������������!" << "\n";
	}

	int d1 = num / 1000;
	int d2 = (num / 100) % 10;
	int d3 = (num / 10) % 10;
	int d4 = num % 10;

	int NewNum = d2 * 1000 + d1 * 100 + d4 * 10 + d3;
	std::cout << "���������: " << NewNum << "\n";





	std::cout << "������� 3\n";
	int MaxNum;
	std::cout << "������� 7 ����� �����:" << "\n";
	std::cin >> MaxNum;

	for (int i = 1; i < 7; i++) 
	{
		std::cin >> num;
		if (num > MaxNum)
		{
			MaxNum = num;
		}
	}
	std::cout << "������������ �����: " << MaxNum << "\n";
	return 0;
}