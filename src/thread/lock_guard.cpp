// data race问题，就是数据的同时写问题
// mutex 加锁
// lock_gurad不需要手动unlock

#include <thread>
#include <vector>
#include <mutex>
#include <iostream>

using namespace std;

int main()
{
    vector<int> arr;
    mutex mtx;
    
    thread t1([&]
    {
        for(int i = 0; i < 10; ++i)
        {
            lock_guard grd(mtx);
            arr.push_back(1);
        }
    });

    thread t2([&]
    {
        for(int i = 0; i < 10; ++i)
        {
            lock_guard grd(mtx);
            arr.push_back(2);
        }
    });

    t1.join();
    t2.join();

    for(int i : arr)
        cout << i;

    return 0;
}