#include <iostream>
#include <locale>
#include <fstream>
#include <conio.h>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

#define N 5

using namespace std;

//percussion per_buf;
//string file;
//ofstream f;			///открытие файла для записи
//ifstream in;		///открытие файла для чтения

class orchestra
{
private:
	char name[20]; //название инстр
	int cost; //стоимость инстр
	int num_of_orch; //кол-во в оркестре
	char owner[30]; //ФИО владельца
public:
	orchestra() {
		name[0] = '\0';
		cost = NULL;
		num_of_orch = NULL;
		owner[0] = '\0';
		cout << "!cnstr!";
	}

	orchestra(char *_name, int _cost, int _num_of_orch, char *_owner) {
		strcpy_s(name, _name);
		cost = _cost;
		num_of_orch = _num_of_orch;
		strcpy_s(owner, _owner);
	}

	void set_orch() {
		setlocale(LC_ALL, "Russian");
		cout << "\n Введите название инструмента:\t";
		cin >> this->name;
		cout << "\n Введите стоимость :\t";
		cin >> this->cost;
		cout << "\n Введите количество инструментов в оркестре:\t";
		cin >> this->num_of_orch;
		cout << "\n Введите имя владельца:\t";
		cin >> this->owner;
	}

	void put_name() {
		setlocale(LC_ALL, "Russian");
		cout << "\n Название инструмента:\t" << name;
	}
	void put_cost() {
		setlocale(LC_ALL, "Russian");
		cout << "\n Название инструмента:\t" << cost;
	}
	void put_num_of_orch() {
		setlocale(LC_ALL, "Russian");
		cout << "\n Название инструмента:\t" << num_of_orch;
	}
	void put_owner() {
		setlocale(LC_ALL, "Russian");
		cout << "\n Название инструмента:\t" << owner;
	}

	void put_orch() {
		setlocale(LC_ALL, "Russian");
		cout << "\n Название инструмента:\t" << name;
		cout << "\n Стоимость:\t\t" << cost;
		cout << "\n Количество в оркестре:\t" << num_of_orch;
		cout << "\n Имя владельца:\t\t" << owner;
	}

	char* ret_name() {
		return name;
	}

	char* ret_owner() {
		return owner;
	}

	virtual ~orchestra();
};

orchestra::~orchestra() { cout << "!dstrctr!"; }

class percussion : public orchestra //ударные
{
private:
	char type[20];
public:
	percussion() { type[0] = '\0'; cout << "!percussion!";}
	percussion(char *_name, int _cost, int _num_of_orch, char *_owner, char *_type) {
		orchestra::orchestra(_name, _cost, _num_of_orch, _owner);
		strcpy_s(type, _type);
	}

	void set_per(){
		orchestra::set_orch();
		cout << "\nТип инструмента:\t";
		cin >> this->type;
	}

	void put_per() {
		orchestra::put_orch();
		cout << "\n Тип инструмента:\t" << type << endl;
	}

	percussion& operator +(const percussion &pr) {
		pr.put_per();
		return *this;
	}

	~percussion() { cout << "!destr_percussion!"; }
};

class stringed : public orchestra///краткое описание - НЕОБХОДИМО СОХДАТЬ ДИНАМИЧЕСКУЮ ПАМЯТЬ
{
private:
	string manufact; //наименование производителя
	string description; ///краткое описание - НЕОБХОДИМО СОХДАТЬ ДИНАМИЧЕСКУЮ ПАМЯТЬ
	//общие характеристики
	string name; //название инстр
	string cost; //стоимость инстр
	int num_of_orch; //кол-во в оркестре
	string owner; //ФИО владельца
public:
	stringed()
	{

	}
	void comp_amount()
	{
	}
	~stringed() override { cout << "stringed"; }
};

class wind : public orchestra///краткое описание - НЕОБХОДИМО СОЗДАТЬ ДИНАМИЧЕСКУЮ ПАМЯТЬ
{
private:
	string description; //краткое описание
	string defects; //описание дефектов на инструменте
	//общие характеристики
	string name; //название инстр
	string cost; //стоимость инстр
	int num_of_orch; //кол-во в оркестре
	string owner; //ФИО владельца
public:
	wind()
	{
	}
	void comp_amount()
	{
	}
	~wind() override { cout << " "; }
};

