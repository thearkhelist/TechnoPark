#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

int main(void)
{
	int n = 0;                                     // счетчик введенных чисел
	int* n_array = new int[1000*1000];		//Создание массива
	while(1) {
		if ((scanf("%d", &n_array[n])!=1 ) || (std::cin.eof())) break;  //Ввод значений 
		++n;
	}

	int min_index;
	for (int i = 0; i < n-1; i++) { //Сортировка выбором
		min_index = i;
		for (int k = i+1; k<n; k++) {
			if (n_array[k] < n_array[min_index]) min_index = k; 
		}
		if (min_index != i) { 
			int temp = n_array[min_index];
			n_array[min_index] = n_array[i];
			n_array[i] = temp;
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", n_array[i]);
	//scanf("%d\n");
	return EXIT_SUCCESS;
}
