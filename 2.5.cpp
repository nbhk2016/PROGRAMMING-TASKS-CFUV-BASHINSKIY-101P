/*
1.Условие задачи:
	В каждом из двух классов учатся по 18 человек. Известны средние оценки каждого ученика каждого класса,
	подсчитанные по ряду предметов (все значения для каждого класса разные). 
	Определить, в каком классе у "третьего из самых успевающих учеников" средняя оценка больше.
2.Словесное описание алгоритма:
	1)Объявляется функция для сортировки пузырьком
	2)Объявляются переменые 
		arr_1 - вектор для хранения оценок 1 класса
		arr_2 - вектор для хранения оценок 2 класса
	2)Заполняется массивы с клавиатуры
	3)Объявляются переменные, которым присваиваются значения, полученные  в результате выполенения
	функции сортировки, выделение третьего элемента каждого массива
	4)Если средний балл в 1 классе больше выводится на экран, что в 1,
		если 2 - то, что 2,
		если одинаковое - то, что средние баллы одинаковые
3.Код задачи */

#include <iostream>
#include <vector>
#define N 18

using namespace std;

vector<float> sort(vector<float> arr){
	float temp; // временная переменная для обмена элементов местами
	int size = arr.size();
    // Сортировка массива пузырьком
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // меняем элементы местами
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return arr;

}

int main(){
	//объявить переменные
	vector<float> arr_1(N);
	vector<float> arr_2(N);

	cout << "please, enter the pupils' marks in 1 class" << endl;

	//заполнить массив 1 с клавиатуры
	for (int i = 0; i < N; i ++)
		cin >> arr_1[i];

	cout << "please, enter the pupils' in 2 class" << endl;

	//заполнить массив 2 с клавиатуры
	for (int i = 0; i < N; i ++)
		cin >> arr_2[i];
	//Объявляются переменные, которым присваиваются значения, полученные  в результате выполенения
	float mark_1 = sort(arr_1)[3];
	float mark_2 = sort(arr_2)[3];

	/*Если средний балл в 1 классе больше выводится на экран, что в 1,
		если 2 - то, что 2,
		если одинаковое - то, что средние баллы одинаковые*/
	if (mark_1 > mark_2)
		cout << "in first class mark of the 3rd people is more" << endl;

	else if (mark_1 < mark_2)
		cout << "in second class mark of the 3rd people is more" << endl;

	else if (mark_1 == mark_2)
		cout << "marks of 3rds peoples in both classes are equal" << endl;
	

	return 0;
}

/*
4.Результат работы на текстовых данных
	1.please, enter the pupils' marks in 1 class
	2.4.9 2.5 3.1 4.5 1.6 2.3 3.5 4.1 2.5 1.3 5.0 3.7 5.0 4.0 1.5 4.4 3.4 4.2
	3.please, enter the pupils' marks in 1 class
	4.4.9 2.5 3.1 4.5 1.4 2.3 3.5 3.1 2.5 1.2 5.0 3.6 5.0 4.0 1.6 4.4 3.5 4.2
	5.marks of 3rds peoples in both classes are equal
*/