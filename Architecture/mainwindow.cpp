#include "Object.cpp"
#include "Square.cpp"
#include "Triangle.cpp"
#include <iostream>
#include <vector>
#include <string>

class mainwindow
{
    public:
    std::vector<Object*> objects;
    Object* selected;
    mainwindow()
    {
        std::cout<<"mainwindow constructed"<<std::endl;
    }
    void create_object(std::string obj_type);
    void print_all();
    unsigned int number_of_elements();
    void delete_element(int i);



};

void mainwindow::create_object(std::string obj_type)
{

    if(obj_type=="Object") this->objects.push_back(new Object(obj_type));
    if(obj_type=="Square") this->objects.push_back(new Square(obj_type));
    if(obj_type=="Triangle") this->objects.push_back(new Triangle(obj_type));
}

void mainwindow::print_all()
{
    for(int i=0;i<objects.size();i++)
    {
        objects[i]->print_status();
    }
}

unsigned int mainwindow::number_of_elements()
{
    return objects.size();
}

void mainwindow::delete_element(int i)
{
    std::vector<Object*>::iterator it=objects.begin();
    std::cout<<"    before"<<objects.size()<<std::endl;
    objects[i]->draw();
    delete objects[i];
    std::cout<<"    after"<<objects.size()<<std::endl;
    std::cout<<"object deletet"<<std::endl;
}