#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <malloc.h>
#include "Autoschool.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //пример работы со статической переменной
    Lesson staticExample = *InputLesson();
    PrintLesson(staticExample);
    PrintInstructor(staticExample.intstructor);
    PrintClient(staticExample.client);
    ChangeStatus(&staticExample, 2);
    PrintLesson(staticExample);

    //пример работы с динамической
    Lesson* dynamicExample = (Lesson*)calloc(1, sizeof(Lesson));
    char data[] = "22.12.2023";
    char time[] = "11.50";
    dynamicExample = CreateLesson(*InputClient(), *InputInstructor(), data, time, 2);
    PrintLesson(*dynamicExample);
    PrintInstructor(dynamicExample->intstructor);
    PrintClient(dynamicExample->client);
    ChangeStatus(dynamicExample, 2);
    PrintLesson(*dynamicExample);
    FreeLessonMemory(dynamicExample);
    free(dynamicExample);
}