#include<bits/stdc++.h>
using namespace std;

bool isSafe(int** arr, int x, int y, int n){
    for(int row=0; row<n; row++){
        if(arr[row][y] == 1){
            return false;
        }
    }

    int row = x;
    int col = y;
    while(row>=0 && col>=0){
        if(arr[row][col] == 1){
            return false;
        }
        col--;
        row--;
    }

    row = x;
    col = y;
    while(row>=0 && col<n){
        if(arr[row][col] == 1){
            return false;
        }
        col++;
        row--;
    }

    return true;
}

bool placeQueen(int** arr, int x, int n){
    if(x>=n){
        return true;
    }

    for(int col=0; col<n; col++){
        if(isSafe(arr, x, col, n)){
            arr[x][col] = 1;

            if(placeQueen(arr, x+1, n)){
                return true;
            }

            arr[x][col] = 0; // Bactracking
        }
        
    }

    return false;
}

int main(){
    int n;
    cin >>n;

    int** arr = new int*[n];

    for(int i=0; i<n; i++){
        arr[i] = new int[n];
        for(int j=0; j<n; j++)
            arr[i][j] = 0;       
    }

    if(placeQueen(arr, 0, n)){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;      
        }

    }

    //corner case
    else{
        cout << "Beware of using n = 2, 3 & greater than 27" << endl;
    }
    return 0;
}
