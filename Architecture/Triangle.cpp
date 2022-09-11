#include "Object.cpp"
#include <string>
class Triangle: public Object

{
    public:
    Triangle(std::string _name)
    {
        this->name=_name;
        std::cout<<"    Triangle constucted: "<<this->name<<std::endl;

    };


};