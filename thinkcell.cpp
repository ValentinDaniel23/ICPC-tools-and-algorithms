#include <map>
#include <bits/stdc++.h>

using namespace std;

template <typename K, typename V>
class interval_map
{
    friend void IntervalMapTest();
    V m_valBegin;
    std::map<K, V> m_map;

public:
    // constructor associates whole range of K with val
    template <typename V_forward>
    interval_map(V_forward &&val)
        : m_valBegin(std::forward<V_forward>(val))
    {
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    template <typename V_forward>
    void assign(K const &keyBegin, K const &keyEnd, V_forward &&val)
        requires(std::is_same<std::remove_cvref_t<V_forward>, V>::value)
    {
        // INSERT YOUR SOLUTION HERE

        if (!(keyBegin < keyEnd))
            return;

        auto itBegin = m_map.lower_bound(keyBegin);
        if (itBegin == m_map.end())
        {
            if (val == m_valBegin)
                return;

            m_map.insert({keyBegin, val});
            m_map.insert({keyEnd, m_valBegin});
        }
        else
        {
            auto itEnd = m_map.lower_bound(keyEnd);

            if (itEnd == m_map.begin())
            {
                if (m_valBegin == val)
                    return;

                if (keyEnd < itEnd->first)
                {
                    if (itEnd->second == m_valBegin)
                        m_map.erase(itEnd);
                    m_map.insert({keyBegin, val});
                    m_map.insert({keyEnd, m_valBegin});
                }
                else
                {
                    if (itEnd->second == val)
                        m_map.erase(itEnd);
                    m_map.insert({keyBegin, val});
                }
                return;
            }
            if (itEnd == m_map.end() || keyEnd < itEnd->first)
                m_map.insert({keyEnd, std::prev(itEnd)->second});

            if (itBegin != m_map.begin())
            {
                auto prevIt = std::prev(itBegin);
                auto itEnd = m_map.lower_bound(keyEnd);

                m_map.erase(itBegin, itEnd);

                if (prevIt->second == val)
                {
                    if (itEnd->second == val)
                        m_map.erase(itEnd);
                    return;
                }

                if (itEnd->second == val)
                    m_map.erase(itEnd);

                m_map.insert({keyBegin, val});
            }
            else
            {
                auto itEnd = m_map.lower_bound(keyEnd);
                m_map.erase(itBegin, itEnd);

                if (m_valBegin == val)
                {
                    if (itEnd->second == val)
                        m_map.erase(itEnd);
                    return;
                }

                if (itEnd->second == val)
                    m_map.erase(itEnd);

                m_map.insert({keyBegin, val});
            }
        }
    }

    // Type requirements: You must adhere to the specification of the key and value type given above.
    // For example, many solutions we receive use operations other than those that are explicitly stated in the task description.
    // We have to reject many solutions because they assume that V is default-constructible, e.g., by using std::map::operator[].

    // look-up of the value associated with key
    V const &operator[](K const &key) const
    {
        auto it = m_map.upper_bound(key);
        if (it == m_map.begin())
        {
            return m_valBegin;
        }
        else
        {
            return (--it)->second;
        }
    }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

// This time, it failed to meet this criterion:

// Type requirements: You must adhere to the specification of the key and value type given above. For example, many solutions we receive use operations other than those that are explicitly stated in the task description. We have to reject many solutions because they assume that V is default-constructible, e.g., by using std::map::operator[].
// Correctness (not checked): Your program should produce a working interval_map with the behavior described above. In particular, pay attention to the validity of iterators. It is illegal to dereference end iterators. Consider using a checking STL implementation, such as the one shipped with Visual C++ or GCC. Many solutions we receive do not create the data structure that was asked for, e.g., some interval ends up being associated with the wrong value. Others contain a code path that will eventually dereference an invalid or end iterator.
// Canonicity (not checked): The representation in m_map must be canonical. Some solutions we receive create consecutive map entries containing the same value, or repeat the value of m_valBegin at the beginning of the map.
// Running time (not checked): Imagine your implementation is part of a library and should therefore be big-O optimal:

// The assign function should have amortized time complexity of O(log N), where N is the number of elements in m_map.
// Minimize the number of copy-constructions and copy-assignments performed on K and V. Make use of std::forward where applicable.
// Only one operation may have amortized time complexity of O(log N). The rest must have amortized time complexity of O(1).
// Given the constraints above, avoid comparing K and V more often than necessary because you don't know how fast these operations are.
// Otherwise, favor simplicity over minor speed improvements.
// We regret that we cannot provide you with information specific to your solution, or with a correct version of the algorithm. If we did, we could no longer use this challenge for our interview process. We sincerely hope for your understanding on this matter.

// Since this was your final submission, we have decided not to offer you an interview.

// We want to thank you for your interest in the C++ Developer position at think-cell and for the time and effort you have put into taking our programming test. We know that C++ Developers are a scarce resource and that you have your pick of companies to work for. For this reason, we highly value your application.

// Arno, our CTO, and the HR Team want to thank you for your time and interest in our company. We wish you the very best in your future career.

void IntervalMapTest()
{
    interval_map<int, char> obj('A');

    cout << obj.m_valBegin << '\n';

    obj.assign(2, 5, 'B');
    obj.assign(5, 6, 'A');
    obj.assign(7, 10, 'B');
    obj.assign(1, 8, 'C');
    obj.assign(3, 9, 'D');
    obj.assign(-2, 5, 'A');
    obj.assign(1, 3, 'B');

    for (const auto &[k, v] : obj.m_map)
    {
        cout << k << ' ' << v << '\n';
    }
}

int main()
{
    IntervalMapTest();

    return 0;
}