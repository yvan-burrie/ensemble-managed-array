/* License: MIT. See LICENSE in root directory. */

/**
 * \date 2020/06/27
 */

#pragma once

#ifndef ENSEMBLE_MANAGED_ARRAY_VERSION
#define ENSEMBLE_MANAGED_ARRAY_VERSION 1
#endif

namespace Ensemble {

template<typename T = int>
class ManagedArray {

protected:

    T* m_values = nullptr;

    int m_count = 0;

    int m_desiredNumberValue = 0;

    /**
     * Determines the hidden number of values that are ready to be filled with new values.
     */
    int m_allocatedSize = 0;

#if ENSEMBLE_MANAGED_ARRAY_VERSION >= 2
    int m_initialSize = 0;
#endif

public:

#if ENSEMBLE_MANAGED_ARRAY_VERSION >= 2
    explicit
    ManagedArray(int initialSize = 0);
#else
    ManagedArray() = default;
#endif

    ~ManagedArray();

protected:

    bool resize(int desiredSize);

public:

    /**
     * Checks if a value is found in the values.
     */
    bool contains(T);

    /**
     * Appends a new value into the values.
     * The new value must be unique.
     * The number of values will increment if need be.
     * @return Only returns true if the new value was added into the values.
     */
    bool add(T);

    T operator[](int);

    bool remove(T);

    /**
     * Retrieves the current number of values.
     */
    [[nodiscard]] inline
    int number() const
    { return m_count; }

    /**
     * Resets the current number of values.
     */
    inline
    void zeroNumber()
    { m_count = 0; }

    [[nodiscard]] inline
    int desiredNumber() const
    { return m_desiredNumberValue; }

    inline
    void setDesiredNumber(int v)
    { m_desiredNumberValue = v; }
};

template class ManagedArray<int>;

} // namespace Ensemble
