#include "alphabet.h"
#include "digits.h"


int main(int argc, char *argv[])
{
    const std::string test_expr = "1Z7vi4";
    Digits digits(test_expr, 36);

    if ( digits.isCorrect() ) {
        std::cout << "{ ";
        for ( auto it : digits )
            std::cout << it << " ";
        std::cout << "}";
    } else {
        std::cerr << "Not correct!" << std::endl;
    }

    return EXIT_SUCCESS;
}