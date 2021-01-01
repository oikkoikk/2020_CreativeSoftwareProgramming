#include <iostream>
#include <cassert>
#include "p1.h"

int main() {
    auto array = Array<float>();

    array + 3.f;
    assert(array.size() == 1);
    assert(array[0] == 3.f);

    array += 1.f;
    assert(array.size() == 2);
    assert(array[0] == 1.f);

    array + 5.f + 3.f + 7.f + 3.f;
    assert(array.size() == 6);
    assert(array[2] == 5.f &&
           array[3] == 3.f &&
           array[4] == 7.f &&
           array[5] == 3.f);

    array - 3.f;
    assert(array.size() == 5);
    assert(array[1] == 5.f);

    array -= 3.f;
    assert(array.size() == 4);
    assert(array[3] == 7.f);

    assert(array[0] == 1.f &&
           array[1] == 5.f &&
           array[2] == 3.f &&
           array[3] == 7.f);

    array * 2.f;
    assert(array[0] == 2.f &&
           array[1] == 10.f &&
           array[2] == 6.f &&
           array[3] == 14.f);

    array / 2.f;
    assert(array[0] == 1.f &&
           array[1] == 5.f &&
           array[2] == 3.f &&
           array[3] == 7.f);

    return 0;
}
