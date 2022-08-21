// c++ 时间标准库 chrono
// thread.join() 主线程等待子线程结束

#include <iostream>
#include <thread>
#include <string>

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

int main()
{
    thread t1(downlod, "hello.zip");    // 开启一个线程
    // thread t1([&]{ downlod("hello.zip"); });
    interact();
    t1.join();  // 主线程会等待子线程结束, 再执行
    
    return 0;
}


