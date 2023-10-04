#include "carport.h"
Carport::Carport(bool a, int b)
{
    empty = a;
    order = b;
}

int Carport::getorder()
{
    return order;
}
