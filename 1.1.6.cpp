/*+
1.Условие задачи:
	Ввести массив, состоящий из 20 элементов целого типа.
	Определить каких элементов больше четных или нечетных по значению.
2.Словесное описание алгоритма:
	1)Объявляются переменые 
		mass - массив для хранения данных
		even - счетчик четных
		odd - нечетных
	2)Заполняется массив с клавиатуры
	3)Проверяется четность каждого элемента перебором в цикле
		если осток от деления числа на 2 равен 0 тогда увеличивается счетчик even
		в противном случае odd
	4)Если even > odd выводится, что четных больше, если even < odd, то нечетных, если одинаковое количество,
	то выводится, что одинаковое
3.Код задачи */

#include <iostream>
#include <vector>
#define N 20

using namespace std;

int main(){
	//объявить переменные
	int *mass = new int[N];
	int even, odd;

	cout << "please, enter the array" << endl;

	//заполнить массив с клавиатуры
	for (int i = 0; i < N; i ++)
		cin >> mass[i];

	//проверить четность каждого элемента
	for (int i = 0; i < N; i ++){
		if (i % 2 == 0)
			even ++;
		else
			odd ++;
	}

	//Если even > odd выводится, что четных больше, если even < odd, то нечетных, если одинаковое количество,
	//то выводится, что одинаковое

	if (even > odd)
		cout << "even" << endl;

	else if (even < odd)
		cout << "odd" << endl;

	else if (even == odd)
		cout << "equals" << endl;

	delete mass;
	return 0;
}

/*
4.Результат работы на текстовых данных
	1.please enter the array
	2.5 7 8 9 10 11 12 54 3 4 12 11 10 14 15 16 10 3 77 20
	3.odd
*/
