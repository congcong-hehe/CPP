// thrad.detach() 子线程从主线程中分离

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
    interact();
    t1.detach();  // 子线程和主线程分离，主线程return0，进程释放，子线程也结束
    
    return 0;
}


