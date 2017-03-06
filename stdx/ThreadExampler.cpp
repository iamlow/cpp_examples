#pragma once

#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

template<typename TF>
void log(std::ostream & out, TF const& f) {
    out << f << std::endl;
}

template<typename TF, typename ... TR>
void log(std::ostream & out, TF const& f, TR const& ... rest) {
    out << f << " ";
    log(out, rest...);
}

#define trace(...) log(std::cout, __func__, __LINE__, __VA_ARGS__)

namespace cppexam {
namespace stdx {

class ThreadExampler {
public:
    ThreadExampler()
    {
        trace("Constructor is entered");
        th_ = std::thread(
            [&] ()
            {
                trace("Thread is created!");
                while (status_) {
                    trace("Thread is running!");
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
                trace("Thread is destoryed!");
            }
        );
        trace("Constructor is leaved");
    }

    ~ThreadExampler()
    {
        trace("Destructor is entered");
        status_ = false;
        th_.join();
        trace("Destructor is leaved");
    }

private:
    std::thread th_;
    bool status_ = true;
};
} // stdx
} // cppexam

int main(int argc, char *argv[])
{
    std::shared_ptr<cppexam::stdx::ThreadExampler> te(new cppexam::stdx::ThreadExampler());
    trace("waiting for one second!");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return 0;
}
