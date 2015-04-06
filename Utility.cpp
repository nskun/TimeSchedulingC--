/* 
 * File:   Utility.cpp
 * Author: shain
 * 
 * Created on 2015/04/06, 21:39
 */

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include "Utility.h"
#include "StructProblem.h"

using namespace std;

/**
 * 
 * @param filename
 * @return 
 */
Problem getBenchmarkProblem(string &filename){

    std::ifstream ifs(filename.c_str());
    if (ifs.fail()) {
        /* エラーの場合は異常終了する */
        std::cerr << "file open error!!\n" << std::endl;
        exit(-1);
    }
    while (getline(ifs, str))
    {
        std::cout << "[" << str << "]" << std::endl;
    }
    return 0;

	int i, j, count = 0;


	// ファイルポインタの宣言
	FILE *fp;
	if ((fp = fopen(filename, "r")) == NULL) {
	}

        Problem Problem;
        
	fscanf(fp, "%d %d %d %d", Problem.TotalLesson, Problem.TotalRooms, Problem.TotalFeature, Problem.TotalStudent);
        
	// 部屋のサイズを読む
	for(i = 0; i < Problem.TotalRooms; i++){
		fscanf(fp, "%d", &Problem.Rooms[i].RoomSize);
	}

	// どの授業に生徒が出席するか 
        int temp;
	for(i = 0; i < Problem.TotalStudent; i++){ /* event_studentの0-1マトリクスを読む */
		for(j = 0; j < Problem.TotalLesson; j++){
			fscanf(fp, "%d", &temp);
                        Problem.Students[i].Attend.push_back(temp);
		}
	}

	// どの部屋にどの特徴があるか // RoomType
	for(i = 0; i < Problem.TotalRooms; i++){ /* feature_roomの0-1マトリクスを読む */
		for(j = 0; j < Problem.TotalFeature; j++){
			fscanf(fp, "%d", &temp);
                        Problem.Rooms[i].Installation.push_back(temp);
		}
	}
	// どの授業にどの特徴がいるか // eventType
	for(i = 0; i < Problem.TotalLesson; i++){ /* feature_eventの0-1マトリクスを読む */
		for(j = 0; j < Problem.TotalFeature; j++){
			fscanf(fp, "%d", &temp);
                        Problem.Lessons[i].Installation.push_back(temp);
		}
	}
	fclose(fp); /* ファイルのクローズ */

        return Problem;
        
	for(i = 0; i < *event; i++){ /* 各科目に何人の生徒が出席しているかを計測 */
		for(j = 0; j < *student; j++){
			if(Se[j][i] == 1){
				count += 1;
			}
		}
		if(*attendance < count){
			*attendance = count;
		}
		Es[i] = count;
		count = 0;
	}
	for(i = 0; i < *room; i++){ /* 特徴の多い教室を計測 */
		for(j = 0; j < *feature; j++){
			if(Rf[i][j] == 1){
				count += 1;
			}
		}
		Fr[i] = count;
		count = 0;
	}
	for(i = 0; i < *event; i++){ /* 特徴の多い科目を計測 */
		for(j = 0; j < *feature; j++){
			if(Ef[i][j] == 1){
				count += 1;
			}
		}
		Fe[i] = count;
		count = 0;
	}

#if 0

	printf("read関数内チェック:\n");
	printf( "科目数 : %d\n部屋数 : %d\n特徴の数 : %d\n生徒数 : %d\n\n", *event, *room, *feature, *student);
	printf("roomsize:\n");
	for(i = 0; i < *room; i++){
		printf("%d\n", roomsize[i]);
	}puts("");
	printf("event_student:\n");
	for(i = 0; i < *student; i++){ /* event_studentの0-1マトリクスを出力 */
		for(j = 0; j < *event; j++){
			printf("%d", Se[i][j]);
		}puts("");
	}puts("");
	printf("feature_room\n");
	for(i = 0; i < *room; i++){ /* feature_roomの0-1マトリクスを出力 */
		for(j = 0; j < *feature; j++){
			printf("%d", Rf[i][j]);
		}puts("");
	}puts("");
	printf("feature_event\n");
	for(i = 0; i < *event; i++){ /* feature_eventの0-1マトリクスを出力 */
		for(j = 0; j < *feature; j++){
			printf("%d", Ef[i][j]);
		}puts("");
	}puts("");
	for(i = 0; i < *event; i++){ /* 各科目に何人の生徒が出席しているかを出力 */
		printf("Es[%d] : %d\n", i, Es[i]);
	}puts("");

	for(i = 0; i < *room; i++){ /* 各部屋にいくつの特徴があるかを出力 */
		printf("Fr[%d] : %d\n", i, Fr[i]);
	}puts("");

	for(i = 0; i < *event; i++){ /* 各科目にいくつの特徴があるかを出力 */
		printf("Fe[%d] : %d\n", i, Fe[i]);
	}puts("");
#endif


}
