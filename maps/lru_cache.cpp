#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class LRUCache
{
public:
    int capacity;
    unordered_map<int, int> map;
    queue<int> q;

    LRUCache(int capacity);
    int get(int key);
    void set(int key, int value);
};

LRUCache::LRUCache(int capacity)
{
    this->capacity = capacity;
}

int LRUCache::get(int key)
{
    if (map.find(key) == map.end())
        return -1;
    else
    {
        queue<int> temp;
        while (!q.empty())
        {
            if (q.front() != key)
                temp.push(q.front());
            q.pop();
        }
        q = temp;
        q.push(key);
        return map[key];
    }
}

void LRUCache::set(int key, int value)
{
    if (map.find(key) == map.end())
    {
        if (q.size() == capacity)
        {
            map.erase(q.front());
            q.pop();
        }
        q.push(key);
        map[key] = value;
    }
    else
    {
        queue<int> temp;
        while (!q.empty())
        {
            if (q.front() != key)
                temp.push(q.front());
            q.pop();
        }
        q = temp;
        q.push(key);
        map[key] = value;
    }
}

int main()
{
    LRUCache cache(2);
    cache.set(1, 10);
    cache.set(5, 12);
    cout << cache.get(5) << endl;
    cout << cache.get(1) << endl;
    cout << cache.get(10) << endl;
    cache.set(6, 14);
    cout << cache.get(5) << endl;
    return 0;
}