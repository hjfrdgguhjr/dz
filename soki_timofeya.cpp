#include <iostream>
int count = 0;

int choice = 0;

int cart_count = 0;

int quantities[9];

std::string product_names[9]{
"Яблочный сок", "Апельсиновый сок", "Абрикосовый сок", "Грушевый сок",
"Томатный сок", "Луковый сок", "Огуречный сок", "Чесночный чай", "Петрушевый чай"
};

int prices[9]{
/*Яблочный сок[0]    */ 110,
/*Апельсиновый сок[1]*/ 120,
/*Абрикосовый сок[2] */ 147,
/*Грушевый сок[3]    */ 130,
/*Томатный сок[4]    */ 170,
/*Луковый сок[5]     */ 100,
/*Огуречный сок[6]   */ 150,
/*Чесночный чай[7]   */ 200,
/*Петрушевый чай[8]  */ 777 
};

void screen_main()
{
    std::cout << "\nВыберите действие:\n";
    std::cout << "1.Фруктовые\n" << "2.Овощные\n" << "3.Чаи\n" << "4.Цены\n" << "5.Корзина\n" << "6.Завершить покупку\n";
}

void screen_fruits()
{
    std::cout << "Выберите сок\n";
    std::cout << "1.Яблочный\n" << "2.Апельсиновый\n" << "3.Абрикосовый\n" << "4.Грушевый\n" << "0.Назад\n";
}

void screen_veges()
{
    std::cout << "Выберите сок\n";
    std::cout << "1.Томатный\n" << "2.Луковый\n" << "3.Огуречный\n" << "0.Назад\n";
}

void screen_tea()
{
    std::cout << "Выберите чай\n";
    std::cout << "1.Чесночный\n" << "2.Петрушевый\n" << "0.Назад\n";
}

void pricelist()
{
    system("cls");
    std::cout << "Фруктовые соки:\n" << "Яблочный сок - " << prices[0] << "\n" << "Апельсиновый сок - " << prices[1] << "\n" << "Абрикосовый сок -" << prices[2] << "\n" << "Грушевый сок - " << prices[3] << "\n\n";
    std::cout << "\nОвощные соки:\n" << "Томатный сок - " << prices[4] << "\n" << "Луковый сок - " << prices[5] << "\n" << "Огуречный сок - " << prices[6] << "\n\n";
    std::cout << "\nЧаи:\n" << "Чесночный чай - " << prices[7] << "\n" << "Петрушечный чай - " << prices[8] << "\n\n";
}

void add_to_cart(int product_index) 
{
    std::cout << "Выберите кол-во товара -> ";
    std::cin >> count;
    quantities[product_index] += count;
    std::cout << "\nДобавлено " << count << " л товара\n\n";
}

void show_cart() {
    system("cls");
    while (true)
    {
        std::cout << "=== ВАША КОРЗИНА ===" << "\n";
        for (int i = 0; i < 9; i++) 
        {
            if (quantities[i] > 0) 
            {
                std::cout << i + 1 << ". " << product_names[i] << ": " << quantities[i] << " л" << "\n";
                cart_count += 1;
            }
        }
        if (cart_count <= 0)
        {
            system("cls");
            std::cout << "Корзина пуста";
            break;
        }
        std::cout << "\n\n1.Удалить выбранную позицию\n";
        std::cout << "2.Выйти\n";
        std::cin >> choice;
        if (choice == 1)
        {
            std::cout << "Введите номер товара для удаления -> ";
            int product_choice;
            std::cin >> product_choice;

            if (product_choice >= 1 && product_choice <= 9) {
                int index = product_choice - 1;
                if (quantities[index] > 0) 
                {
                    quantities[index] = 0;
                    cart_count -= 1;
                    std::cout << "Товар \"" << product_names[index] << "\" удален из корзины." << "\n\n";
                    if (cart_count <= 0)
                    {
                        break;
                    }
                }
                else 
                {
                    std::cout << "Этот товар отсутствует в корзине." << "\n";
                }
            }
            else 
            {
                std::cout << "Неверный номер товара." << "\n";
            }
        }
        else if (choice == 2)
        {
            system("cls");
            break;
        }
    }
}

void final_cost() 
{
    system("cls");
    int cost = 0;
    int total_discount = 0;

    for (int i = 0; i < 9; i++) 
    {
        cost += prices[i] * quantities[i];
    }

    if (quantities[8] >= 3) 
    {
        int discount_petrusha = prices[8] * quantities[8] * 0.05;
        total_discount += discount_petrusha;
        std::cout << "Скидка на петрушечный чай: -" << discount_petrusha << " руб." << "\n";
    }

    if (cost >= 1000)
    {
        int threshold_discount = cost * 0.13;
        total_discount += threshold_discount;
        std::cout << "Скидка при покупке от 1000 рублей: -" << threshold_discount << " руб." << "\n";
    }

    if (quantities[5] >= 4) 
    {
        int free_juice = quantities[5] / 4;
        int discount_onion = free_juice * prices[5];
        total_discount += discount_onion;
        std::cout << "Акция: каждый 4-й литр лукового сока бесплатно! (" << free_juice << " л): -" << discount_onion << " руб." << "\n";
    }

    std::cout << "Общая стоимость: " << cost << " руб." << "\n";
    std::cout << "Общая скидка: " << total_discount << " руб." << "\n";
    std::cout << "Итого к оплате: " << cost - total_discount << " руб." << "\n";
}

int main()
{
    setlocale(LC_ALL, "ru");
    std::cout << "=== Магазин cоки Тимофея ===\n";
    while (true)
    {
        screen_main();
        std::cin >> choice;

        if (choice == 1) 
        {
            system("cls");
            while (true)
            {
                screen_fruits();
                std::cin >> choice;
                if (choice == 0)
                {
                    system("cls");
                    break;
                }
                else if (choice == 1)
                {
                    add_to_cart(0);
                }
                else if (choice == 2)
                {
                    add_to_cart(1);
                }
                else if (choice == 3)
                {
                    add_to_cart(2);
                }
                else if (choice == 4)
                {
                    add_to_cart(3);
                }
                else
                {
                    std::cout << "Неверный выбор!\n";
                }
            }
        }
        else if (choice == 2) 
        {
            system("cls");
            while (true)
            {
                screen_veges();
                std::cin >> choice;
                if (choice == 0)
                {
                    system("cls");
                    break;
                }
                else if (choice == 1)
                {
                    add_to_cart(4);
                }
                else if (choice == 2)
                {
                    add_to_cart(5);
                }
                else if (choice == 3)
                {
                    add_to_cart(6);
                }
                else
                {
                    std::cout << "Неверный выбор!\n";
                }
            }
        }
        else if (choice == 3) 
        {
            system("cls");
            while (true)
            {
                screen_tea();
                std::cin >> choice;
                if (choice == 0)
                {
                    system("cls");
                    break;
                }
                else if (choice == 1)
                {
                    add_to_cart(7);
                }
                else if (choice == 2)
                {
                    add_to_cart(8);
                }
                else
                {
                    std::cout << "Неверный выбор!\n";
                }
            }
        }
        else if (choice == 4) 
        {
            pricelist();
        }
        else if (choice == 5) 
        {
            show_cart();
        }
        else if (choice == 6)
        {
            final_cost();
            break;
        }
        else
        {
            std::cout << "\nНекорректно введенное число\n";
        }
    }
    return 0;
}