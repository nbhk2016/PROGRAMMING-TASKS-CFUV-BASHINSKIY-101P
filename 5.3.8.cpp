/*
1.Условие задачи:
	Имеются два текстовых файла с одинаковым числом строк. Выяснить, совпадают ли их строки. 
	Если нет, то получить номер первой строки, в которой эти файлы отличаются друг от друга.
2.Словесное описание алгоритма:
	1)Объявляется функция для чтения файла
		1.1)Объявляются переменные
			line - для хранения конкретной строки
			str - всей строки
		1.2)Чтение файла с помощью цикла, запись значения линии в массив
	2)Объявляется функция для получения количества линий
		чтения файла с помощью цикла, возврат счетчика
	2)Объявляется переменные
		addr1, addr2 -адреса файлов
		file1_arr, file2_arr - массивы линий файла
		is_equals - флаг для хранения совпадают файлы или нет
	3)Считывание с клавивиатуры адресов
	4)вызов функции подсчета и запись в переменные
	5)вызов функции записи в массив
	6)цикл перебора массивов до первого расхождения
		если есть расхождение вывод счетчика и присвоение флагу 0
	7)проверка флага
		если 1 вывод о том что содержимое файлов совпадает


3.Код задачи */



#include <iostream>
#include <fstream>

using namespace std;

//функция записи в массив

void read_file_to_arr(string address, string *arr){
    string line;
    string str;

    int i = 0;
 
    ifstream in(address);
    if (in.is_open())
        while (getline(in, line)){
	        arr[i] = line;
	        i ++;
        }
        
    in.close();
}

//функция подсчета количества линий
int get_amount_of_lines(string address){
	string line;
    string str;

    int i = 0;
 
    ifstream in(address);
    if (in.is_open())
        while (getline(in, line))
        	i++;

    in.close();

    return i;
}

int main(){
	bool is_equals = 1;
	cout << "Enter first file address" << endl;
	string addr1;
	cin >> addr1;
	int lines_amount = get_amount_of_lines(addr1);
	string *file1_arr = new string[lines_amount];
	read_file_to_arr(addr1, file1_arr);

	cout << "Enter second file address" << endl;
	string addr2;
	cin >> addr2;
	string *file2_arr = new string[lines_amount];
	read_file_to_arr(addr2, file2_arr);

	for (int i = 0; i < lines_amount; i ++)
		if (file1_arr[i] != file2_arr[i]){
				cout << i << endl;
				is_equals = 0;
				break;
			}

	if (is_equals)
		cout << "Text in files is equal" << endl;

	return 0;
}

/*текстовый вывод
Enter first file address
c://users/nazar/desktop/1.txt
Enter second file address
c://users/nazar/desktop/2.txt
8

содержимое 1.txt
	gfdfgdfsgfdsgfd
	ddfsgdfsgfdsgdfs
	dfsgdfsgdsg
	hhjkutrthgeawgrh
	r
	ghrtjykilttyrtht
	yjurkruyytey
	treyyyjjmdff
	sdfgfdg
	fdgdhkli9;
содержимое 2.txt
	gfdfgdfsgfdsgfd
	ddfsgdfsgfdsgdfs
	dfsgdfsgdsg
	hhjkutrthgeawgrh
	r
	ghrtjykilttyrtht
	yjurkruyytey
	treyyyjjmdff
	sdfddgfdg
	fdgdhkli9;
	
*/
