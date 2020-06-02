/*
1.Условие задачи:
	В заданной строке поменять местами первое и последнее слово строки.
	Разделителями слов считаются пробелы.
2.Словесное описание алгоритма:
	1)Объявляется функция для замены первого и последнего слова местами
		1.1)Объявлеяется переменные
			len - длина строки
			first_gap_index - первый пробел
			last_gap_index - второй пробел
			gaps - счетчик пробелов
			first_word - первое слово
			last_word - второе слово
		1.2)цикл поиска первых и последних слов
			если счетчик пробелов = 1 тогда записывеи идекс в first_gap
			затем каждый последующий пробел в last_gap_index
		1.3)копирование в переменные первых и последних слов
		1.4)замена первых и последних слов функцией replace
	
	2)Объявляется переменная для хранения строки
	3)Ввод строки с клавиатуры
	4)Вывод результата работы функции замены
3.Код задачи */


#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

//Объявляются функция замены местами слов

string swap(string str){

	//Объявлеяется переменные
	int len = str.length();
	int first_gap_index = 0;
	int last_gap_index = 0;
	int gaps = 0;
	string first_word;
	string last_word;

	//цикл поиска первых и последних слов
	for (int i = 0; i < len; i ++)
		if (str[i] == ' '){
			gaps ++;

			if (gaps == 1)
				first_gap_index = i;

			last_gap_index = i + 1;
		}

	//копирование последнего и первого слова
	last_word = str.substr(last_gap_index);
	first_word = str.substr(0, first_gap_index);
	
	//замена местами
	str.replace(0, first_gap_index, last_word);
	str.replace(last_gap_index - 1, last_word.length(), first_word);

	return str;

}

int main (){
	cout << "enter a string" << endl;
	//Объявляется переменная для хранения строки
	string str;
	//Ввод строки с клавиатуры
	getline(cin, str);
	//Вывод результата работы функции замены
	cout << swap(str) << endl;

}

/*Результат текстового выполнения:
	1)enter a string
	2)каждый охотник желает знать
	3)знать охотник желает каждый
*/
