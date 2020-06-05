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
	
	3)ввод с клавиатуры имен файлов, размеров массивов, самих файлов
	4)перебор циклом, запись в массив
	5)запись
	6)вывод

3.Код задачи */


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void write_file_from_arr(const string &fileName, int * arr){
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

	for (int i = 0; arr[i]; i ++)
		fout.write((char*) &arr[i], sizeof(int));

	fout.close();
	cin.clear(); // сбросить состояние потока
	while (cin.get() != '\n') // отбросить остаток входной строки
		continue;
}

vector<int> read_file_to_arr(const string &fileName){
	vector <int> arr;
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
	//cout << endl << "Data of file \"" << fileName << "\"" << endl ;
	while(!fin.eof()){
		fin.read((char*) &data, sizeof(int));
		if (!fin.eof())
			arr.push_back(data);
	}
	cout << endl;
	fin.close();
	return arr;

}


int main(){
	string file1_name;
	string file2_name;

	int len;

	cout << "Enter array length: ";
	cin >> len;

	int * file1_arr = new int[len];
	int * file2_arr = new int[len];

	cout << "Enter 1 file name: ";
	cin >> file1_name;

	cout << "Enter elements of 1 file: ";
	for (int i = 0; i < len; i ++)
		cin >> file1_arr[i];

	cout << "Enter 2 file name: ";
	cin >> file2_name;

	cout << "Enter elements of 2 file: ";
	for (int i = 0; i < len; i ++)
		cin >> file2_arr[i];

	write_file_from_arr(file1_name, file1_arr);
	write_file_from_arr(file2_name, file2_arr);

	string file31_name;
	string file32_name;

	cout << "Enter file name 3.1: ";
	cin >> file31_name;

	cout << "Enter file name 3.2: ";
	cin >> file32_name;

	int * file31_arr = new int[read_file_to_arr(file1_name).size()];
	int * file32_arr = new int[read_file_to_arr(file1_name).size()];

	for (int i = 0; i < read_file_to_arr(file1_name).size(); i ++){
		file31_arr[i] = read_file_to_arr(file1_name)[i] - read_file_to_arr(file2_name)[i];

		if (read_file_to_arr(file1_name)[i] > read_file_to_arr(file2_name)[i])
			file32_arr[i] = read_file_to_arr(file1_name)[i];
		else 
			file32_arr[i] = read_file_to_arr(file2_name)[i];
	}

	write_file_from_arr(file31_name, file31_arr);
	write_file_from_arr(file32_name, file32_arr);

	cout << "3.1 file: ";

	for (int i = 0; i < read_file_to_arr(file31_name).size(); i ++)
		cout << read_file_to_arr(file31_name)[i];
	cout << "3.2 file: ";

	for (int i = 0; i < read_file_to_arr(file32_name).size(); i ++)
		cout << read_file_to_arr(file32_name)[i];

	return  0;
}

/*результаты работы
Enter array length: 14
Enter 1 file name: hh
Enter elements of 1 file: 1 2 3 4 5 6 7 8 9 10 11 12 13 14
Enter 2 file name: jj
Enter elements of 2 file: 15 16 17 18 19 20 21 22 23 24 25 26 27 28
29
Enter file name 3.1: aaa
Enter file name 3.2: bbb
3.1 file: 16 18 20 22 23 25 27 29 31 34 36 38 40 42
3.2 file: 15 16 17 18 19 20 21 22 23 24 25 26 27 28
*/
