//
// Created by Roson on 2021/1/26.
//

#ifndef MYMINHEAP_H
#define MYMINHEAP_H
#include<vector>
#include<iostream>

using namespace std;
template <typename T>
class MyMinHeap 
{
public:
    MyMinHeap(T buff[],int length);
    MyMinHeap(int capacity);
    virtual ~MyMinHeap();
    int getSize();
    bool isFull();
    bool isEmpty();
    void swap(vector<T> &vec,int i,int j);
    void floating(int index);
    void sink(int index);
    bool push(T data);
    bool pop(int index);
    void printfAll();
private:
    int m_iHeapCapacity;
    int m_iHeapSize;
    vector<T> m_vecData;
};

template <typename T>
MyMinHeap<T>::MyMinHeap(T buff[],int length)
{
    m_iHeapCapacity=length;
    m_iHeapSize=1;
    m_vecData.resize(length);
    m_vecData[0] = 0;
    for(int i=0;i<length-1; i++)
    {
        push(buff[i]);
    }
}

template <typename T>
MyMinHeap<T>::    MyMinHeap(int capacity)
{
    m_iHeapCapacity=capacity;
    m_iHeapSize=0;
    m_vecData.resize(capacity);
}

template <typename T>
MyMinHeap<T>::~MyMinHeap() {}

template <typename T>
int MyMinHeap<T>::getSize()
{
    return m_iHeapSize;
}

template <typename T>
bool MyMinHeap<T>::isFull()
{
    if(m_iHeapSize >= m_iHeapCapacity)
        return true;
    return false;
}

template <typename T>
bool MyMinHeap<T>::isEmpty()
{
    return m_iHeapSize == 0;
}

template <typename T>
void MyMinHeap<T>::swap(vector<T> &vec, int i, int j)
{
    T temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

template <typename T>
void MyMinHeap<T>::floating(int index)
{
    T temp;
    for(int i = index-1; i > 1; i*=0.5)
    {
        if(m_vecData[i] < m_vecData[i/2])
            swap(m_vecData, i, i/2);
        else
            break;
    }
}

template <typename T>
void MyMinHeap<T>::sink(int index)
{
    int i = index-1;
    while(i*2 < m_iHeapSize)
    {
        if(m_vecData[i] > m_vecData[i*2])
        {
            swap(m_vecData, i, i*2);
            if(i*2+1 <= m_iHeapSize and m_vecData[i] > m_vecData[i*2+1])
                swap(m_vecData, i, i*2);
            i = 2*i +1;
        }
        else if(i*2 + 2 <= m_iHeapSize and m_vecData[i] > m_vecData[2*i+1])
        {
            swap(m_vecData, i, i*2+1);
            i = 2*(i+1);
        }
        else
            break;
    }
}

template <typename T>
bool MyMinHeap<T>::push(T data)
{
    if(isFull())
        return false;
    m_vecData[m_iHeapSize] = data;
    m_iHeapSize++;
    floating(m_iHeapSize);
    return true;
}

template <typename T>
bool MyMinHeap<T>::pop(int index)
{
    if(isEmpty())
        return false;
    m_vecData[index] = m_vecData[m_iHeapSize-1];
    m_iHeapSize--;
    sink(index+1);
    return true;
}

template <typename T>
void MyMinHeap<T>::printfAll()
{
    cout << "Heap : ";
    for(int i = 0; i < m_iHeapSize; i++)
    {
        cout << m_vecData[i] << " ";
    }
    cout << endl << endl;
}

#endif //DATASTRUCTURE_MYMINHEAP_H
