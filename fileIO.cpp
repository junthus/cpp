//
//  main.cpp
//  #01FileIO
//
//  Created by juhee.bak on 2015. 7. 6..
//  Copyright (c) 2015년 juhee.bak. All rights reserved.
//

#include <iostream> 
#include <fstream>

using namespace std; //std::cout << "Hello, World!\n";

int main()
{

    //file object
    ofstream fileObject;
    
    fileObject.open("test.txt");
    
    fileObject << "test a filestream\n";
    
    fileObject.close();
    
    
    
    
    
    return 0;
}
