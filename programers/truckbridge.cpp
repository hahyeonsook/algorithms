#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int time = 0;
int on_trucks = 0;
queue<int> trucks;

void update_bridge(int num, int weight)
{
    time += 1;
    on_trucks += weight;
    trucks.push(num);
}
void update_truck(vector<int> &truck_lengths)
{
    for (int i = 0; i < trucks.size(); i++)
    {
        if (truck_lengths[i] <= 0)
            trucks.pop();
        truck_lengths[i] -= 1;
        cout << truck_lengths[i] << ' ';
    }
    cout << '\n';
}

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    vector<int> truck_lengths(truck_weights.size(), bridge_length);
    sort(truck_weights.begin(), truck_weights.end());
    for (int i = 0, size = truck_weights.size(); i < size; i++)
    {
        update_bridge(i, truck_weights[i]);
        update_truck(truck_lengths);
        cout << '\n';
    }
    while (!trucks.empty())
    {
        update_truck(truck_lengths);
        cout << '\n';
    }
    answer = time;
    return answer;
}
int main()
{
    vector<int> truck_weights;
    int bridge_length = 2, weight = 10;
    int arr[] = {7, 4, 5, 6};
    for (int i = 0; i < 4; i++)
        truck_weights.push_back(arr[i]);
    cout << solution(bridge_length, weight, truck_weights);
    return 0;
}