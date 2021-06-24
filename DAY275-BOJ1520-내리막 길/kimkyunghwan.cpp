#include <stdio.h>
#define startY 1
#define startX 1
long long int dfs(int a,int b, int n,int m);
  
const int dy[4]={0,0,1,-1}; const int dx[4]={1,-1,0,0};
long long int d[501][501];
int height[501][501];

int main() {
  int n,m;
	int i,j;
	
	
    scanf("%d %d",&n,&m);
	
	for(i=1;i<=n;++i) {
		for(j=1;j<=m;++j) {
			scanf("%d",&height[i][j]);
			d[i][j]=-1;
		}
	}
	
	//d[startY][startX]=1;
	d[n][m]=1;
    
	dfs(1,1,n,m);
	
	

	
	printf("%lld",d[1][1]);

	return 0;
}

long long int dfs(int y,int x,int n,int m) {
	int tempY,tempX;
	long long int temp=0;
	int k;
    //if(y==n && x==m) return 1;
    if(d[y][x]>=0) return d[y][x];
			for(k=0;k<4;++k) {
				tempY=y+dy[k]; tempX=x+dx[k];
				//if(d[tempY][tempX]>0) continue;
				if(tempY>0 && tempY<=n && tempX>0 && tempX<=m) {
				
					if(height[y][x]>height[tempY][tempX]) {
						
						//d[tempY][tempX]+=1;
						//d[y][x]+=dfs(tempY,tempX,n,m);
                        temp+=dfs(tempY,tempX,n,m);
				}
			}
			}
    d[y][x]=temp; //이걸로 0 해결
    return d[y][x];
}
