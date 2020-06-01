/*
1.Условие задачи:
	Известно число жителей, проживающих в каждом доме улицы. Нумерация домов проведена подряд.
	Дома с нечетными номерами расположены на одной стороне улицы,
	с четными — на другой. На какой стороне улицы проживает больше жителей?
2.Словесное описание алгоритма:
	1)Объявляются переменые 
		arr_people - вектор для хранения количества жителей в каждом доме
		even - количество в четных домах
		odd - в нечетных
	2)Заполняется массивы с клавиатуры
	3)С помощью цикла перебирается каждый элемент массива
		3.1)если индекс четный, то значение количества людей прибавляется к переменной even
			в противном случае - в odd
	4)Если количество в четных домах больше выводится на экран, что в четных больше,
		если нечетных - то, что нечетных больше
		если одинаковое - то, что количество одинаковое
3.Код задачи */

#include <iostream>
#include <vector>
#define N 20

using namespace std;

int main(){
	//объявить переменные
	vector<int> arr_people(N);
	int even = 0;
	int odd = 0;

	cout << "please, enter the people amount in which house" << endl;

	//заполнить массив с клавиатуры
	for (int i = 0; i < N; i ++)
		cin >> arr_people[i];

	/*3)С помощью цикла перебирается каждый элемент массива
		3.1)если индекс четный, то значение количества людей прибавляется к переменной even
			в противном случае - в odd*/

	for (int i = 0; i < N; i ++){
		if (i % 2 == 0)
			even += arr_people[i];

		else
			odd += arr_people[i];
	}

	if (even > odd)
		cout << "even" << endl;

	else if (even < odd)
		cout << "odd" << endl;

	else if (even == odd)
		cout << "equals" << endl;
	

	return 0;
}

/*
4.Результат работы на текстовых данных
1.please, enter the people amount in which house
2.5 7 8 9 10 11 12 54 3 4 12 11 10 14 15 16 10 3 77 20
3.even
*/