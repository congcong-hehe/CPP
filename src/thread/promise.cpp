// promise配合future执行，在一个线程中保存一个typename T类型的值，在另一个线程中通过future获得

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
    promise<int> pret;
    thread t = thread([&]
    {
        auto ret = downlod("hello.zip");
        pret.set_value(ret);
    });
    future<int> fret = pret.get_future();

    interact();

    cout << fret.get() << endl;
    t.join();
    return 0;
}


