#ifndef DOUBLYLL_H
#define DOUBLYLL_H
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;


struct node
{
    int info;
    struct node *next;
    struct node *prev;
}*start;


class DoublyLL
{
    public:
        void create_list(int value);
        void count();

        DoublyLL()
        {
            start = NULL;
        }
};

#endif // DOUBLYLL_H
