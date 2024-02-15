#include <iostream>
#include <thread>

using namespace std;

void f() {
    cout << "Hello concurrent world!" << endl;
}

int main() {
    thread t(f);
    t.join();
    return 0;
}
