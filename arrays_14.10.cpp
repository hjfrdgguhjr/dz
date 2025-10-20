#include <iostream>

int main() 
{
    setlocale(LC_ALL, "RU");
    std::cout << "������� 1\n";
    const int size = 10;
    int arr[size];
    std::cout << "������� " << size << " ��������� �������:" << "\n";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min) 
        {
            min = arr[i];
        }
        if (arr[i] > max) 
        {
            max = arr[i];
        }
    }
    std::cout << "����������� �������: " << min << "\n";
    std::cout << "������������ �������: " << max << "\n";





    std::cout << "������� 2\n";
    int userValue;
    std::cout << "������� " << size << " ��������� �������:" << "\n";
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << "������� �������� ��� ���������: ";
    std::cin >> userValue;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < userValue) 
        {
            sum += arr[i];
        }
    }
    std::cout << "����� ��������� ������ " << userValue << ": " << sum << "\n";




    std::cout << "������� 3\n";
    const int MONTHS = 12;
    double profit[MONTHS];
    int startMonth, endMonth;
    std::cout << "������� ������� ����� �� 12 �������:" << "\n";
    for (int i = 0; i < MONTHS; i++) 
    {
        std::cout << "����� " << (i + 1) << ": ";
        std::cin >> profit[i];
    }
    std::cout << "������� ��������� ����� ��������� (1-12): ";
    std::cin >> startMonth;
    std::cout << "������� �������� ����� ��������� (1-12): ";
    std::cin >> endMonth;
    if (startMonth < 1 || startMonth > 12 || endMonth < 1 || endMonth > 12 || startMonth > endMonth) 
    {
        std::cout << "������: ������������ ��������!" << "\n";
    }
    int minMonth = startMonth - 1;
    int maxMonth = startMonth - 1;
    for (int i = startMonth - 1; i <= endMonth - 1; i++) 
    {
        if (profit[i] < profit[minMonth]) 
        {
            minMonth = i;
        }
        if (profit[i] > profit[maxMonth]) 
        {
            maxMonth = i;
        }
    }
    std::cout << "\n���������� �������:" << "\n";
    std::cout << "����������� ������� � ������: " << (minMonth + 1) << " (" << profit[minMonth] << ")" << "\n";
    std::cout << "������������ ������� � ������: " << (maxMonth + 1) << " (" << profit[maxMonth] << ")" << "\n";
    return 0;
}