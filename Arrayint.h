#ifndef LESSON_4_ARRAYINT_H
#define LESSON_4_ARRAYINT_H

#include <cassert>
#include <iostream>
#include <algorithm>

//-----------------------
// Task 1
//-----------------------

class ArrayInt {
private:
    int m_length;
    int* m_data;

public:
    ArrayInt() : m_length(0), m_data(nullptr) {}

    ArrayInt(int length):
    m_length(length)
    {
        assert (length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }
    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    int getLength() {return m_length;}

    int& operator[] (int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    void resize(int new_length)
    {
        if (new_length == m_length) {return;}

        if (new_length <= 0)
        {
            erase();
            return;
        }

        int* data = new int[new_length];

        if (m_length > 0)
        {
            int elementsToCopy = (new_length > m_length) ? m_length : new_length;

            for (int index=0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        delete[] m_data;

        m_data = data;
        m_length = new_length;
    }

    void insertBefore (int value, int index)
    {
        assert(index >= 0 && index <= m_length);

        int* data = new int[m_length + 1];

        for(int before = 0; before < index; ++before)
            data[before] = m_data[before];

        data[index] = value;

        for (int after = index; after < m_length; ++after)
            data[after+1] = m_data[after];

        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void push_back(int value)
    {
        insertBefore(value, m_length);
    }

    void pop_back()
    {
        int* data = new int[m_length - 1];

        for (int i = 0; i < (m_length - 1); ++i)
            data[i] = m_data[i];

        delete[] m_data;
        m_data = data;
        --m_length;
    }

    void pop_front()
    {
        int* data = new int[m_length - 1];

        for (int i = m_length; i > 0; --i)
            data[i - 1] = m_data[i];

        delete[] m_data;
        m_data = data;
        --m_length;
    }

    void sort()

    {
        for (int idx_i = 0; idx_i < m_length - 1; ++idx_i) {
            int min_idx = idx_i;

            for (int idx_j = idx_i + 1; idx_j < m_length; ++idx_j) {
                if (m_data[idx_j] < m_data[min_idx]) {
                    min_idx = idx_j;
                }
            }

            if (min_idx != idx_i) {
                std::swap(m_data[idx_i], m_data[min_idx]);
            }
        }
    }

    void print()

    {
        std::cout << "[ ";
        for (int i = 0; i < m_length; ++i)
             std::cout << m_data[i] << " ";
        std::cout << "]" << std::endl;
    }

};

#endif //LESSON_4_ARRAYINT_H
