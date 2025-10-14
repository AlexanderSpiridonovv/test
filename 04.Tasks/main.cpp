#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <memory>
//task 1
bool IsClosingPerentecie(const char& c)
{
    return c == '}' || c == ']' || c == ')';
}
bool AreMatching(const char& opening, const char& closing)
{
    return opening == '{' && closing == '}' 
        || opening == '[' && closing == ']'
        || opening == '(' && closing == ')';
}

bool ValidPerentecies(const std::string& str){
    if(str.length() == 0)
    {
        return true;
    }
    if(IsClosingPerentecie(str[0]))
    {
        return false;
    }
    std::stack<char> s;
    s.push(str[0]);
    int i = 1;
    while(!s.empty())
    {
        
        while(!IsClosingPerentecie(str[i]))
        {
            if(s.top() < str[i])
            {
                return false;
            }
            s.push(str[i]);
            i++;
        }
        while(IsClosingPerentecie(str[i])){
            if(s.empty() || !AreMatching(s.top(),str[i])){
                return false;
            }
            s.pop();
            i++;
        }
    }
    return true;
}
//task 2
//ne vidqh smisul da pravq header i cpp za tolkova maluk obekt
class Person {
private:
    std::string m_name;
    unsigned m_age;

public:
    Person(const std::string& name, unsigned age) : m_name(name), m_age(age) 
    {
        std::cout << "Person created: " << m_name << '\n';
    }
    
    ~Person() 
    {
        std::cout << "Person destroyed: " << m_name << '\n';
    }
    
    void Print() const 
    {
        std::cout << "Name: " << m_name << ", Age: " << m_age << '\n';
    }
    
    std::string GetName() const 
    { 
        return m_name;
    }
    int GetAge() const 
    { 
        return m_age;
    }
};
//task 3
template <typename T>
T getMax(const T* arr, const size_t size)
{
    T max_element = arr[0];
    for(size_t i = 1; i < size; i++)
    {
        if(arr[i] > max_element)
        {
            max_element = arr[i];
        }
    }
    return max_element;
}

int main(int argc, const char** argv) 
{
    std::cout<<ValidPerentecies("{[]()()}")<<std::endl;

    auto p1 = std::make_shared<Person>("Ivan", 69);
    std::cout << "Count: " << p1.use_count() << '\n';  // 1
    
    auto p2 = p1;  
    std::cout << "Count: " << p1.use_count() << '\n';  // 2
    
    auto p3 = p2; 
    std::cout << "Count: " << p1.use_count() << '\n';  // 3
    
    p2.reset(); 
    std::cout << "Count: " << p1.use_count() << '\n';  // 2
    
    p3.reset();
    std::cout << "Count: " << p1.use_count() << '\n';
    return 0;
}