int main()
{
	setlocale(LC_ALL, "Rus");

			  /////////////////////////
			 /*ПОЛЬЗОВАТЕЛЬСКОЕ МЕНЮ*/
			/////////////////////////
	
	ofstream f;			///открытие файла для записи
	ifstream in;		///открытие файла для чтения

	percussion *per;
	percussion per_buf;
	
	string file;
	char name[20];
	char FIO[30];
	
	int swtch1 = 1;

	while (swtch1 != 0) {
		cout << "Выберите действие:" << endl << 
			"|1| <-> Вывести все данные оркестра на экран" << endl <<
			"|2| <-> Просмотр и редактирование данных инструментов конкретного типа" << endl << 
			"|0| <-> Выход" << endl;
		cin >> swtch1;
		switch (swtch1)
		{
		case 1: /*Вывести все данные оркестра на экран*/
			cout << "Данные каких инструментов вывести на экран?" << endl <<
				"|1| <-> Духовые инструменты" << endl <<
				"|2| <-> Струнные инструменты" << endl <<
				"|3| <-> Ударные инструменты" << endl <<
				"|4| <-> Вывести всю базу данных на экран" << endl;
			cin >> swtch1;
			switch (swtch1)
			{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			default:
				break;
			}
			break;
		case 2:
			cout << "Выберите тип инструментов:" << endl << 
				"|1| <-> Духовые инструменты" << endl << 
				"|2| <-> Струнные инструменты" << endl <<
				"|3| <-> Ударные инструменты" << endl;
			cin >> swtch1;
			switch (swtch1)
			{
			case 1: /*Духовые*/

				break;
			case 2: /*Струнные*/

				break;
			case 3: /*Ударные*/
				file = "percussion.dat";
				cout << "Выберите действие:" << endl <<
					"|1| <-> Вывод на экран" << endl <<
					"|2| <-> Добавление нового инструмента в базу" << endl <<
					"|3| <-> Удаление инструмента из базы" << endl <<
					"|4| <-> Редактирование базы" << endl;
				cin >> swtch1;
				switch (swtch1)
				{
				case 1: /*Вывод на экран*/
					in.open(file, ios::binary | ios::in);
					if (!in.is_open())
					{
						cout << "Ошибка открытия файла!" << endl;
					}
					else
					{
						cout << "Файл открыт!" << endl;
						while (in.read(reinterpret_cast<char*>(&per_buf), sizeof(percussion)))
							per_buf.put_per();
						cout << endl;
					}
					in.close();
					break;
				case 2: /*Добавление в базу*/
					f.open(file, ios::binary | ios::app);
					if (!f.is_open())
					{
						cout << "Ошибка открытия файла!" << endl;
					}
					else
					{
						cout << "Файл открыт!" << endl;
						per = new percussion[1]; //выделение дин пам под один объект класса
						while (true)
						{
							per[0].set_per();
							f.write(reinterpret_cast<char*>(&per[0]), sizeof(per[0]));
							cout << "Ввести ещё один инструмент? \n1 -> ДА\n2 -> НЕТ " << endl;
							cin >> swtch1;
							if (swtch1 != 1)
								break;
						}
						delete[] per;
					}
					f.close();

					/////////////////////////////////////Вывод на экран////////////////////////////

					in.open(file, ios::binary | ios::in);
					if (!in.is_open())
					{
						cout << "Ошибка открытия файла!" << endl;
					}
					else
					{
						cout << "Файл открыт!" << endl;
						per = new percussion[1];
						while (in.read(reinterpret_cast<char*>(&per[0]), sizeof(percussion)))
							per[0].put_per();
						per[0] = percussion();
						delete[] per;
					}
					in.close();

					system("percussion.dat");


					break;
				case 3: /*Удаление из базы по названию инстр и ФИО владельца*/	
					in.open(file, ios::binary | ios::in);
					if (!in.is_open())
					{
						cout << "Ошибка открытия файла!" << endl;
					}
					else
					{
						cout << "Файл открыт!" << endl;
						swtch1 = 0;
						while (in.read(reinterpret_cast<char*>(&per_buf), sizeof(percussion)))
							swtch1++;

						in.clear();
						in.seekg(0);

						per = new percussion[swtch1];
						swtch1 = 0;
						while (in.read(reinterpret_cast<char*>(&per_buf), sizeof(percussion))) {
							per[swtch1] = per_buf;
							per[swtch1].put_per();
							swtch1++;
						}
					}
					in.close();

					cout << "Введите название инструмента -> ";
					cin >> name;
					cout << "Введите имя владельца -> ";
					cin >> FIO;

					f.open(file, ios::binary | ios::out);
					if (!f.is_open())
					{
						cout << "Ошибка открытия файла!" << endl;
					}
					else
					{
						cout << "Файл открыт!" << endl;
						for (int i = 0; i < swtch1; i++)
						{
							if (strcmp(per[i].ret_name(), name)==0 && strcmp(per[i].ret_owner(), FIO) == 0)
							{
								cout << "Данные об инструменте удалены! =D" << endl;
							}
							else
							{
								f.write(reinterpret_cast<char*>(&per[i]), sizeof(per[i]));
								per[i].put_per();
							}
						}
						delete[] per;
					}
					f.close();
					break;
				case 4: /*Редактирование базы*/
					in.open(file, ios::binary | ios::in);
					if (!in.is_open())
					{
						cout << "Ошибка открытия файла!" << endl;
					}
					else
					{
						cout << "Файл открыт!" << endl;
						swtch1 = 0;
						while (in.read(reinterpret_cast<char*>(&per_buf), sizeof(percussion)))
							swtch1++;

						in.clear();
						in.seekg(0);

						per = new percussion[swtch1];
						swtch1 = 0;
						while (in.read(reinterpret_cast<char*>(&per_buf), sizeof(percussion))) {
							per[swtch1] = per_buf;
							per[swtch1].put_per();
							swtch1++;
						}
					}
					in.close();
					cout << "Данные о каком инструменте вы хотели бы изменить?" << endl;
					cout << "Введите название инструмента -> ";
					cin >> name;
					cout << "Введите имя владельца -> ";
					cin >> FIO;

					f.open(file, ios::binary | ios::out);
					if (!f.is_open())
					{
						cout << "Ошибка открытия файла!" << endl;
					}
					else
					{
						cout << "Файл открыт!" << endl;
						for (int i = 0; i < swtch1; i++)
						{
							if (strcmp(per[i].ret_name(), name) == 0 && strcmp(per[i].ret_owner(), FIO) == 0)
							{
								cout << "Введите новые данные об инстрменте: " << endl;
								per[i].set_per();
								f.write(reinterpret_cast<char*>(&per[i]), sizeof(per[i]));
								cout << "Редактирование прошло успешно! " << endl;
								per[i].put_per();
							}
							else
							{
								f.write(reinterpret_cast<char*>(&per[i]), sizeof(per[i]));
								per[i].put_per();
							}
						}
						delete[] per;
					}
					f.close();
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
			break;
		case 0:
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
