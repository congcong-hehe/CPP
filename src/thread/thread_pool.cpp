// 如果在函数中创建一个线程但是想要它和主线程同步执行，可以使用一个全部vector存储子线程

#include <iostream>
#include <thread>
#include <string>
#include <vector>

using namespace std;

void downlod(const string &file)
{
    for(int i = 1; i <= 10; ++i)
    {
        cout << "Downlonding " << file << " " << i * 10 << " %" << endl;
        this_thread::sleep_for(std::chrono::milliseconds(400));     // 线程停止400ms
    }
}

void interact()
{
    string name;
    cin >> name;
    cout << "Hi, " << name << endl;
}

// 添加一个线程池全局变量，在主线程中等待结束
vector<thread> thread_pool;

void myFunc()
{
    thread t1(downlod, "hello.zip");    // 开启一个线程
    thread_pool.push_back(move(t1));
}

int main()
{
    myFunc();
    interact();
    for(auto &t : thread_pool)
        t.join();
    return 0;
}


