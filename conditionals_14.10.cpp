#include <iostream>

int main()
{
	setlocale(LC_ALL, "RU");
	int num;
	std::cout << "Задание 1\n";
	std::cout << "Введите шестизначное число -> ";
	std::cin >> num;
	int fhalf = num / 1000;
	int shalf = num % 1000;
	int fsum = (fhalf / 100) + (fhalf / 10 % 10) + (fhalf % 10);
	int ssum = (shalf / 100) + (shalf / 10 % 10) + (shalf % 10);
	if (num < 100000 || num > 999999)
	{
		std::cout << "число не шестизначное" << "\n";
	}

	if (fsum == ssum) 
	{
		std::cout << "счастливое число" << "\n";
	}
	else 
	{
		std::cout << "не счастливое число" << "\n";
	}





	std::cout << "Задание 2\n";
	std::cout << "Введите четырехзначное число -> ";
	std::cin >> num;

	if (num < 1000 || num > 9999) 
	{
		std::cout << "число не четырехзначное!" << "\n";
	}

	int d1 = num / 1000;
	int d2 = (num / 100) % 10;
	int d3 = (num / 10) % 10;
	int d4 = num % 10;

	int NewNum = d2 * 1000 + d1 * 100 + d4 * 10 + d3;
	std::cout << "результат: " << NewNum << "\n";





	std::cout << "Задание 3\n";
	int MaxNum;
	std::cout << "Введите 7 целых чисел:" << "\n";
	std::cin >> MaxNum;

	for (int i = 1; i < 7; i++) 
	{
		std::cin >> num;
		if (num > MaxNum)
		{
			MaxNum = num;
		}
	}
	std::cout << "Максимальное число: " << MaxNum << "\n";
	return 0;
}
