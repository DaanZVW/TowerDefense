// ======================================
// = Author: Daan Zimmerman van Woesik  =
// = Insitute: HU                       =
// = Date: 12/12/2019                   =
// ======================================

#include <SFML/Graphics.hpp>
#include <vector>


class path {
private:

    std::vector<int> nodes;

public:

    path( const std::vector<int> &nodes ):
        nodes( nodes )
    {}

    
};