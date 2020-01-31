#include <iostream>
#include <stack>
#include <string>

using namespace std;
struct Stack
{
    int data[1000];
    int size;

    Stack()
    {
        size = 0;
    }
    void push(int num)
    {
        data[size] = num;
        size++;
    }
    bool empty()
    {
        if (size == 0)
            return true;
        else
            return false;
    }
    int pop()
    {
        if (empty())
            return -1;
        else
        {
            size--;
            return data[size];
        }
    }
    int top()
    {
        if (empty())
            return -1;
        else
            return data[size - 1];
    }
};

int main()
{
    int n;
    cin >> n;

    Stack s;

    while (n--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "push")
        {
            int num;
            cin >> num;
            s.push(num);
        }
        else if (cmd == "top")
            cout << s.top() << '\n';
        else if (cmd == "size")
            cout << s.size << '\n';
        else if (cmd == "empty")
            cout << s.empty() << '\n';
        else if (cmd == "pop")
            cout << s.pop() << '\n';
    }
    return 0;
}