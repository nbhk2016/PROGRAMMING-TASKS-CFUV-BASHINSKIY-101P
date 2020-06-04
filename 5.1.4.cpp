/*
1.Условие задачи:
	Имеется текстовый файл. Удалить из него третью строку. Результат записать в другой файл.
2.Словесное описание алгоритма:
	1)Объявляется функция для чтения файла
		1.1)Объявляются переменные
			line - для хранения конкретной строки
			str - всей строки
			subst - разделитель
		1.2)Чтение файла с помощью цикла, который проверяет равен ли номер строки 2
		1.3)Возврат значения строки
	2)Объявляются функция записи файла
	3)Объявляется переменная для хранения адреса
	4)Вызов функции чтения и записи файла 
3.Код задачи */

#include <iostream>
#include <fstream>

using namespace std;

string read_file(string address){
    string line;
    string str;

    int i = 0;
 
    ifstream in(address);
    if (in.is_open())
        while (getline(in, line)){
        	if (i != 2){
	            str += line + "\n";
        	}
        	i++;
        }
        
    in.close();
    return str;
}

void write_file(string address, string content){
    ofstream out;
    out.open(address);
    if (out.is_open())
        out << content << endl;
    
}

int main (){
	cout << "enter an address to read" << endl;
	//Объявляется переменная для хранения строки адреса чтения
	string addr_read;
	//Ввод строки с клавиатуры
	cin >> addr_read;

	cout << "enter an address to write" << endl;
	//Объявляется переменная для хранения строки адреса чтения
	string addr_write;
	//Ввод строки с клавиатуры
	cin >> addr_write;
	//Вызов функции чтения и записи
	write_file(addr_write, read_file(addr_read));

	cout << "ok" << endl;
	return 0;

}

/*Результат выполнения:
	enter an address to read
	c://new.txt
	enter an address to write
	c://users/nazar/desktop/new.txt
	ok
	
	содержимое c://new.txt
		1ddfsdfsdf
		2fsdf
		3sdfsd
		4fsdf
		5sd
		6fs
		7df
		8sd
		9fs
	содержимое c://users/nazar/desktop/new.txt
		1ddfsdfsdf
		2fsdf
		4fsdf
		5sd
		6fs
		7df
		8sd
		9fs
*/
