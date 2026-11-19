#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL, "RUS");

    char fill;
    char contr;
    int a;
    int go;

    do {
        printf("Введите символ для контура фигуры: ");
        scanf(" %c", &contr);

        printf("Введите символ для внутренней закраски: ");
        scanf(" %c", &fill);

        printf("Введите размер фигуры (радиус): ");
        scanf("%d", &a);

        if (a < 2)
        {
            printf("Ошибка: размер должен быть не меньше 2.\n");
        }
        else
        {
            printf("\n");
            for (int y = a; y >= -1; y--)
            {
                for (int x = -1; x <= a; x++)
                {
                    if (x == 0 && y >= 0 && y < a)
                    {
                        printf("| ");
                    }
                    else if (x == 0 && y == a)
                    {
                        printf("^ ");
                    }
                    else if (y == 0 && x > 0 && x < a)
                    {
                        printf("--");
                    }
                    else if (y == 0 && x == a)
                    {
                        printf("> ");
                    }
                    else if (x == 0 && y == 0)
                    {
                        printf("+ ");
                    }
                    else
                    {
                        if (x >= 0 && y >= 0)
                        {
                            int r2 = x * x + y * y;
                            int a2 = a * a;

                            int acr = (abs(r2 - a2) <= a);
                            int diagonal = (x == y);
                            int bound = (x == 0 && y <= a);

                            if ((acr || diagonal || bound) && y >= x)
                            {
                                printf("%c ", contr);
                                continue;
                            }

                            if (r2 < a2 && y > x)
                            {
                                printf("%c ", fill);
                                continue;
                            }
                        }

                        printf("  ");
                    }
                }
                printf("\n");
            }
        }

        printf("Запустить программу заново? (любая цифра - да; 0 - нет): ");
        scanf("%d", &go);

    } while (go != 0);
}