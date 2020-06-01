/*
1.Условие задачи:
	В заданной строке поменять местами первое и последнее слово строки.
	Разделителями слов считаются пробелы.
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
 
    ifstream in(address);
    if (in.is_open())
        while (getline(in, line)){
        	if (i != 2){
	            str += line + "\n";
	            i++;
        	}
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
	cout << "enter a addr" << endl;
	//Объявляется переменная для хранения строки
	string addr;
	//Ввод строки с клавиатуры
	cin >> addr;
	//Вывод результата работы функции замены
	write_file(addr, read_file(addr));

}

/*Результат выполнения:
	удалилась 3 строка файла
*/
