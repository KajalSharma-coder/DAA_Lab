#include <iostream>
#include <vector>
using namespace std;

int isSafe(vector<vector<int>>& mat, int row, int col){
  int n=mat.size();
  
  for(int i=0;i<row;i++){
    if(mat[i][col]==1){
      return 0;
    }
  }
  for(int i=row-1,j=col-1; i>=0 && j>=0;i--,j--){
    if(mat[i][j]==1){
      return 0;
    }
  }
  for(int i=row-1,j=col+1; i>=0 && j<n;i--,j++){
    if(mat[i][j]==1){
      return 0;
    }
  }
  return 1;
}

void placeQueens(int row, vector<vector<int>>& mat, vector<vector<int>>& res){
  
  int n=mat.size();
  if(row==n){
    vector<int> temp;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        temp.push_back(mat[i][j]);
      }
    }
    res.push_back(temp);
    return;
  }

  for(int col=0;col<n;col++){
    if(isSafe(mat,row,col)){
      mat[row][col]=1;
      placeQueens(row+1,mat,res);
      mat[row][col]=0;
    }
  }
}

vector<vector<int>> nQueen(int n){
  vector<vector<int>> mat(n,vector<int>(n,0));
  vector<vector<int>> res;
  placeQueens(0,mat,res);
  return res;
}
int main() {

    int n;

    cout << "Enter n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input";
        return 0;
    }

    vector<vector<int>> result = nQueen(n);

    if (result.empty()) {
        cout << "No solution exists";
        return 0;
    }

    cout << "\nTotal solutions = " << result.size() << endl;

    for (int k = 0; k < result.size(); k++) {

        cout << "\nSolution " << k + 1 << ":" << endl;

        int index = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                cout << result[k][index] << " ";
                index++;
            }

            cout << endl;
        }
    }

    return 0;
}