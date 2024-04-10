//
// Created by admin on 2024/4/10.
//

#include <iostream>
#include <utility>

using namespace std;

class foo {
public:
    foo() {
        cout << "constructor" << endl;
    }

    ~foo() {
        cout << "destructor" << endl;
    }

    foo(const foo &temp) {
        cout << "copy constructor" << endl;
    }

    foo(foo &&temp) noexcept {
        cout << "move constructor" << endl;
    }

    foo &operator=(const foo &temp) {
        cout << "copy assign" << endl;
        return *this;
    }

    foo &operator=(foo &&temp) noexcept {
        cout << "move assign" << endl;
        return *this;
    }
};

pair<foo, foo> func() {
    foo a1, a2;
    return {std::move(a1), std::move(a2)};
}

int main(int argc, char *argv[]) {
    auto &&[b1, b2] = func();
    return 0;
}