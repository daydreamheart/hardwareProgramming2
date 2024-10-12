/*
Írj egy C programot, amely folyamatosan és ciklikusan 1-100-ig számol
(1, 2, 3, ... , 99, 100, 1, 2, ... , 99, 100, 1, 2, ... ) a lehető leggyorsabban.
A program másodpercenként írja ki melyik számnál tart éppen!
Interrupt szignal (Ctrl + C) érkezése esetén írja ki az aktuális értéket és álljon meg!
*/

// Magyar Melinda Barbara

#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

volatile sig_atomic_t print = false;
volatile int value = 0;

void signalHandler(int signal)
{
    printf("Aktuális érték: %d\n", value);
    exit(signal);
}

void alarmHandler(int signal)
{
    print = true;
}

int main()
{
    signal(SIGALRM, alarmHandler);
    alarm(1);

    while (1)
    {
        for (int i = 0; i < 100; i++)
        {
            if (print)
            {
                printf("%d\n", i + 1);
                print = false;
                alarm(1);
                value = i + 1;
            }

            signal(SIGINT, signalHandler);
        }
    }

    return 0;
}
