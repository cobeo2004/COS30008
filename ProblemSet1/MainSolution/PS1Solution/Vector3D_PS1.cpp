#pragma once
#include "Vector3D.h"
#include <sstream>
#include <math.h>



std::string Vector3D::toString() const noexcept {
    std::stringstream ss;
    auto roundByTenSqrtFour = [](float roundNum) {
        float sqrtFour = 10000;
        float rounded = round(roundNum * sqrtFour) / sqrtFour;

        return rounded;
    };
    ss << "[" << roundByTenSqrtFour(x()) << ", " << roundByTenSqrtFour(y()) << ", " << roundByTenSqrtFour(w()) << "]";
    return ss.str();
    
}


