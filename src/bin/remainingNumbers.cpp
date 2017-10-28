#include "remainingNumbers.h"


RemainingNumbers::RemainingNumbers()
{
    reset();
}

RemainingNumbers::~RemainingNumbers() {
    arr = nullptr;
    delete arr;
}


void RemainingNumbers::reset() {
    arr = nullptr;
    size = 9;
    arr = new int*[size];
    for (int i = 0; i < size; i++) {
        arr[i] = new int[2];
    }

    for (int i = 0; i < size; i++) {
        for (int p = 0; p < 2; p++) {
            arr[i][p] = defaultArr[i][p];
        }
    }
}

int RemainingNumbers::find(int x[]) {
    for (int i = 0; i < size; i++) {
        if (arr[i][0] == x[0] && arr[i][1] == x[1]) {
            return i;
        }
    }
    return -1;
}

void RemainingNumbers::remove(int x[]) {
    int index = find(x);

    if (index == -1) {
        return;
    }

    int **tempArr = new int*[size - 1];

    bool iteratedPastIndex = false;

    for (int i = 0; i < size - 1; i++) {
        tempArr[i] = new int[2];
    }

    for (int i = 0; i < size; i++) {
        for (int p = 0; p < 2; p++) {
            if (i == index) {
                iteratedPastIndex = true;
            }
            else if (i != index && !iteratedPastIndex) {
                tempArr[i][p] = arr[i][p];
            }
            else if (iteratedPastIndex) {
                tempArr[i - 1][p] = arr[i][p];
            }
        }
    }

    // size -= 1
    size--;
    // reset array
    arr = nullptr;
    // create number of elements size
    arr = new int*[size];

    // set each element to be an array of size 2
    for (int i = 0; i < size; i++) {
        arr[i] = new int[2];
    }

    for (int i = 0; i < size; i++) {
        for (int p = 0; p < 2; p++) {
            arr[i][p] = tempArr[i][p];
        }
    }


    for (int i = 0; i < size; i++) {
        delete[] tempArr[i];
    }

    tempArr = nullptr;

    delete[] tempArr;
}

int RemainingNumbers::getSize() {
    return size;
}


int** RemainingNumbers::getArr() {
    return arr;
}
