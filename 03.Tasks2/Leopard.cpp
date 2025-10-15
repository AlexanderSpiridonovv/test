#include "Leopard.h"
#include <error.h>
#include <stdexcept>
#include<iostream>

Leopard::Leopard() : Animal()
{
    _setType(AnimalType::Leopard);
}

Leopard::Leopard(const std::string& name, const double speed)
{
    _setType(AnimalType::Leopard);
    SetName(name);
    SetSpeed(speed);
}

void Leopard::_printType() const
{
    std::cout << "Leopard";
}

void Leopard::SetSpeed(const double speed)
{
    if(speed < 0 || speed > 120)
    {
        throw std::invalid_argument("Invalid speed for leopard (0-120 km/h)");
    }
    m_speed = speed;
}