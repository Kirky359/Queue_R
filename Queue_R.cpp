#include <iostream>
#include <stdlib.h>
#include <windows.h>
#define N 5

using namespace std;

struct BankTransaction
{
    unsigned int cardSender;//відправник
    unsigned int cardResiver;//адресат
    double sum;//сума переказу
};
struct Queue
{
    BankTransaction array[N];
    int head = -1;
    int tail = -1;
    int quantity = 0;
    void push(BankTransaction transaction)
    {
        if (quantity == N)
        {
            cout << "Черга переповнена" << endl;
            return;
        }
        if (head == -1)
        {
            head = 0;
        }
        if (tail == N - 1)
        {
            tail = -1;
        }
        array[++tail] = transaction;
        quantity++;
    }
    BankTransaction pop()
    {
        if (!isEmpty())
        {
            BankTransaction tmp = array[head];
            if (head == N - 1)
            {
                head = -1;
            }
            head++;
            quantity--;
            return tmp;
        }
        else
        {
            cout << "Черга порожня" << endl;
        }
    }
    BankTransaction getFront()
    {
        if (isEmpty())
        {
            cout << "Черга порожня!" << endl;
        }
        else
        {
            return array[0];
        }
    }
    bool isEmpty()
    {
        return (quantity == 0);
    }
    void clear()
    {
        head = -1;
        tail = -1;
        quantity = 0;
    }
};

void print(Queue queue)
{
    while (queue.quantity != 0)
    {
        BankTransaction del = queue.pop();
        cout << del.cardSender << " " << del.cardResiver << " " << del.sum << endl;
    }

}
int main()
{
    SetConsoleOutputCP(1251);
    Queue queue;
    cout << "Додати в чергу 2 різні транзакції:" << endl;
    queue.push({ 1234, 3211, 234.4 });
    queue.push({ 4321, 5412, 1233.8 });
    print(queue);

    cout << "\nДодати ще 4 транзакції:" << endl;
    queue.push({ 87654, 543321, 12344 });
    queue.push({ 12397, 1223456, 4321 });
    queue.push({ 12345, 56541, 32 });
    queue.push({ 5432, 12343, 43322 });
    print(queue);

    cout << "\nВзяти перші дві транзакції, змінити місцями суми транзакцій та знову додати їх у чергу:" << endl;
    BankTransaction del1 = queue.pop();
    BankTransaction del2 = queue.pop();
    double sum = del1.sum;
    del1.sum = del2.sum;
    del2.sum = sum;
    queue.push(del1);
    queue.push(del2);
    print(queue);

    cout << "\nЗабрати 3 перші транзакції з черги:" << endl;
    for (int i = 0; i < 3; i++)
    {
        queue.pop();
    }
    print(queue);

    cout << "\nЗабрати ще 3 транзакції з черги:" << endl;
    for (int i = 0; i < 3; i++)
    {
        queue.pop();
    }

    print(queue);
    return 0;
}
