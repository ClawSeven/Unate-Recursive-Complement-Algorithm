#include "cubelist.h"
int cubelist::MostBinate(){
    //1. 判断各个var是否binate
    //2. 选取在cube中出现次数最多的binate var，
    //3. 如果有两个以上最多的binate var，选取最小的|T-C|的binate
    //4. 如果有两个以上最小的|T-C|的binate，选择smallest index
    //5. 如果只有unate，选择在cube中次数最多的var
    //6. 如果只有unate，且有数个在cube中次数最多的var，选择lowest index；

    int countDe[EleNum] = {0};
    int countAbs[EleNum] = {0};
    bool binate[EleNum];
    memset(binate,false,sizeof(binate)*EleNum);

    bool PExist=false;
    bool NExist=false;
    std::vector<int> binate_pos;

    for(int i=0 ; i<EleNum ; i++){
        for(int j=0;j<Matrix.size();j++){
            int temp = Matrix[j][i];
            if (temp == 1){
                countDe[i]++;
                countAbs[i]=countAbs[i]+1;
                PExist = true;
            }
            if (temp == 0){
                countDe[i]++;
                countAbs[i]=countAbs[i]-1;
                NExist = true;
            }
        }
        if(PExist & NExist){
            binate[i]=true;
        }
        PExist = false;
        NExist = false;
    }
    
    for(int i=0;i<EleNum;i++){
        countAbs[i]=abs(countAbs[i]);
    }

    for(int i = 0 ; i<EleNum ; i++){
        if(binate[i]==true)
        binate_pos.push_back(i);
    }
    int binate_num = binate_pos.size();

    std::vector<int> DeMax_pos;
    //std::vector<int> DeAbs;   //abs for deMax
    int De_max = std::max_element(countDe,countDe+EleNum)-countDe;//lowest index

    if(binate_num == 0){                     //全是unate的
        return De_max;
    }
    else if(binate_num == 1 ){               //一个binate
        return binate_pos[0];
    }
    else{                                    //两个及以上binate

        std::vector<int> binate_De;
        std::vector<int> binate_abs;
        for(int i = 0 ; i < binate_num ; i++){
            binate_abs.push_back(countAbs[binate_pos[i]]);
            binate_De.push_back(countDe[binate_pos[i]]);
        }

        std::vector<int> binate_De_max_pos;
        std::vector<int> binate_DeMax_abs;
        int binate_De_max_value = *std::max_element(binate_De.begin(),binate_De.end());
        for(int i=0 ; i<binate_num ; i++){
            if(binate_De[i]==binate_De_max_value){
                binate_De_max_pos.push_back(i);
                binate_DeMax_abs.push_back(binate_abs[i]);
            }
        }
        if(binate_De_max_pos.size()==1){
            return binate_pos[binate_De_max_pos[0]];
        }
        else{
            int DeMax_minabs = std::min_element(binate_DeMax_abs.begin(),binate_DeMax_abs.end())-binate_DeMax_abs.begin();
            int temp1 = binate_De_max_pos[DeMax_minabs];
            int temp2 = binate_pos[temp1];
            return temp2;
        }
    }
};

bool cubelist::AllDontCare(){
    bool temp =false;
    bool temp_row = true;
    int Size = Matrix.size();
    for(int i=0 ; i<Size ; i++){
        for (int j=0 ; j<EleNum ; j++){
            if(Matrix[i][j]!=-1){
                temp_row = false;
            }
        }
        if (temp_row){
            return true;
        }
    }
    return false;   
}
bool cubelist::OneCube(){
    //bool k = AllDontCare();
    if (!AllDontCare()){
        if(Matrix.size()==1){
            return true;
        }
    }
    else{
        return false;
    }
}

int cubelist::remove(int i){
    std::vector<std::vector<int>>::iterator iter;
    iter = Matrix.erase(Matrix.begin()+i);
    int point = iter-Matrix.begin();
    return point;
};