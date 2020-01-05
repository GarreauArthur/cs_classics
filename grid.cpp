#include "grid.h"

int main ()
{
    Grid g(50,50);
    g.print(1);
    while ( true ) {
        char a;
        std::cout << "un char" << std::endl;
        std::cin >> a;
        g.setChar(4,4,a);
        g.setChar(2,2,a);
        g.clean();
        g.print(1);
    }

}