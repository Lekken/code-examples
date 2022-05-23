#include <algorithm>
#include <iomanip>
#include <stdexcept>

#include "digits.h"
#include "alphabet.h"


Digits::Digits(const std::string &num_string,
                const uint32_t base)
    : base_(base)
{
    parse(num_string);
}

DigitsContainer Digits::parse(const std::string &strNum)
{
    container_.clear();

    if ( strNum.empty() )
        setState(DigitsState::Bad);
    else if ( !checkBaseIsCorrect(strNum) )
        setState(DigitsState::Bad);
    else
        setState(DigitsState::Good);

    if ( isCorrect() ) {
        for (auto ch : strNum) {
            int num = std::stoi(std::string(1, ch), nullptr, static_cast<int>(base_));
            container_.push_back(num);
        }
    }

    return container_;
}

bool Digits::checkBaseIsCorrect(const std::string &strNum)
{
    Alphabet alphabet(base_);
    for (auto it : strNum) {
        auto found = std::find( alphabet.begin(), alphabet.end(), std::toupper(it) );
        if (found == alphabet.end())
            return false;
    }

    return true;
}


std::istream& operator>>(std::istream &is, Digits &obj)
{
    std::string str;
    std::getline(is >> std::ws, str);
    obj.parse(str);
    is.sync();
    return is;
}

std::ostream& operator<<(std::ostream &os, const Digits &obj)
{
    for (auto it : obj.container_)
        os << it;

    return os;
}
