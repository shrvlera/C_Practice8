#include <stdio.h>
#include "myarrfunc.h"
// очистка буфера
void flush_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void show_menu() {
    printf("a Задать размер массива\n");
    printf("b Заполнить массив\n");
    printf("c Представление массива (значения, адреса)\n");
    printf("d Минимальное значение в диапазоне индексов k-m\n");
    printf("e Разница между макс. и мин. значением в диапазоне k-m\n");
    printf("f Индексы элементов со значением ниже заданного k\n");
    printf("g Выход\n");
    printf("Выберите пункт: ");
}

int main() {
    int arr[SIZE] = {0};
    int indices[SIZE] = {0};
    int n = 0;
    int is_filled = 0;
    int k, m, ans, count, res;
    int *p, *end;
    char choice;

    while (1) {
        show_menu();

        res = scanf(" %c" ,  &choice);
        if (res == EOF) {
            printf("\nEOF - выход\n");
            break;
        }
        flush_input();

        switch (choice) {
            case 'a' : {
                printf("введите размер массива (от 1 до %d):" , SIZE);
                res = scanf("%d", &n);
                if (res == EOF) {
                    printf("\nEOF - выход\n");
                    return 0;
                }
                flush_input();

                is_filled = 0;
                if (res != 1 || n <= 0 || n > SIZE) {
                    n = 0;
                    printf("размер должен быть от 1 до %d.\n\n", SIZE);
                } else {
                    printf("размер массива установлен: %d\n\n", n);
                }
                break;

            }

            case 'b' : 
                if (n == 0) {
                   printf("Сначала задайте размер массива (пункт a).\n\n");
                   break;
                }
                fill_array(arr, n);
                is_filled = 1;
                printf("Массив заполнен.\n\n");
                break;
                
            case 'c' :
                if (n == 0 || is_filled == 0) {
                    printf("Массив не задан или не заполнен (пункты a и b).\n\n");
                    break;
                }
                print_array(arr, n);
                break;

            case 'd' :
                if (n == 0 || is_filled == 0) {
                    printf("Массив не задан или не заполнен (пункты a и b).\n\n");
                    break;
                }
                printf("Введите индексы k и m (от 0 до %d): ", n - 1);
                res = scanf("%d %d", &k, &m);
                if (res == EOF) {
                     return 0;
                }
                flush_input();
                if (res != 2) {
                    printf("Ошибка ввода индексов.\n\n");
                    break;
                }

                if (find_min_range(arr, n, k, m, &ans) == OK) {
                    printf("Минимальный элемент: %d\n\n", ans);
                } else {
                    printf("ошибка - неверные границы диапазона\n\n");
                }
                break;
                
            case 'e':
                if (n == 0 || is_filled == 0) {
                    printf("Массив не задан или не заполнен (пункты a и b).\n\n");
                    break;
                }
                printf("Введите индексы k и m (от 0 до %d): ", n - 1);
                res = scanf("%d %d", &k, &m);
                if (res == EOF) {
                    return 0;
                }
                flush_input();

                if (res != 2) {
                    printf("Ошибка ввода индексов.\n\n");
                    break;
                }

                if (find_diff_range(arr, n, k, m, &ans) == OK) {
                    printf("Разница между макс. и мин.: %d\n\n", ans);
                } else {
                    printf("ошибка -  неверные границы диапазона.\n\n");
                }
                break;

            case 'f':
                if (n == 0 || is_filled == 0) {
                    printf("Массив не задан или не заполнен (пункты a и b).\n\n");
                    break;
                }
                printf("введите число k: ");
                res = scanf("%d" , &k);
                if (res == EOF) {
                    return 0;
                }
                flush_input();
                   
                if (res != 1) {
                    printf("ошибка ввода числа\n\n");
                    break;
                }

                if (find_below_k(arr, n, k, indices, &count) == OK) {
                    printf("Индексы элементов меньше %d: ", k);
                    p = indices;
                    end = indices + count;
                    while (p < end) {
                        printf("%d ", *p);
                        p++;
                    }
                    printf("\n\n");
                } else {
                    printf("Элементы меньше %d не найдены.\n\n", k);
                }
                break;
                
            case 'g':
                printf("Выход\n");
                return 0;
            
            default:
                printf("Неизвестный пункт меню.\n\n");
                break;

        }

    }
    return 0;
}