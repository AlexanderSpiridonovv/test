#include "Turtle.h"
#include <error.h>
#include <stdexcept>
#include <iostream>

Turtle::Turtle() : Animal()
{
    _setType(AnimalType::Turtle);
}

Turtle::Turtle(const std::string& name, const double speed)
{
    _setType(AnimalType::Turtle);
    SetName(name);
    SetSpeed(speed);
}

void Turtle::_printType() const
{
    std::cout << "Turtle";
}

void Turtle::SetSpeed(const double speed)
{
    if(speed < 0 || speed > 10)
    {
       throw std::invalid_argument("Invalid speed for turtle (0-10 km/h)");
    }
    m_speed = speed;
}