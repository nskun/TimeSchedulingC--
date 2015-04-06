/* 
 * File:   main.cpp
 * Author: nskun
 *
 * Created on 2015/04/06, 17:31
 */

#include <cstdlib>
#include <string>
#include <vector>
#include "Utility.h"

using namespace std;

/**
 * 時間割作成問題に対する近似解を生成する。
 * 
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv) {
    /* ファイルを読み込む */
    int i;
    struct Problem Problems[20];
    for(i = 0; i < 20; i++) {
        getBenchmarkProblem("./tim/competition" + i + ".tim" , &Problems[i]);
    }
    for(i = 0; i < 20; i++) {
        
    }
    /* 解を構築する */
    
    /* 解を改善する */
    
    /* 出力する */
    

    return 0;
}
