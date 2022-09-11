#include "Object.cpp"
#include <string>
class Square : public Object

{
    public:
    Square(std::string _name)
    {
        this->name=_name;
        std::cout<<"    Square constucted: "<<this->name<<std::endl;

    };


};