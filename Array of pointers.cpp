#include <iostream>  
using namespace std;  
int main()  
{  
    int *ptr;  // integer pointer declaration  
    int marks[10]; // marks array declaration  
    std::cout << "Enter the elements of an array :" << std::endl;  
    for(int i=0;i<10;i++)  
    {  
        cin>>marks[i];  
    }  
    ptr=marks; // both marks and ptr pointing to the same element..  
    std::cout << "The value of *ptr is :" <<*ptr<< std::endl;  
    std::cout << "The value of *marks is :" <<*marks<<std::endl;  
}  
