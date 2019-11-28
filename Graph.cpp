#include "Graph.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include "trick.h"
bool Graph::parse_file(std::string file_name){
    std::ifstream val;
    val.open(file_name);

    if(!val.is_open()){
        std::cout<<"fail to open the file:"<<file_name<<std::endl;
        return false;
    }
    std::string line;
    getline(val,line);

    if(line.length()==1){
        int num = atoi(line.c_str());
        CUBE.setNum(num);
        while(getline(val,line)){
            std::vector <int> fun;
            for(int i=0; i<num; i++){
                fun.push_back(transform(line[i]));
            }
            CUBE.addRow(fun);
        }    
    }
}
void Graph::output_file(std::string file_name){
    CUBE = Complement(CUBE);
    std::ofstream outfile(file_name);
    outfile << CUBE.GetEleNUM()<<std::endl;
    std::cout << CUBE.GetEleNUM()<<std::endl;
    int iSize = CUBE.RowSize();
    int jSize = CUBE.GetEleNUM();
    for (int i=0 ; i<iSize ; i++){
        std::string s;
        for (int j=0 ; j<jSize ; j++){
            char c = Inverse_transform(CUBE.Getvalue(i,j));
            s=s+c;
        }
        outfile << s <<std::endl;
        std::cout << s <<std::endl;
    }
}
cubelist Graph::PCofactor(cubelist F, int x){
    cubelist V = F;
    int temp;
    for(int i=0;i<V.RowSize();){
        temp = V.Getvalue(i,x);
        if(temp==0){
            i = V.remove(i);                                           //erase导致的迭代器失效问题；
        }
        else if(temp==1){
            V.setEle(i,x,-1);
            i++;
        }
        else{
            i++;
        }
    }
    return V;
};  //positive cofactor,x means the subscript
cubelist Graph::NCofactor(cubelist F, int x){
    cubelist V = F;
    int temp;
    for(int i=0;i<V.RowSize();){
        temp = V.Getvalue(i,x);
        if(temp==1){
            i = V.remove(i);                                           //erase导致的迭代器失效问题；
        }
        else if(temp==0){
            V.setEle(i,x,-1);
            i++;
        }
        else{
            i++;
        }
    }
    return V;
};  //negative cofactor

cubelist Graph::AND(int x, bool value, cubelist F){
    cubelist V=F;
    if(value){
        for(int i=0; i<V.RowSize(); i++){
            V.setEle(i,x,1);
        }
        return V;
    }
    if(!value){
        for(int i=0; i<V.RowSize(); i++){
            V.setEle(i,x,0);
        }
        return V;
    }
}
cubelist Graph::OR(cubelist P, cubelist N){
    cubelist F=P;
    for(int i=0; i<N.RowSize();i++){
        F.addRow(N.GetRow(i));
    }
    return F;
};
cubelist Graph::Complement(cubelist F){

    int Size = F.GetEleNUM();
    cubelist V(Size);

    if(F.EmptyCube()){
        V =CompEmpty(F);
        return V;
    }
    else if(F.AllDontCare()){
        return V;
    }
    else if(F.OneCube()){
        V = CompOnecube(F);
        return V;
    }
    else{
        int x = F.MostBinate();
        //cubelist test1 = PCofactor(F,x);
        cubelist P = Complement(PCofactor(F,x));
        cubelist N = Complement(NCofactor(F,x));
        P = AND(x,true,P);
        N = AND(x,false,N);
        V = OR(P,N);
        return V;
    }
}
cubelist Graph::CompOnecube(cubelist F){
    int Size = F.GetEleNUM();
    cubelist V(Size);
    std::vector<int> temp;                     //all don't care element
    for(int i=0;i<Size;i++){
        temp.push_back(-1);
    }
    for (int j=0;j<Size;j++){
        if(F.Getvalue(0,j)==1){
            std::vector<int> row=temp;
            row[j]=0;
            V.addRow(row);
        }
        else if(F.Getvalue(0,j)==0){
            std::vector<int> row=temp;
            row[j]=1;
            V.addRow(row);
        }
    }
    return V;
};
cubelist Graph::CompEmpty(cubelist F){
    int Size = F.GetEleNUM();
    cubelist V(Size);
    std::vector<int> temp;
    for(int i=0;i<Size;i++){
        temp.push_back(-1);
    }
    V.addRow(temp);
    return V;
};
