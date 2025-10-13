#pragma once
#include "Animal.h"

class Turtle : public Animal {
    void _printType() const override;
public:
    Turtle();
    Turtle(const std::string& name, const double speed);
    void SetSpeed(const double speed) override;
};