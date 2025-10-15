#include "Animal.h"
#include <iostream>


void Animal::_setType(AnimalType type)
{
    m_type = type;
}

Animal::Animal()
{
    _setType(AnimalType::Undefined);
    SetName("");
    m_speed = 0;
} 
void Animal::SetName(const std::string& name)
{
    m_name = name;
}
auto Animal::GetName() const -> const std::string&
{
    return m_name;
}
auto Animal::GetSpeed() const -> const double
{
    return m_speed;
}
auto Animal::GetTimeForDistance(const double distance) const -> double
{
    return distance / m_speed;
}
void Animal::Print(const double distance) const{
    _printType();
    std::cout<< " | " 
    << GetName() << " | "
    << GetSpeed() << " km/h | " 
    << GetTimeForDistance(distance) << " h \n"; 
}