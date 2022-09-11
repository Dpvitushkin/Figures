#include "mainwindow.cpp"


int main()
{

    mainwindow window;
    window.create_object("Object");
    window.delete_element(0);
    int* memory=new int;
    *memory=10;
    std::cout<<*memory;



    
}