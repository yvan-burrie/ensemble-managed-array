/* License: MIT. See LICENSE in root directory. */

/**
 * \date 2020/06/27
 */

#include <cassert>

#include <ensemble/managed-array.hpp>

using Ensemble::ManagedArray;

int main()
{
    auto m = new ManagedArray<>;

    assert(m->add(99)); // Add a new value.
    assert(m->number() == 1); // There should be exactly 1 value added.
    assert(m->add(99) == false); // Add the same value and ensure it fails since only unique values can be added.
    assert(m->number() == 1); // There should still be only 1 value.
    assert(m->add(100)); // Add another unique value.
    assert(m->number() == 2); // There should 2 values.
    assert(m->contains(1) == false); // There should not be a nonexisting value.
    assert(m->contains(100)); // There should be an existing value.
}
