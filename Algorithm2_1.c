#include <stdio.h>
#include <stdlib.h>
void selection_sort_x(int *a, int n);
void selection_sort_y(int *a, int first, int last);
int main(void) {
        int n;
        //int result;
        scanf("%d", &n);
        int* coordinate_arr=(int*)malloc(2*n*sizeof(int)); //Создание одномерного массива, в котором i = x, i+1 = y (значения координат идут подряд)
        int* count_of_x_coord = (int*)malloc(n*sizeof(int));//Создание массива для определения количества точек с одинаковой x-координатой (используется при сортировке по y-координате)
        for(int i = 0; i < 2*n; i+=2)
        {
                scanf("%d%d", &coordinate_arr[i], &coordinate_arr[i+1]);
                count_of_x_coord[coordinate_arr[i]]++;
        }
        selection_sort_x(coordinate_arr, n); //Сотрировка по х
        for (int i = 0; i < 2*n; i+=2*count_of_x_coord[coordinate_arr[i]]){
                selection_sort_y(coordinate_arr, i, i+2*count_of_x_coord[coordinate_arr[i]]-1); //Сортировка по y(в функцию передаются индексы первой и последней одинаковой координаты х)
        }
        for(int i = 0; i < 2*n; i+=2)
        {
                printf("%d ", coordinate_arr[i]);
                printf("%d\n", coordinate_arr[i+1]);
        }
        return EXIT_SUCCESS;
}


void selection_sort_x(int *a, int n) { //Сортировка данных точек по х-координате 
        for (int i = 0; i < 2*(n - 1); i+=2) {
                int min_index = i;
                for (int j = i + 2; j < 2*n; j+=2) {
                        if (a[j] < a[min_index]) min_index = j;
                }
                if (min_index != i) {
                        int temp = a[i];
                        a[i] = a[min_index];
                        a[min_index] = temp;
                        int tempx= a[i+1];
                        a[i+1] = a[min_index+1];
                        a[min_index+1] = tempx;
                }
        }
}

void selection_sort_y(int *a, int first, int last) { //Сортировка точек по y-координате(в пределах одного значения х)
        for (int i = first+1; i < last - 1; i+=2) {
                int min_index = i;
                for (int j = i + 2; j < last+1; j+=2) {
                        if (a[j] < a[min_index]) min_index = j;
                }
                if (min_index != i) {
                        int temp = a[i];
                        a[i] = a[min_index];
                        a[min_index] = temp;
                }
        }
}
