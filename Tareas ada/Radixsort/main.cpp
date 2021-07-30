#include<iostream>
using namespace std;
#include <math.h>
#define NUMELTS 20

void radixsort(int x[], int n)
{
    int front[10], rear[10];

    struct {
        int info;
        int next;
    } node[NUMELTS];

    int exp, first, i, j, k, p, q, y;

    for (i = 0; i < n-1; i++)
    {
        node[i].info = x[i];
        node[i].next = i+1;
    }

    node[n-1].info = x[n-1];
    node[n-1].next = -1;
    first = 0;

    for (k = 1; k < 5; k++)
    {

        for (i = 0; i < 10; i++)
        {

            rear[i] = -1;
            front[i] = -1;
        }


        while (first != -1)
        {
            p = first;
            first = node[first].next;
            y = node[p].info;
            exp = pow(10, k-1);
            j = (y/exp) % 10;
            q = rear[j];
            if (q == -1)
                front[j] = p;
            else
                node[q].next = p;
            rear[j] = p;
        }
        for (j = 0; j < 10 && front[j] == -1; j++);
            ;
        first = front[j];

        while (j <= 9)
        {
            for (i = j+1; i < 10 && front[i] == -1; i++);
                ;
            if (i <= 9)
            {
                p = i;
                node[rear[j]].next = front[i];
            }
            j = i;
        }
        node[rear[p]].next = -1;
    }

    for (i = 0; i < n; i++)
    {
            x[i] = node[first].info;
            first = node[first].next;
    }
}


int main(void)
{
    int x[50] = {NULL}, i;
    static int n;

    cout<<"Cadena de números enteros:\n";
    for (n = 0;; n++)
    {
        cin>>x[n];
        if(x[n]==-1)
            break;
    }

    if (n)
        radixsort (x, n);
    for (i = 0; i < n; i++)
        cout<<x[i]<<endl;;

    return 0;
}
