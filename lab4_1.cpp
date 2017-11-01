#include <iostream>
#include <cstdlib>
#include <array>
#include <vector>
#include <stdlib.h>

int main(){
    std::vector<int> A;
    for (int z = 0; z < 500; z++){
        int num = rand()%100 + 1;
        A.push_back(num);
    }
    //std::vector<int> A={7, 2, 4, 6, 9, 11, 2, 6, 10, 6, 15, 6, 14, 2, 7, 5, 13, 9, 12, 15};
    std::vector<int> S[A.size()][A.size()] = {};
    for (int j = 0; j < A.size(); j++) {
        for (int i = j; i >= 0; i--) {
            std::vector<int> a;
            S[i][j] = a;
            if (i == j){
                S[i][j].push_back(A[i]);
            }
            else if (i == j - 1){
                S[i][j].push_back(A[i]);
            }
            else if (j >= i+2){
                if (A[i] == A[j]){
                    std::vector<int> c = S[i+1][j-1];
                    c.push_back(A[i]);
                    std::vector<int> b;
                    b.push_back(A[i]);
                    for (int o = 0; o < c.size(); o++){
                        b.push_back(c[o]);
                    }
                    S[i][j] = b;
                }
                else {
                    if (S[i+1][j].size() >= S[i][j-1].size()){
                        S[i][j] = S[i+1][j];
                    }
                    else {
                        S[i][j] = S[i][j-1];
                    }
                }
            }
        }
    }
    int s = A.size();
    for (int l = 0; l < S[0][s - 1].size(); l++){
        std::cout << S[0][s - 1][l] << " ";
    }
};