#pragma once

int transform(char a){
    if(a=='1'){
        return 1;
    }
    else if(a=='0'){
        return 0;
    }
    else if(a=='-'){
        return -1;
    }
    else{
        return 2;                   //不存在此种情况，防止报错
    }
};

char Inverse_transform(int a){
    char value;
    if(a==1){
        value = '1';
    }
    else if(a==0){
        value = '0';
    }
    else if(a==-1){
        value = '-';
    }
    return value;
};