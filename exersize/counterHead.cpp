#include "counterHead.hpp"
#include "infoHead.hpp"

int id01 = 1;
std::string id01Name = "Собачий корм";
int id01Count = 20;
double id01Price = 2000.0;

int id02 = 2;
std::string id02Name = "Кошачий корм";
int id02Count = 20;
double id02Price = 2000.0;

int id03 = 3;
std::string id03Name = "Пищалка";
int id03Count = 6;
double id03Price = 180.0;

int id04 = 4;
std::string id04Name = "Кошачья мята";
int id04Count = 10;
double id04Price = 300.0;

int id05 = 5;
std::string id05Name = "Шлейка     ";
int id05Count = 5;
double id05Price = 250.0;

int id06 = 6;
std::string id06Name = "Ошейник";
int id06Count = 7;
double id06Price = 350.0;

int id07 = 7;
std::string id07Name = "Вкусняшки";
int id07Count = 15;
double id07Price = 200.0;

int id08 = 8;
std::string id08Name = "Косточки";
int id08Count = 8;
double id08Price = 50.0;

int id09 = 9;
std::string id09Name = "Костюм     ";
int id09Count = 13;
double id09Price = 2500.0;

int id10 = 10;
std::string id10Name = "Игрушка";
int id10Count = 4;
double id10Price = 450.0;



const int SIZE = 10;
int arrId[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
std::string arrName[SIZE] = { "Собачий корм", "Кошачий корм", "Пищалка", "Кошачья мята",
"Шлейка     ", "Ошейник", "Вкусняшки", "Косточки", "Костюм     ", "Игрушка" };
int arrCount[SIZE] = { 20, 20, 6, 10, 5, 7, 15, 8, 13, 4 };
double arrPrice[SIZE] = { 2000.0, 2000.0, 180.0, 300.0, 250.0, 350.0, 200.0, 50.0, 2500.0, 450.0 };

int checkId = 0;


void Refill(int id, int count01)
{
	std::cout << "Количество товара " << arrName[id - 1] << "до: " << arrCount[id - 1] << std::endl;
	arrCount[id - 1] += count01;
	std::cout << "Количество товара " << arrName[id - 1] << " после: " << arrCount[id - 1] << std::endl;
}
void Return(int id, int count01)
{
	std::cout << "Количество товара " << arrName[id - 1] << " до: " << arrCount[id - 1] << std::endl;
	arrCount[id - 1] -= count01;
	std::cout << "Количество товара " << arrName[id - 1] << " после: " << arrCount[id - 1] << std::endl;
}
void NewPrice(int id, double newPrice01)
{
	std::cout << "\nЦена товара " << arrName[id - 1] << " до: " << arrPrice[id - 1] << std::endl;
	arrPrice[id - 1] = newPrice01;
	std::cout << "Цена товара " << arrName[id - 1] << " после: " << arrPrice[id - 1] << std::endl;
}
void Purchase(double& totalSumm)
{
	std::cout << "\n\t\t   Начало покупки\n";


	int currentId = 0, currentCount = 0;
	int choice = -1;
	int* checkId;
	std::string* checkName;
	double* checkPrice;
	double* checkOnePrice;
	int checkSize = 0;
	int* checkCount;

	std::cout << "Введите кол-во товаров: \n";
	std::cin >> checkSize;
	checkId = new int[checkSize];
	checkName = new std::string[checkSize];
	checkPrice = new double[checkSize];
	checkCount = new int[checkSize];
	checkOnePrice = new double[checkSize];



	for (int i = 0; i < checkSize; i++)
	{
		do
		{
			std::cout << "\nВведите id товара: " << std::endl;
			std::cin >> currentId;
			std::cout << "Введите кол-во товара: " << std::endl;
			std::cin >> currentCount;
			Return(currentId, currentCount);
		} while ((currentId < 1 || currentId > 10) || (currentCount > arrCount[currentId - 1] && currentCount < 1));


		totalSumm += arrPrice[currentId - 1] * currentCount;

		checkId[i] = currentId;
		checkName[i] = arrName[currentId - 1];
		checkCount[i] = currentCount;
		checkOnePrice[i] = arrPrice[currentId - 1];
		checkPrice[i] = arrPrice[currentId - 1] * currentCount;
	}

	std::cout << "\nЧек: \n" << std::endl;
	std::cout << "Id\t" << "Название\t" << "   \tКол-во\t" << "    \tЦeна за 1 товар\t" << "   \tЦена\t" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < checkSize; i++)
	{
		std::cout << checkId[i] <<
			"\t" << checkName[i];
		std::cout << " \t\t" << checkCount[i];
		std::cout << "     \t\t" << checkOnePrice[i];
		std::cout << "                \t" << checkPrice[i] << std::endl;

	}

	delete[]checkId;
	delete[]checkName;
	delete[]checkPrice;
	delete[]checkOnePrice;
	delete[]checkCount;
	totalSumm == 0;

}
void Tester(double& count)
{
	std::cout << "\nTotal summ: " << count;
}
void MainMenu(double& totalSumm)
{
	while (true)
	{
		int choice = -1;
		int idd = 0, countt = 0, newPrice = 0;
		do
		{

			std::cout << "\n\t\t\tPet-Shop ^ *3* ^\n" << std::endl;
			std::cout << "1) - Начать продажу\n";
			std::cout << "2) - Показать склад\n";
			std::cout << "3) - Пополнить склад\n";
			std::cout << "4) - Уменьшить склад\n";
			std::cout << "5) - Изменить цену\n";
			std::cout << "0) - Выход\n\n";
			std::cout << "Ввод: ";
			std::cin >> choice;

			if (choice == 1)
			{
				Purchase(totalSumm);
				Tester(totalSumm);

			}
			else if (choice == 2)
			{
				DataBase(SIZE, arrId, arrName, arrCount, arrPrice);
			}
			else if (choice == 3)
			{
				system("cls");
				std::cout << "\t\t\tПополнение склада\n\n";
				std::cout << "Введите id товара : ";
				std::cin >> idd;
				std::cout << "Введите кол-во товара : ";
				std::cin >> countt;
				if (countt >= 0)
				{
					Refill(idd, countt);
				}
				else
				{
					std::cerr << "Ошибка ввода !" << std::endl;
				}
				std::cout << "\n\n";
			}
			else if (choice == 4)
			{
				system("cls");
				std::cout << "\t\t\tУменьшение склада\n\n";
				std::cout << "Введите id товара : ";
				std::cin >> idd;
				std::cout << "Введите кол-во товара : ";
				std::cin >> countt;
				if (countt <= arrCount[idd - 1] && countt >= 0)
				{
					Return(idd, countt);
				}
				else
				{
					std::cerr << "Ошибка ввода !" << std::endl;
				}
				std::cout << "\n\n";
			}
			else if (choice == 5)
			{
				system("cls");
				std::cout << "\t\t\tИзменение цены\n\n";
				std::cout << "Введите id товара : ";
				std::cin >> idd;
				std::cout << "Введите новую цену товара : ";
				std::cin >> newPrice;
				if (newPrice >= 0)
				{
					NewPrice(idd, newPrice);
				}
				else
				{
					std::cerr << "Ошибка ввода !" << std::endl;
				}
				std::cout << "\n\n";
			}
			else if (choice == 0)
			{
				std::cout << "\t\t\tПока !\n\n";
				break;
			}

		} while (0 <= choice && choice < 6);

		break;

	}

}
