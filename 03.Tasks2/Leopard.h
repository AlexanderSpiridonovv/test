#pragma once
#include "Animal.h"

class Leopard : public Animal {
    void _printType() const override;
public:
    Leopard();
    Leopard(const std::string& name, const double speed);
    void SetSpeed(const double speed) override;
};