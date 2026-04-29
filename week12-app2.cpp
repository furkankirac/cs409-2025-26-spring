// tuples: how to design our own new dialect tuple structure? A case-study

#include <iostream>
#include <tuple>

using namespace std;

template<typename First, typename ... Rest>
struct Tuple {
    First first; // int first;
    Tuple<Rest...> rest; // Tuple<float, double>

    template<size_t dist>
    auto get() const {
        if constexpr(dist == 0) {
            return first;
        } else {
            return rest.template get<dist-1>();
        }
    }

    template<typename T>
    auto get() const {
        if constexpr(is_same_v<T, First>) {
            return first;
        } else {
            return rest.template get<T>();
        }
    }
};

template<typename T>
struct Tuple<T> {
    T first; // int first;

    template<size_t dist>
    auto get() const {
        static_assert(dist==0, "OUT OF BOUNDS");
        return first;
    }

    template<typename U>
    auto get() const {
        static_assert(is_same_v<U, T>, "CANNOT FIND IT");
        return first;
    }
};


template<size_t dist, typename ... Ts>
auto myget(const Tuple<Ts...>& t) {
    return t.template get<dist>();
}

template<typename Target, typename ... Ts>
auto myget(const Tuple<Ts...>& t) {
    return t.template get<Target>();
}


// struct X {
//     int i;
//     float f;
// };




int main()
{
    // auto t = Tuple<int, float>{1, 2};

    auto t = Tuple<int, float, double, float>{1, 2.2f, 3.3, 4.4f};
    // cout << t.get<0>() << endl;
    // cout << t.get<float>() << endl;

    cout << myget<0>(t) << endl;
    cout << myget<float>(t) << endl;

    // get<0>(t);
    // get<int>(t);


    return 0;
}
