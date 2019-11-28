#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"
#include "cubelist.h"
int main(int argc,const char *argv[]){
    std::string infile = argv[1];
    std::string outfile = "mytest.out";
    if (argc == 3){
        outfile = argv[2];
    }
    Graph graph;
    graph.parse_file(infile);
    graph.output_file(outfile);
    return 0;
}