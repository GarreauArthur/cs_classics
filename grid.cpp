#include "grid.h"

int main ()
{
    Grid g(10,10);
    g.print();
    while ( true ) {

        char a;
        std::cout << "un char" << std::endl;
        std::cin >> a;
        g.setChar(4,4,a);
        g.clean();
        g.print();
    }

}