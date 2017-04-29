#include <iostream>
#include <memory>
#include <utility>

using namespace std;

template<typename T, typename Arg>
shared_ptr<T> factory(Arg& arg)
{
    cout << "factory1" << endl;
    return shared_ptr<T>(new T(arg));
}

template<typename T, typename Arg>
shared_ptr<T> factory(const Arg& arg)
{
    cout << "factory2" << endl;
    return shared_ptr<T>(new T(arg));
}

template<typename T, typename Arg>
shared_ptr<T> factory(Arg&& arg)
{
    cout << "factory3" << endl;
    return shared_ptr<T>(new T(forward<Arg>(arg)));
}

int getInt()
{
    return 99;
}

void profect_forwarding()
{
    shared_ptr<int> si(new int(5));
    auto ai = make_shared<int>(6);
    auto ai2(make_shared<int>(7));
    cout << *si << ":" << *ai << ":" << *ai2 << endl;

    {
        int int_for_f1 = 3;
        auto f1 = factory<int>(std::move(int_for_f1));
        cout << *f1 << endl;

        auto f2_1 = factory<int>(4);
        cout << *f2_1 << endl;

        auto f2_2 = factory<int>(getInt());
        cout << *f2_2 << endl;
    }
}

int main(void)
{
    int a = 1;

    // int &r = 3;             // L-value Reference must be L-value
    const int &cra = 3;    // OK? Why?
    int &ra = a;   //

    int b = 10;
    int &&rb = 20;
    rb = b;

    profect_forwarding();

    return 0;
}
