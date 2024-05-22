#ifndef graphs
#define graphs

#include <vector>
#include <tuple>


template <typename T>
class Graphs {

typedef std::vector<T> vector;
typedef std::tuple<T,T> tuple;


private:
public:
    vector nodes;
    std::vector<tuple> edges;
    
    Graphs();
    ~Graphs();
};

#endif