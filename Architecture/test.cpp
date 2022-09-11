#include <iostream>

int main()
{
    int* memory=new int;
    *memory=10;
    std::cout<<*memory<<std::endl;
}