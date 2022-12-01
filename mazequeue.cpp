//
//  mazequeue.cpp
//  HW2
//
//  Created by Angela Kan on 2/1/21.
//

#include <queue>
#include <string>
#include <iostream>
using namespace std;

class Coord
{
  public:
    Coord(int rr, int cc) : m_row(rr), m_col(cc) {}
    int r() const { return m_row; }
    int c() const { return m_col; }
  private:
    int m_row;
    int m_col;
};

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec);
   // Return true if there is a path from (sr,sc) to (er,ec)
   // through the maze; return false otherwise

//int main()
//{
//    string maze[10] = {
//        "XXXXXXXXXX",
//        "X........X",
//        "XX.X.XXXXX",
//        "X..X.X...X",
//        "X..X...X.X",
//        "XXXX.XXX.X",
//        "X.X....XXX",
//        "X..XX.XX.X",
//        "X...X....X",
//        "XXXXXXXXXX"
//    };
//
//    if (pathExists(maze, 10,10, 6,4, 1,1))
//        cout << "Solvable!" << endl;
//    else
//        cout << "Out of luck!" << endl;
//}

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec){
    queue<Coord> coordQueue;
    Coord start(sr, sc);
    Coord end(er, ec);

    coordQueue.push(start);
    maze[sr][sc] = '!';

    while (!coordQueue.empty()){
        Coord cur = coordQueue.front();
        //cerr<<"("<<cur.r()<<","<<cur.c()<<")" << endl;
        coordQueue.pop();
        if (cur.r() == end.r() && cur.c() == end.c()){
            return true;
        } else {
            if (maze[cur.r() - 1][cur.c()] != 'X' && maze[cur.r() - 1][cur.c()] != '!'){
                coordQueue.push(Coord(cur.r()-1, cur.c()));
                maze[cur.r() - 1][cur.c()] = '!';
            }
            if (maze[cur.r()][cur.c() + 1] != 'X' && maze[cur.r()][cur.c() + 1] != '!'){
                coordQueue.push(Coord(cur.r(), cur.c()+1));
                maze[cur.r()][cur.c()+1] = '!';
            }
            if (maze[cur.r() + 1][cur.c()] != 'X' && maze[cur.r() + 1][cur.c()] != '!'){
                coordQueue.push(Coord(cur.r()+1, cur.c()));
                maze[cur.r() + 1][cur.c()] = '!';
            }
            if (maze[cur.r()][cur.c() - 1] != 'X' && maze[cur.r()][cur.c() - 1] != '!'){
                coordQueue.push(Coord(cur.r(), cur.c()-1));
                maze[cur.r()][cur.c()-1] = '!';
            }
        }
    }
    return false;
}
