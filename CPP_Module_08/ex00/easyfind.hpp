#ifndef EASYFIND_HPP
#define EASYFIND_HPP

// 'typename T::iterator' iterator is an object that allows to look for elements inside container,
// typename is required, because 'T::iterator' depends on type T, so compiler needs to know that T::iterator is a type
// and not a static member
template <typename T>
typename T::iterator easyfind(T& container, int toFind) {
    typename T::iterator it = std::find(container.begin(), container.end(), toFind);
    if (it == container.end()) {
        throw std::exception();
    }
    return it;
}

#endif