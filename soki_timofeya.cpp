#include <iostream>
int count = 0;

int choice = 0;

int cart_count = 0;

int quantities[9];

std::string product_names[9]{
"�������� ���", "������������ ���", "����������� ���", "�������� ���",
"�������� ���", "������� ���", "��������� ���", "��������� ���", "���������� ���"
};

int prices[9]{
/*�������� ���[0]    */ 110,
/*������������ ���[1]*/ 120,
/*����������� ���[2] */ 147,
/*�������� ���[3]    */ 130,
/*�������� ���[4]    */ 170,
/*������� ���[5]     */ 100,
/*��������� ���[6]   */ 150,
/*��������� ���[7]   */ 200,
/*���������� ���[8]  */ 777 
};

void screen_main()
{
    std::cout << "\n�������� ��������:\n";
    std::cout << "1.���������\n" << "2.�������\n" << "3.���\n" << "4.����\n" << "5.�������\n" << "6.��������� �������\n";
}

void screen_fruits()
{
    std::cout << "�������� ���\n";
    std::cout << "1.��������\n" << "2.������������\n" << "3.�����������\n" << "4.��������\n" << "0.�����\n";
}

void screen_veges()
{
    std::cout << "�������� ���\n";
    std::cout << "1.��������\n" << "2.�������\n" << "3.���������\n" << "0.�����\n";
}

void screen_tea()
{
    std::cout << "�������� ���\n";
    std::cout << "1.���������\n" << "2.����������\n" << "0.�����\n";
}

void pricelist()
{
    system("cls");
    std::cout << "��������� ����:\n" << "�������� ��� - " << prices[0] << "\n" << "������������ ��� - " << prices[1] << "\n" << "����������� ��� -" << prices[2] << "\n" << "�������� ��� - " << prices[3] << "\n\n";
    std::cout << "\n������� ����:\n" << "�������� ��� - " << prices[4] << "\n" << "������� ��� - " << prices[5] << "\n" << "��������� ��� - " << prices[6] << "\n\n";
    std::cout << "\n���:\n" << "��������� ��� - " << prices[7] << "\n" << "����������� ��� - " << prices[8] << "\n\n";
}

void add_to_cart(int product_index) 
{
    std::cout << "�������� ���-�� ������ -> ";
    std::cin >> count;
    quantities[product_index] += count;
    std::cout << "\n��������� " << count << " � ������\n\n";
}

void show_cart() {
    system("cls");
    while (true)
    {
        std::cout << "=== ���� ������� ===" << "\n";
        for (int i = 0; i < 9; i++) 
        {
            if (quantities[i] > 0) 
            {
                std::cout << i + 1 << ". " << product_names[i] << ": " << quantities[i] << " �" << "\n";
                cart_count += 1;
            }
        }
        if (cart_count <= 0)
        {
            system("cls");
            std::cout << "������� �����";
            break;
        }
        std::cout << "\n\n1.������� ��������� �������\n";
        std::cout << "2.�����\n";
        std::cin >> choice;
        if (choice == 1)
        {
            std::cout << "������� ����� ������ ��� �������� -> ";
            int product_choice;
            std::cin >> product_choice;

            if (product_choice >= 1 && product_choice <= 9) {
                int index = product_choice - 1;
                if (quantities[index] > 0) 
                {
                    quantities[index] = 0;
                    cart_count -= 1;
                    std::cout << "����� \"" << product_names[index] << "\" ������ �� �������." << "\n\n";
                    if (cart_count <= 0)
                    {
                        break;
                    }
                }
                else 
                {
                    std::cout << "���� ����� ����������� � �������." << "\n";
                }
            }
            else 
            {
                std::cout << "�������� ����� ������." << "\n";
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
        std::cout << "������ �� ����������� ���: -" << discount_petrusha << " ���." << "\n";
    }

    if (cost >= 1000)
    {
        int threshold_discount = cost * 0.13;
        total_discount += threshold_discount;
        std::cout << "������ ��� ������� �� 1000 ������: -" << threshold_discount << " ���." << "\n";
    }

    if (quantities[5] >= 4) 
    {
        int free_juice = quantities[5] / 4;
        int discount_onion = free_juice * prices[5];
        total_discount += discount_onion;
        std::cout << "�����: ������ 4-� ���� �������� ���� ���������! (" << free_juice << " �): -" << discount_onion << " ���." << "\n";
    }

    std::cout << "����� ���������: " << cost << " ���." << "\n";
    std::cout << "����� ������: " << total_discount << " ���." << "\n";
    std::cout << "����� � ������: " << cost - total_discount << " ���." << "\n";
}

int main()
{
    setlocale(LC_ALL, "ru");
    std::cout << "=== ������� c��� ������� ===\n";
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
                    std::cout << "�������� �����!\n";
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
                    std::cout << "�������� �����!\n";
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
                    std::cout << "�������� �����!\n";
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
            std::cout << "\n����������� ��������� �����\n";
        }
    }
    return 0;
}