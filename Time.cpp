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
#include <stdio.h>  // ��� printf
#include <time.h> // ��� time, localtime, strftime

int main (void)
{    
    //���������� ��� ���������� �������
    long int s_time;
    //��������� �� ��������� � ��������� ��������
    struct tm *m_time;
    //������ ��� ���������� ���������������� �������
    char str_t[128]="";

    //��������� ��������� �����
    s_time=time(NULL);
        time(&timer);
    //����������� ��������� ����� � ���������
    m_time = localtime (&s_time);

   //����������� ��������� ����� � ��������� ������
   strftime (str_t, 128, "����:  %x %A %X %Z", m_time);

    //������� ������ � �������
    printf ("%s\n",str_t);
    getchar();
    while(true){}
    return 0;
} */