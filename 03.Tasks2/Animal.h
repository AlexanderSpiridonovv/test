#pragma once
#include <string>

enum class AnimalType{
    Undefined,
    Leopard,
    Turtle
};

class Animal
{
protected:
    std::string m_name; 
    double m_speed;
    AnimalType m_type;
    void _setType(AnimalType type);
    static void _printTypeHelper(AnimalType type);
    virtual void _printType() const = 0;
public:
    Animal();
    virtual ~Animal() = default;
    void SetName(const std::string& name);
    auto GetName() const -> const std::string&;
    virtual void SetSpeed(const double speed) = 0;
    auto GetSpeed() const -> const double;
    auto GetTimeForDistance(const double distance) const -> double;
    void Print(const double distance) const;
};