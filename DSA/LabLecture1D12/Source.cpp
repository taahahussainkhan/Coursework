//#include <iostream>
#include "myArray.h"

int main()
{
    myArray myObj;
    myObj.addValue(50);
    myObj.addValue(51);
    myObj.addValue(52);
    myObj.display();
    cout << myObj.removeValue()<<endl;
    myObj.display();
    myObj.setValue(60);
    cout<<myObj.getValue()<<endl;
    
}
