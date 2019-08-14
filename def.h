#ifndef DEF_H
#define DEF_H

#include "mbed.h"


//---------------------------------------------------
/// Convert Float to Byte
union ParseFloatToByte_tag {
    float _float;
    char _byte[4];
};
typedef union ParseFloatToByte_tag ParseFloatToByte;

struct Position_tag { //目標座標の構造体
    double x, y, angle;
    uint16_t flg;
};
typedef struct Position_tag POSITION;

//---------------------------------------------------

//配列の長さを取得するテンプレート関数
template<typename TYPE, std::size_t SIZE>
std::size_t array_length(const TYPE (&)[SIZE]) {
    return SIZE;
}

//-1.0~1.0に数値を制限する
double LIM(double n) { //return [-1.0~1.0]
    if(n > 1.0)       return 1.0;
    else if(n < -1.0) return -1.0;
    else              return n;
}

inline double D2R(double n) { //degree to radian convert
    return M_PI / 180.0 * n;
}

#endif