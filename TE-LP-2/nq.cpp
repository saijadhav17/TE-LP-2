#include <bits/stdc++.h>
#define rep(i,a,b)  for(int i=a;i<b;i++)

bool issafe(int** board, int x, int y, int n)
{
	rep(i,0,n){
		if(board[i][y]==1)
			return false;
	}
	
	int row=x;
	int col= y;
	while(row>= 0 && col>= 0){
		if(board[row][col]==1)
			return false;
		row--;
		col--;
	}
	
	row= x;
	col= y;
	while(row>= 0 && col< n){
		if(board[row][col]==1)
			return false;
		row--;
		col++;
	}
	return true;
}

bool nqueen(int** arr, int x, int n){
	if(x>=n)
		return true;
		
	for(int col=0; col<n;col++){
		if(issafe(arr,x,col,n)){
			arr[x][col] = 1;
			if(nqueen(arr,x+1,n)){
			
				return true;
			}
			arr[x][col] = 0;
		}
	}
	
	return false;
}

int main(){
	int n;
	std::cin>>n;
	int** board=new int*[n];
	
	rep(i,0,n){
		board[i] = new int[n];
		rep(j,0,n){
			board[i][j]=0;
		}
	}
	
	if(nqueen(board,0,n))
	rep(i,0,n){
		rep(j,0,n){
			std::cout<<board[i][j]<<" ";
		}
std::cout<<"\n";
	}
}
