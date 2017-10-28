#ifndef GAME_REMAININGNUMBERS_H
#define GAME_REMAININGNUMBERS_H


class RemainingNumbers {
private:
    const int defaultArr[9][2] = { { 0, 0 },{ 0, 1 },{ 0, 2 },{ 1, 0 },{ 1, 1 },{ 1, 2 },{ 2, 0 },{ 2, 1 },{ 2, 2 } };
    int **arr;
    int size;
public:
    RemainingNumbers();
    ~RemainingNumbers();
    void reset();
    int find(int x[]);
    void remove(int x[]);
    int getSize();
    int** getArr();
};


#endif //GAME_REMAININGNUMBERS_H
