#pragma once
#include "Slot.h"
#include <memory>

const int playCost = 5;

class Player
{
public:
    Player(unsigned balance, Slot& slot);
    void Play();
    void Deposit(unsigned deposit);
    void DisplayInfo()const;
    void CashOut();
private:
    unsigned m_balance;
    std::unique_ptr<Slot> m_slot = nullptr;
};