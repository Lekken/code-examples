#ifndef LCONTAINERS_DIGITS_H
#define LCONTAINERS_DIGITS_H

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>


using DigitsContainer = std::vector<int>;

enum class DigitsState {
    Good,
    Bad
};

class Digits
{
    using iterator = DigitsContainer::iterator;
    using const_iterator = DigitsContainer::const_iterator;
    using reverse_iterator = DigitsContainer::reverse_iterator;
    using const_reverse_iterator = DigitsContainer::const_reverse_iterator;

public:
    explicit Digits() = default;
    explicit Digits(const std::string &num_string,
                    const uint32_t base = defaultBase);

    operator bool() const { return isCorrect(); }
    int operator[](int index) const { return container_[index]; }

    friend std::istream& operator>>(std::istream &, Digits &);
    friend std::ostream& operator<<(std::ostream &, const Digits &);

    void pushBack(int digit) { container_.push_back(digit); }
    // void pushBack(char digit) { /* do something */ }
    void popBack() { container_.pop_back(); }

    int at(int index) const { return container_.at(index); }
    int front() const { return container_.front(); }
    int back() const { return container_.back(); }

    uint32_t size() const { return container_.size(); }
    bool empty() const { return container_.empty(); }
    void clear() { container_.clear(); }

    iterator begin() { return container_.begin(); }
    const_iterator begin() const { return container_.begin(); }
    iterator end() { return container_.end(); }
    const_iterator end() const { return container_.end(); }

    reverse_iterator rbegin() { return container_.rbegin(); }
    const_reverse_iterator rbegin() const { return container_.rbegin(); }
    reverse_iterator rend() { return container_.rend(); }
    const_reverse_iterator rend() const { return container_.rend(); }

    DigitsState state() const { return state_; }
    bool isCorrect() const { return state_ == DigitsState::Good ? true : false; }

private:
    DigitsContainer parse(const std::string &strNum);
    bool checkBaseIsCorrect(const std::string &strNum);

    void setState(DigitsState state) { state_ = state; }

private:
    DigitsContainer container_;
    uint32_t base_ = defaultBase;
    DigitsState state_ = DigitsState::Bad;

    static constexpr uint32_t defaultBase = 10;
};

std::istream& operator>>(std::istream &is, Digits &obj);
std::ostream& operator<<(std::ostream &os, const Digits &obj);

#endif // LCONTAINERS_DIGITS_H
