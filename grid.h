#include <iostream>
#include <stdlib.h>

class Grid {
private:
    unsigned int _number_of_lines;
    unsigned int _number_of_columns;
    char ** grid;

public:
    Grid();

    Grid(unsigned int const& number_of_lines, unsigned int const& number_of_columns)
        :_number_of_lines(number_of_lines), _number_of_columns(number_of_columns)
    {
        grid = new char*[_number_of_lines];
        for ( int i = 0; i < _number_of_lines; i ++ ) 
        {
            grid[i] = new char[_number_of_columns];
            for ( int j = 0; j < _number_of_columns; j++ ) {
                grid[i][j] = ' ';
            }
        }
    }

    ~Grid() {
        for ( int i = 0; i < _number_of_lines; i ++ ) 
        {
            delete[] grid[i];
        }
        delete[] grid;
    }


    void setChar(int const& line, int const& column, char const& character)
    {
        grid[line][column] = character;
    }

    void print() const
    {
        for ( int i = 0; i < _number_of_lines; i++ ) 
        {
            for ( int j = 0; j < _number_of_columns; j++ ) {
                std::cout << " | " << grid[i][j];
            }
            std::cout << " |" << std::endl;
        }
    }

    void clean() const
    {
#ifdef WINDOWS
        system("CLS");
#else
        system("clear");
#endif
    }

};