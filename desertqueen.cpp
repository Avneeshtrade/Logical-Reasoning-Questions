#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Point {
    int x, y;
    Point(int x_, int y_) : x(x_), y(y_) {}
};

int rowDir[] = {0, 0, 1, -1};
int colDir[] = {1, -1, 0, 0};

bool isValidPosition(int x, int y, int rows, int cols, vector<vector<bool> >& visited) {
    return x >= 0 && x < rows && y >= 0 && y < cols && !visited[x][y];
}
void findPaths(int x, int y, int endX, int endY, int rows, int cols, char**& matrix, vector<Point>& path, vector<vector<bool> >& visited, vector<vector<Point> >& allPaths, int maxX, int maxY) {
    
    if (x == endX && y == endY && x <= maxX && y <= maxY) {
        allPaths.push_back(path);
        return;
    }
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int newX = x + rowDir[i];
        int newY = y + colDir[i];
        if (isValidPosition(newX, newY, rows, cols, visited)) {
            path.push_back(Point(newX, newY));
            findPaths(newX, newY, endX, endY, rows, cols, matrix, path, visited, allPaths, maxX, maxY);
            path.pop_back();
        }
    }
    visited[x][y] = false;
}
int main()
{
    int N;
    cout<<"Enter the size of the matrix"<<endl;
    cin >> N;
    char **desertPathMatrix = new char *[N];

    vector<vector<bool> > visited(N, vector<bool>(N, false));
    vector<vector<Point> > allPaths;
    vector<Point> path;
    cout<<"Enter the matrix"<<endl;
    for (int i = 0; i < N; ++i)
    {
        desertPathMatrix[i] = new char[N];
        for (int j = 0; j < N; ++j)
        {
            cin >> desertPathMatrix[i][j];
        }
    }
    
    int startX, startY, endX, endY;
    for(int i=0;i<N;i++){
        for(int j=0;j< N;j++){
            if(desertPathMatrix[i][j] == 'S'){
                startX = i;
                startY = j;
            }
            if(desertPathMatrix[i][j] == 'E'){
                endX = i;
                endY = j;
            }
        }
    }
    int maxX = startX > endX? startX : endX;
    int maxY = startY > endY? startY : endY;
    path.push_back(Point(startX, startY));
    findPaths(startX, startY, endX, endY, N, N, desertPathMatrix, path, visited, allPaths, maxX, maxY);
    int cost = 1;
    cout<< endl;
    char prevChar = 'S';
    int smallest = INT_MAX;
    for(size_t i=0;i<allPaths.size();i++){
        prevChar = desertPathMatrix[allPaths[i][0].x][allPaths[i][0].y];
        int sum = 0;
        for(size_t j=1;j<allPaths[i].size();j++){
            int x = allPaths[i][j].x;
            int y = allPaths[i][j].y;
            if(prevChar == 'M'){
                sum = smallest;
                break;
            }
            if(!(prevChar == desertPathMatrix[x][y] && prevChar == 'T')){
                sum += cost;
            }
            prevChar = desertPathMatrix[x][y];
        }
        if(smallest > sum){
            smallest = sum;
        }
    }
    cout<<"Minimum Cost incurred in following path "<<smallest;

    //Deallocating the memory of matrix
    for (int i = 0; i < N; ++i) {
        delete[] desertPathMatrix[i]; // Free each row
    }
    delete[] desertPathMatrix;
}