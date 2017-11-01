#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

bool myfunction(std::vector<float> i, std::vector<float> j){return (i[2] > j[2]);}

int greedy(std::vector<std::vector<float> > A, int W){
    for (int i = 0; i < A.size(); i++){
        A[i].push_back(A[i][1]/A[i][0]);
    }
    std::sort(A.begin(), A.end(), myfunction);
    int value = 0;
    for (int i = 0; i < A.size(); i++){
        if (W > A[i][0]){
            value += A[i][1];
            W -= A[i][0];
        }
    }
    return value;
}

int dp(std::vector<std::vector<int> > A, int wei){
    int k[wei + 1][A.size()] = {};
    for (int w = 0; w <= wei; w++){
        k[w][0] = 0;
    }
    for (int j = 0; j < A.size(); j++){
        k[0][j] = 0;
    }
    for (int j = 1; j < A.size(); j++){
        for (int w = 1; w <= wei; w++){
            if (A[j][0] > w){
                k[w][j] = k[w][j-1];
            }
            else if (k[w][j-1] >= k[(w-A[j][0])][j-1] + A[j][1]){
                k[w][j] = k[w][j-1];
            }
            else {
                k[w][j] = (k[w-A[j][0]][j-1] + A[j][1]);
            }
        }
    }
    return k[wei][A.size() - 1];
}
int main(){
    std::vector<std::vector<float> > A = {{96, 91}, {96, 92}, {96, 92}, {97, 94}, {98, 95}, {100, 94}, {100, 96}, {102, 97}, {103, 97}, {104, 99}, {106, 101}, {107, 101}, {106, 102}, {107, 102}, {109, 104}, {109, 106}, {110, 107}, {111, 108}, {113, 107}, {114, 110}};
    std::vector<std::vector<int> > B = {{96, 91}, {96, 92}, {96, 92}, {97, 94}, {98, 95}, {100, 94}, {100, 96}, {102, 97}, {103, 97}, {104, 99}, {106, 101}, {107, 101}, {106, 102}, {107, 102}, {109, 104}, {109, 106}, {110, 107}, {111, 108}, {113, 107}, {114, 110}};
    std::cout<<greedy(A, 300)<<std::endl;
    std::cout<<dp(B, 300)<<std::endl;
};