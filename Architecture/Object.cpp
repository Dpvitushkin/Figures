#pragma once
#include <string>
#include <iostream>

class Object
{
    public:
        int num;
        std::string name;
        unsigned int VAO,VBO,EBO;
        float vertices[12] = {
         0.5f,  0.5f, 0.0f,
         0.5f,  -0.5f, 0.0f,
         -0.5f,  -0.5f, 0.0f,
         -0.5f,  0.5f, 0.0f };
        unsigned int indices[6] = { 0, 1, 3,1,2,3 };
        Object()
        {
            std::cout<<"Object constructed : default constructor"<<std::endl;
            
        }
        Object(std::string _name)
        {
            this->name=_name;
            std::cout<<"Object constructed : "<<this->name<<std::endl;

        }
        ~Object()
        {
            std::cout<<"Object default destructor"<<std::endl;
        }
        void setup();
        void change_color();
        void draw();
        void translate(float x, float y);
        void print_status();
};
void Object::setup()
{
    //Use VAO,VBO,EBO,vertices,indises
    std::cout<<this->name<<"::setup()"<<std::endl;
}
void Object::change_color()
{
    //Gluniform4(vertexColorLocation,color)
    std::cout<<this->name<<"::change_color()"<<std::endl;
}
void Object::draw()
{
    //Draw objects
    std::cout<<this->name<<"::draw()"<<std::endl;
}
void Object::translate(float x,float y)
{
    //add x,y to vertices, call setup();
    std::cout<<this->name<<"::translate()"<<std::endl;

}

void Object::print_status()
{
    std::cout<<this->name<<std::endl;
}


