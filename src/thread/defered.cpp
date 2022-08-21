// 一般线程在创建的时候就执行，使用launch::defered, 直到使用get或者wait的时候才执行

#include <iostream>
#include <thread>
#include <string>
#include <future>

using namespace std;

int downlod(const string &file)
{
    for(int i = 1; i <= 10; ++i)
    {
        cout << "Downlonding " << file << " " << i * 10 << " %" << endl;
        this_thread::sleep_for(std::chrono::milliseconds(400));     // 线程停止400ms
    }
    return 404;
}

void interact()
{
    string name;
    cin >> name;
    cout << "Hi, " << name << endl;
}

int main()
{
    future<int> fret = async(launch::deferred, [&]
    {
        return downlod("hello.zip");
    });
    //fret.wait();
    interact();

    cout << fret.get() << endl;
    return 0;
}


