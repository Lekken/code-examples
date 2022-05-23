#ifndef DIGITSFABRIC_H
#define DIGITSFABRIC_H

#include <cstdint>
#include <set>
#include <vector>


class Alphabet
{
    using iterator = std::vector<char>::iterator;
    using const_iterator = std::vector<char>::const_iterator;

public:
    Alphabet(uint32_t base = defaultBase);

    std::vector<char> operator()(uint32_t base = defaultBase);
    char& operator[](int index) { return alphabet_[index]; }

    std::vector<char> create(uint32_t base = defaultBase);

    std::vector<char> alphabet() const { return  alphabet_; }

    uint32_t size() const { return alphabet_.size(); }

    char at(int index) const { return alphabet_.at(index); }

    iterator begin() { return alphabet_.begin(); }
    const_iterator begin() const { return alphabet_.begin(); }
    iterator end() { return alphabet_.end(); }
    const_iterator end() const { return alphabet_.end(); }

    static const std::set<char> digits();
    static const std::set<char> alpha();

private:
    static constexpr uint32_t defaultBase = 10;

    uint32_t base_ = defaultBase;
    std::vector<char> alphabet_;
};

#endif // DIGITSFABRIC_H
