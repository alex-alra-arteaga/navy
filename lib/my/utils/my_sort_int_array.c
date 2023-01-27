/*
** EPITECH PROJECT, 2022
** my_sort_int_array
** File description:
** library
*/

void my_swap(int *a, int *b);

int compare_and_swap(int *array, int temp)
{
    if (array[temp] > array[temp + 1]) {
        my_swap(&array[temp], &array[temp + 1]);
    }
    temp++;
    return (temp);
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int temp = 0;
    int right_len = size -1;

    while (i < size) {
        temp = 0;
        while (temp < right_len) {
            temp = compare_and_swap(array, temp);
        }
        i++;
    }
}
