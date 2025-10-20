#include <iostream>

int main() 
{
    setlocale(LC_ALL, "RU");
    std::cout << "Задание 1\n";
    const int size = 10;
    int arr[size];
    std::cout << "Введите " << size << " элементов массива:" << "\n";
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
    std::cout << "Минимальный элемент: " << min << "\n";
    std::cout << "Максимальный элемент: " << max << "\n";





    std::cout << "Задание 2\n";
    int userValue;
    std::cout << "Введите " << size << " элементов массива:" << "\n";
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << "Введите значение для сравнения: ";
    std::cin >> userValue;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < userValue) 
        {
            sum += arr[i];
        }
    }
    std::cout << "Сумма элементов меньше " << userValue << ": " << sum << "\n";




    std::cout << "Задание 3\n";
    const int MONTHS = 12;
    double profit[MONTHS];
    int startMonth, endMonth;
    std::cout << "Введите прибыль фирмы за 12 месяцев:" << "\n";
    for (int i = 0; i < MONTHS; i++) 
    {
        std::cout << "Месяц " << (i + 1) << ": ";
        std::cin >> profit[i];
    }
    std::cout << "Введите начальный месяц диапазона (1-12): ";
    std::cin >> startMonth;
    std::cout << "Введите конечный месяц диапазона (1-12): ";
    std::cin >> endMonth;
    if (startMonth < 1 || startMonth > 12 || endMonth < 1 || endMonth > 12 || startMonth > endMonth) 
    {
        std::cout << "Ошибка: некорректный диапазон!" << "\n";
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
    std::cout << "\nРезультаты анализа:" << "\n";
    std::cout << "Минимальная прибыль в месяце: " << (minMonth + 1) << " (" << profit[minMonth] << ")" << "\n";
    std::cout << "Максимальная прибыль в месяце: " << (maxMonth + 1) << " (" << profit[maxMonth] << ")" << "\n";
    return 0;
}
