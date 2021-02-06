//
// Created by Roson on 2021/1/26.
//
#include "MyMinHeap.h"
#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int buffer[10] = {9,8,7,6,5,4,3,2,1,0};
    MyMinHeap<int>heap(buffer, 11);
    heap.printfAll();
    heap.pop(1);
    heap.printfAll();
    heap.push(1);
    heap.printfAll();
    system("pause");
    return 0;
}

