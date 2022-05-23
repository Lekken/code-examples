#include "alphabet.h"

constexpr uint32_t MaxBase = 36;

Alphabet::Alphabet(uint32_t base) : base_(base)
{
    create(base);
}

std::vector<char> Alphabet::operator()(uint32_t base)
{
    return create(base);
}

std::vector<char> Alphabet::create(uint32_t base)
{
    auto digits_ = digits();
    auto upperAlpha_ = alpha();

    if ( base > 1 && base <= MaxBase ) {
        if ( base < digits_.size() ) {
            auto it = digits_.begin();
            for ( size_t i = 0; i < base; ++i )
                alphabet_.push_back( *it++ );
        } else {
            uint32_t alphanums = base - digits_.size();

            alphabet_.insert( alphabet_.begin(), digits_.begin(), digits_.end() );

            auto uit = upperAlpha_.begin();
            for ( size_t i = 0; i < alphanums; ++i )
                alphabet_.push_back( *uit++ );
        }
    }

    return alphabet_;
}

const std::set<char> Alphabet::digits()
{
    return { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
}

const std::set<char> Alphabet::alpha()
{
    return { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
             'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
             'U', 'V', 'W', 'X', 'Y', 'Z' };
}
