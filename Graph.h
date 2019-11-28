#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "cubelist.h"
class Graph{
    private:
    cubelist CUBE;
    public:
    Graph(){};
    ~Graph(){};

    bool parse_file(std::string file_name);
    void output_file(std::string file_name);
    cubelist PCofactor(cubelist F, int x);  //positive cofactor,x means the subscript
    cubelist NCofactor(cubelist F, int x);  //negative cofactor
    cubelist Complement(cubelist F);
    cubelist CompOnecube(cubelist F);
    cubelist CompEmpty(cubelist F);
    cubelist AND(int x, bool value, cubelist F);
    cubelist OR(cubelist P, cubelist N);
};