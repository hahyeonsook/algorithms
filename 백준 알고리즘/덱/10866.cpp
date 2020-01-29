#include <iostream>
#include <string>

using namespace std;

struct Deque
{
    int data[10000];
    int begin, end;

    Deque()
    {
        begin = 5000;
        end = 5000;
    }

    void push_front(int num)
    {
        data[begin] = num;
        begin--;
    }
    void push_back(int num)
    {
        end++;
        data[end] = num;
    }
    bool empty()
    {
        if (begin == end)
            return true;
        else
            return false;
    }
    int pop_front()
    {
        if (empty())
            return -1;
        else
        {
            begin++;
            return data[begin];
        }
    }
    int pop_back()
    {
        if (empty())
            return -1;
        else
        {
            end--;
            return data[end + 1];
        }
    }
    int size()
    {
        return end - begin;
    }
    int front()
    {
        if (empty())
            return -1;
        else
            return data[begin + 1];
    }
    int back()
    {
        if (empty())
            return -1;
        else
            return data[end];
    }
};

int main()
{
    Deque d;
    int t;

    cin >> t;

    while (t--)
    {
        string cmd;

        cin >> cmd;

        if (cmd == "push_back")
        {
            int num;
            cin >> num;
            d.push_back(num);
        }
        if (cmd == "push_front")
        {
            int num;
            cin >> num;
            d.push_front(num);
        }
        if (cmd == "empty")
            cout << d.empty() << '\n';
        if (cmd == "pop_front")
            cout << d.pop_front() << '\n';
        if (cmd == "pop_back")
            cout << d.pop_back() << '\n';
        if (cmd == "size")
            cout << d.size() << '\n';
        if (cmd == "front")
            cout << d.front() << '\n';
        if (cmd == "back")
            cout << d.back() << '\n';
    }

    return 0;
}