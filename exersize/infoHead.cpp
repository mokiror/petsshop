#include "infoHead.hpp"


void DataBase(int SIZE, int id[], std::string name[], int count[], double price[])
{
	std::cout << "\n" << std::endl;
	std::cout << "�����\t" "Id\t" << "��������\t" << "   \t���-��\t" << "   \t����\t" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << id[i] << ") \t";
		std::cout << id[i] << "\t" << name[i];
		std::cout << " \t\t" << count[i];
		std::cout << " \t\t" << price[i] << std::endl;
	}
}