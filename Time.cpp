/*#include <stdio.h>
#include <time.h>


int main()
{
    time_t timer;
    char buffer[26];
    struct tm* tm_info;
    int morning_date;
    int evening_date;

    time(&timer);
    tm_info = localtime(&timer);

    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    puts(buffer);

    morning_date = new DateTime(2017, 2, 20, 11, 59, 59, 059);
    evening_date = new DateTime(2017, 2, 20, 17, 59, 59, 059);
    if (int buffer <= morning_date)
        printf("Morning");
    if (((int buffer) > morning_date)&&((int buffer) <= evening_date))
        printf("Evening");
    if (int buffer > evening_date)
        printf("Afternoon");

    getchar();
    while(true){}
    return 0;
}
         */

/*
#include <stdio.h>  // Для printf
#include <time.h> // Для time, localtime, strftime

int main (void)
{    
    //Переменная для системного времени
    long int s_time;
    //Указатель на структуру с локальным временем
    struct tm *m_time;
    //Строка для сохранения преобразованного времени
    char str_t[128]="";

    //Считываем системное время
    s_time=time(NULL);
        time(&timer);
    //Преобразуем системное время в локальное
    m_time = localtime (&s_time);

   //Преобразуем локальное время в текстовую строку
   strftime (str_t, 128, "Дата:  %x %A %X %Z", m_time);

    //Выводим строку в консоль
    printf ("%s\n",str_t);
    getchar();
    while(true){}
    return 0;
} */