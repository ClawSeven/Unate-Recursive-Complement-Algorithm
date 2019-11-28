#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>

class cubelist{
    private:
    int EleNum;
    std::vector<std::vector<int> > Matrix;

    public:
    cubelist(){};
    cubelist(int k){EleNum = k;};
    ~cubelist(){};

    void addRow(std::vector<int> a){Matrix.push_back(a);};
    int MostBinate(); //返回元素的下标
    int remove(int i);   //返回下一个指向位置的下标
    void setEle(int i,int j,int value){Matrix[i][j]=value;};
    int RowSize(){return Matrix.size();};
    int Getvalue(int i,int j){return Matrix[i][j];}; 
    std::vector<int> GetRow(int i){return Matrix[i];};
    bool EmptyCube(){return Matrix.empty();};
    bool AllDontCare();
    bool OneCube();
    int GetEleNUM(){return EleNum;};
    void setNum(int k){EleNum = k;};
};