#include "Slot.h"
#include "PayoutTable.h"
#include "VectorOfLines"
#include <iostream>
#include <random>
#include <utility>

auto Slot::_generateSymbol()const -> Symbol
{
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, SymbolCount - 1); // 10 symbols total
    return static_cast<Symbol>(dist(rng));
}

void Slot::_populateSlot()
{
    scatterCount = 0;

    for(int col = 0; col < Reels; col++)
    {
        bool scatterUsed = false;
        for(int row = 0; row < Rows; row++)
        {
            Symbol symbol; 
            do
            {
               symbol = _generateSymbol();
            } while(scatterUsed && symbol == Symbol::SCATTER);

            if(symbol == Symbol::SCATTER)
            {
                scatterUsed = true;
                scatterCount++;
            }

            m_slot[row][col] = symbol;
        }
    }
}

void Slot::_printMatrix()const
{
    for(int i = 0; i < Rows; i++)
    {
        for(int j = 0; j < Reels; j++)
        {
            std::cout << symbolToStringForSlot(m_slot[i][j]) << ' ';
        }
        std::cout << std::endl << std::endl;
    }
}
auto Slot::_getNormalSymbolKeyByLine(const std::vector<int>& line)const -> std::pair<Symbol,int>
{
    Symbol symbol = m_slot[line[0]][0];
    //scatter win logic is handled separately
    if(symbol == Symbol::SCATTER)
    {
        return {Symbol::SCATTER,0};
    }
    //for non pure wild wins starting with wild
    if(symbol == Symbol::WILD)
    {
        int wildCount = _getConsecutiveWildsByLine(line);
        if(wildCount < Reels)
        {
            int count = wildCount;
            Symbol base = m_slot[line[count]][count];
            if(base == Symbol::SCATTER)
            {
                return {Symbol::SCATTER,0};
            }
            while(count < Reels && 
                 (m_slot[line[count]][count] == base || 
                  m_slot[line[count]][count] == Symbol::WILD))
            {
                count++;
            }
            return {base,count};
        }
        return {symbol,0};
    }
    else
    {
       int count = 1;
       while(count < Reels && 
            (m_slot[line[count]][count] == symbol || 
             m_slot[line[count]][count] == Symbol::WILD))
        {
            count++;
        }
        return {symbol,count};
    }
}
auto Slot::_getConsecutiveWildsByLine(const std::vector<int>& line)const -> int
{
    int count = 0;
    while(count < Reels && m_slot[line[count]][count] == Symbol::WILD) 
    {
        count++;
    }
    return count;
}
auto Slot::_getWildKeyByLine(const std::vector<int>& line)const -> std::pair<Symbol,int>
{
    int count = _getConsecutiveWildsByLine(line);
    return {Symbol::WILD,count};
}
auto Slot::_getWinnigsAmount(const std::pair<Symbol,int>& win)const -> int
{
    auto it = PayoutTable.find(win);
    if(it == PayoutTable.end())
    {
        return 0;
    }
    return it -> second;
}
void Slot::_printWinnigsHelper(const std::pair<Symbol,int>& win)const
{
    int currentWin = _getWinnigsAmount(win);

    if(currentWin == 0)
    {
        return;
    }
    for(int i = 0; i < win.second; i++)
    {
        //predefined operator <<
        std::cout << win.first << ' ';
    }
    std::cout << "= " << currentWin << std::endl;
}
auto Slot::_getWinnigsFromLine(const std::vector<int>& line)const -> int
{
    auto normalPair =  _getNormalSymbolKeyByLine(line);
    auto wildPair = _getWildKeyByLine(line);
    
    
    int normalWin = _getWinnigsAmount(normalPair);
    int wildWin = _getWinnigsAmount(wildPair);
    
    return normalWin + wildWin;
}
void Slot::_printWinnigsFromLine(const std::vector<int>& line)const
{
    auto normalPair =  _getNormalSymbolKeyByLine(line);
    auto wildPair = _getWildKeyByLine(line);

    
    _printWinnigsHelper(normalPair);
    _printWinnigsHelper(wildPair);
}

auto Slot::_getScatterWinAmount()const -> int
{
    return _getWinnigsAmount({Symbol::SCATTER,scatterCount});
}
auto Slot::GetTotalWinnings()const -> int
{
    int totalWin = 0;
    for(const auto& line : lines)
    {
        totalWin += _getWinnigsFromLine(line);
    }

    totalWin += _getScatterWinAmount();

    return totalWin;
}
void Slot::_printAllWinnings()const
{
    int totalWin = GetTotalWinnings();
    if(totalWin == 0)
    {
       return;
    }
    for(const auto& line : lines)
    {
        _printWinnigsFromLine(line);
    }

    _printWinnigsHelper({Symbol::SCATTER,scatterCount});
    std::cout << "\nTotal win: " << totalWin << std::endl;

}
void Slot::Play()
{
    _populateSlot();
    _printMatrix();
    std::cout << "\n----------------------------------------------------------------\n" << std::endl;
    _printAllWinnings();
    std::cout << "\n----------------------------------------------------------------\n" << std::endl;
}
