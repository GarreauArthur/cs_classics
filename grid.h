#include <iostream>
#include <stdlib.h>
#include "rlutil/rlutil.h"

class Grid {
public:
    static const char WALL = '#';
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

    void print(int const& type) const
    {
        switch ( type )
        {
            case 0:
                printWithBorders();
            break;

            case 1:
                printWithPoints();
            break;
            
            default:
                printWithSpaces();
            break;
        }
    }

    void printWithBorders() const
    {
        std::cout << "+";
        for ( int k = 0; k < _number_of_columns; k++ )
        {
            std::cout << "---+";
        }
        std::cout << std::endl;

        for ( int i = 0; i < _number_of_lines; i++ ) 
        {
            for ( int j = 0; j < _number_of_columns; j++ ) {
                std::cout << "| ";
                rlutil::setColor(rlutil::GREEN);
                std::cout << grid[i][j] << " ";
                rlutil::setColor(rlutil::GREY);
            }
            std::cout << "|" << std::endl;

            std::cout << "+";
            for ( int k = 0; k < _number_of_columns; k++)
            {
                std::cout << "---+";
            }
            std::cout << std::endl;

        }
    }

    void printWithSpaces() const
    {

        std::cout << "#";
        for ( int k = 0; k < _number_of_columns; k++ )
        {
            std::cout << "#";
        }
        std::cout << "#" << std::endl;
        
        for ( int i = 0; i < _number_of_lines; i++ ) 
        {
            std::cout << "#";
            for ( int j = 0; j < _number_of_columns; j++ ) {
                rlutil::setColor(rlutil::GREEN);
                std::cout << grid[i][j];
                rlutil::setColor(rlutil::GREY);
            }
            std::cout << "#" << std::endl;
        }
        
        std::cout << "#";
        for ( int k = 0; k < _number_of_columns; k++ )
        {
            std::cout << "#";
        }
        std::cout << "#" << std::endl;
    }

    void printWithPoints() const
    {
        std::cout << "#";
        for ( int k = 0; k < _number_of_columns; k++ )
        {
            std::cout << "#";
        }
        std::cout << "#" << std::endl;
        
        for ( int i = 0; i < _number_of_lines; i++ ) 
        {
            std::cout << "#";
            for ( int j = 0; j < _number_of_columns; j++ ) {
                if ( grid[i][j] == ' ' )
                {
                    std::cout << '.';
                }
                else
                {
                    rlutil::setColor(rlutil::GREEN);
                    std::cout << grid[i][j];
                    rlutil::setColor(rlutil::GREY);
                }
            }
            std::cout << "#" << std::endl;
        }
        
        std::cout << "#";
        for ( int k = 0; k < _number_of_columns; k++ )
        {
            std::cout << "#";
        }
        std::cout << "#" << std::endl;
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