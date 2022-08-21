// 当我们需要子线程返回值的时候，可以使用async，它其实是promise和future的封装

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
    future<int> fret = async([&]
    {
        return downlod("hello.zip");
    });
    interact();

    cout << fret.get() << endl;
    return 0;
}


