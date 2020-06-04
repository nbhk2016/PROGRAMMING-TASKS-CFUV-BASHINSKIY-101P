/*
1.Условие задачи:
	Дан типизированный файл, элементами которого являются числа. Напечатать:
		а) первый элемент;
		б) третий элемент;
		в) n-й элемент;
		г) последний элемент.
2.Словесное описание алгоритма:
	1)объявляется функция записи:
		Объявляются переменные
		fout - моделирует выходной поток
		данные с клавиатуры помещаются в переменную data
		Связать переменную fout с файлом fileName (открыть файл)
		Если файл открыть не удалось - сообщить, завершить программу
		Вод данных с клавиатуры в файл fileName
		сбросить состояние потока
		отбросить остаток входной строки
	2)функция чтения
		Объявление переменной fin, моделирующей входной поток
		Связать переменную fin с файлом fileName (открыть файл)
		Если файл открыть не удалось - сообщить, завершить программу
		Вывод данных из файла на монитор
	
	3)Ввод имени файла с клавиатуры в переменную fileName
	4)Ввод int-данных с клавиатуры в файл fileName
	5)Вывод данных из файла на монитор
	6)Объявление переменной fin, моделирующей входной поток
	7)Связать переменную fin с файлом fileName (открыть файл)
	8)если не удалось открыть выводим ошибку
	9)перебор каждого числа
	10)если это первое, 3 или k вывод
	11)вывод последнего

3.Код задачи */


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void write_to_file(const string &fileName){
	// Объявляются переменные
	ofstream fout; // fout - моделирует выходной поток
	int data; // данные с клавиатуры помещаются в переменную data
	// Связать переменную fout с файлом fileName (открыть файл)
	fout.open(fileName.c_str(), ios::binary | ios::app);
	// Если файл открыть не удалось - сообщить, завершить программу
	if (!fout.is_open()){
		cout << "Cannot open file \"" << fileName << "\"." << endl;
		system("pause");
		exit(1);
	}

	// Вод данных с клавиатуры в файл fileName
	cout << endl << "Data from keyboard to file \"" << fileName << "\" (Q - quit)." << endl;

	while (cin >> data)
		fout.write((char*) &data, sizeof(int));

	fout.close();
	cin.clear(); // сбросить состояние потока
	while (cin.get() != '\n') // отбросить остаток входной строки
		continue;
}

void read_file(const string &fileName){

	// Вывод данных из файла на монитор
	// Объявление переменной fin, моделирующей входной поток
	ifstream fin; // fin - моделирует входной поток
	// Связать переменную fin с файлом fileName (открыть файл)
	fin.open(fileName.c_str(), ios::binary);
	// Если файл открыть не удалось

	if (!fin.is_open()){
		cout << "Cannot open file \"" << fileName << "\"." << endl;
		system("pause");
		exit(1);
	}

	// Вывод данных из файла на монитор

	int data;
	cout << endl << "Data of file \"" << fileName << "\"" << endl ;

	while (!fin.eof()){
		fin.read((char*) &data, sizeof(int));
		if (!fin.eof())
		cout << data << " ";
	}

	cout << endl;
	fin.close();
}

int main(){

	string fileName;
	// Ввод имени файла с клавиатуры в переменную fileName
	cout << "Enter filename: ";
	getline(cin, fileName);

	cout << "Enter k: ";
	int k;
	cin >> k;
	// Ввод int-данных с клавиатуры в файл fileName
	write_to_file(fileName);
	// Вывод данных из файла на монитор
	read_file(fileName);
	// Объявление переменной fin, моделирующей входной поток
	ifstream fin;
	// Связать переменную fin с файлом fileName (открыть файл)
	fin.open(fileName.c_str(), ios::binary);
	// Если файл открыть не удалось
	if (!fin.is_open()){
		cout << "Cannot open file \"" << fileName << "\"." << endl;
		system("pause");
		exit(1);
	}
	// перебор каждого числа
	int data;

	for (int i = 0; !fin.eof(); i ++){
		fin.read((char*) &data, sizeof(int));
		if (!fin.eof()){
			//вывод 1,3,k
			if (i == 0 || i == 2 || i == k - 1)
				cout << "i = " << i << " data = " << data << endl;
		}
	}

	//вывод последнего
	cout << "last " << data << endl;

	fin.close();

	return  0;
}
