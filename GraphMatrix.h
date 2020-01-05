
class GraphMatrix
{
private:
  unsigned int _number_of_nodes;
  int ** _matrix;

public:
  GraphMatrix(unsigned int const& number_of_nodes)
    :_number_of_nodes(number_of_nodes)
  {
    _matrix = new int*[_number_of_nodes];
    for ( int i = 0; i < _number_of_nodes; i++ )
    {
      _matrix[i] = new int[_number_of_nodes];
    }
  }

  ~GraphMatrix() {

    for ( int i = 0; i < _number_of_nodes; i++ )
    {
      delete[] _matrix[i];
    }
    delete[] _matrix;
  }

};