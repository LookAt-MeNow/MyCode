#include <iostream>
#define MAX 1000
using namespace std;
typedef struct{
	int i;//行
	int j;//列
	int e;//元素
}Elem;

typedef struct{
	Elem data[MAX+1];
	int r,l,num;//行，列，非零元素个数
}Matrix,*pMatrix;

void CreateMatrix(pMatrix p);
void PrintMatrix(pMatrix p);
pMatrix InvertMatrix(pMatrix p);

int main(){
	pMatrix p,p2;
	p = new Matrix;
	p->num = 0;
	CreateMatrix(p);
	cout<<"转置前"<<endl;
	PrintMatrix(p);
	p2 = InvertMatrix(p);
	cout<<"转置后"<<endl;
	PrintMatrix(p);
	return 0;
}

void CreateMatrix(pMatrix p){
	int index = 1;
	int m,n,k;
	int row,col;
	cout<<"请输入矩阵的行还有列"<<endl;
	cin>>row>>col;
	p->r = row;
	p->l = col;
	cout<<"请输入矩阵信息，输入-1，-1，-1退出信息输入"<<endl;
	while(1){
		cin>>m>>n>>k;
		if(m!=-1 && n!=-1 && k!=-1){
			p->data[index].i = m;
			p->data[index].j = n;
			p->data[index].e = k;
			p->num++;
			index++;
		}else{
			break;
		}
	}
}

void PrintMatrix(pMatrix p){
	cout<<"这个矩阵的行为："<<p->r<<endl;
	cout<<"这个矩阵的列为："<<p->l<<endl;
	cout<<"这个矩阵的元素个数"<<p->num<<endl;
	for(int i=1;i<=p->num;i++){
		cout<<p->data[i].i<<"   "<<p->data[i].j<<"   "<<p->data[i].e<<endl;
	}
}

pMatrix InvertMatrix(pMatrix p){
	pMatrix p2;
	p2 = new Matrix;
	p2->r = p->l;
	p2->l = p->r;
	p2->num = p->num;
	int* nums = new int[MAX];
	int* cpot = new int[MAX];
	
	for(int i=1;i<=p->num;i++){
		nums[i] = cpot[i] = 0;
	}
	
	for(int i=1;i<=p->num;i++){
		++nums[p->data[i].j];
	}
	
	cpot[1] = 1;
	
	for(int i=2;i<=p->num;i++){
		cpot[i] = cpot[i-1]+nums[i-1];
	}
	
	for(int i=1;i<=p->num;i++){
		p2->data[cpot[p->data[i].j]].i = p->data[i].i;
		p2->data[cpot[p->data[i].j]].j = p->data[i].j;
		p2->data[cpot[p->data[i].j]].e = p->data[i].e;
		cpot[p->data[i].j]++;
	}
	return p2;
}
















