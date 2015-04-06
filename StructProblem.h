/* 
 * File:   StructProblem.h
 * Author: nskun
 *
 * Created on 2015/04/06, 21:58
 */
#include <cstdlib>
#include <vector>

using namespace std;

#ifndef STRUCTPROBLEM_H
#define	STRUCTPROBLEM_H

    /* 教室 */
    typedef struct {
        /* 教室の収容人数 */
        int RoomSize;
        /* 教室の設備（複数） */
        vector<int> Installation;
    } Room;
    /* 授業 */
    typedef struct {
        /* 授業に必要な設備（複数） */
        vector<int> Installation;
    } Lesson;
    /* 生徒 */
    typedef struct {
        /* どの授業に出席するか */
        vector<int> Attend;
    } Student;
    extern typedef struct Problem {
        /* 授業の総数 */
        int TotalLesson;
        /* 教室の総数 */
        int TotalRooms;
        /* 必要設備の総数 */
        int TotalFeature;
        /* 生徒の総数 */
        int TotalStudent;
        struct Room    Rooms[TotalRooms];
        struct Lesson  Lessons[TotalLesson];
        struct Student Students[TotalStudent];
    } ;

#endif	/* STRUCTPROBLEM_H */

