// 创建一个ThreadPool类，自动析构执行join

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

class ThreadPool
{
private:
    vector<thread> m_pool;

public:
    void push_back(thread t)
    {
        m_pool.push_back(move(t));
    }
    ~ThreadPool()
    {
        for(auto &t : m_pool)
            t.join();
    }
};

ThreadPool thread_pool;

void myFunc()
{
    thread t1(downlod, "hello.zip");    // 开启一个线程
    thread_pool.push_back(move(t1));
}

int main()
{
    myFunc();
    interact();
    return 0;
}


