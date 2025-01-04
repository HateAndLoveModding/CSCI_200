#ifndef ISOSCELES_TRIANGLE
#define ISOSCELES_TRIANGLE

#include "Triangle.h"

class IsoscelesTriangle : public Triangle {
    public:
    bool validate() override;
};

#endif