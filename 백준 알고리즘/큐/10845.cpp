#include <iostream>

using namespace std;

struct Queue
{
    int data[10000];
    int begin, end;

    Queue()
    {
        begin = 0;
        end = 0;
    }

    int size()
    {
        return end - begin;
    }

    void push(int num)
    {
        data[end] = num;
        end++;
    }
    bool empty()
    {
        if (begin == end)
            return true;
        else
            return false;
    }
    int front()
    {
        if (empty())
            return -1;
        else
            return data[begin];
    }
    int back()
    {
        if (empty())
            return -1;
        else
            return data[end - 1];
    }
    int pop()
    {
        if (empty())
            return -1;
        begin += 1;
        return data[begin - 1];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    Queue q;

    cin >> t;

    while (t--)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "push")
        {
            int num;
            cin >> num;
            q.push(num);
        }
        if (cmd == "pop")
            cout << q.pop() << '\n';
        if (cmd == "front")
            cout << q.front() << '\n';
        if (cmd == "back")
            cout << q.back() << '\n';
        if (cmd == "size")
            cout << q.size() << '\n';
        if (cmd == "empty")
            cout << q.empty() << '\n';
    }
    return 0;
}