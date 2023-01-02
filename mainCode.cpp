#include<iostream>
using namespace std;
	char matrix[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	int row;
	int col;
	char token='x';
	bool tie=false;
	string n1="";
	string n2="";
void mainfxn1()
{	cout<<"    |     |    "<<endl;
	cout<<matrix[0][0]<<"   |   "<<matrix[0][1]<<" |  "<<matrix[0][2]<<endl;
	cout<<"____|_____|_____"<<endl;
	cout<<"    |     |     "<<endl;
	cout<<"    |     |    "<<endl;
	cout<<matrix[1][0]<<"   |   "<<matrix[1][1]<<" |  "<<matrix[1][2]<<endl;
	cout<<"____|_____|_____"<<endl;
	cout<<"    |     |     "<<endl;
	cout<<"    |     |    "<<endl;
	cout<<matrix[2][0]<<"   |   "<<matrix[2][1]<<" |  "<<matrix[2][2]<<endl;
	cout<<"____|_____|_____"<<endl;
	cout<<"    |     |     "<<endl;
	cout<<"    |     |     "<<endl;
	
	
}
void mainfxn2()
{
	int digit;
	if(token=='x')
	{
		cout<<n1<<" write your digit";
		cin>>digit;
	}
	if(token=='0')
	{
		cout<<n2<<" write your digit";
		cin>>digit;
	}
	if(digit==1)
	{
		row=0;
		col=0;
	}
	if(digit==2)
	{
		row=0;
		col=1;
	}
	if(digit==3)
	{
		row=0;
		col=2;
	}
	if(digit==4)
	{
		row=1;
		col=0;
	}
	if(digit==5)
	{
		row=1;
		col=1;
	}
	if(digit==6)
	{
		row=1;
		col=2;
	}
	if(digit==7)
	{
		row=2;
		col=0;
	}
	if(digit==8)
	{
		row=2;
		col=1;
	}
	if(digit==9)
	{
		row=2;
		col=2;
	}
	
	else if(digit<1 || digit>9){
		cout<<"not Valid"<<endl;}
	if(token=='x' && matrix[row][col]!='x'&& matrix[row][col]!='0')
	{
		matrix[row][col]='x';
		token='0';
	}
	else if(token=='0' && matrix[row][col]!='x'&& matrix[row][col]!='0')
	{
		matrix[row][col]='0';
		token='x';
	}
	
	else{
		cout<<"Space are full";
		mainfxn2();
	}
	 mainfxn1();
}

bool mainfxn3()
{
	for(int i=0;i<3;i++)
	{
		if(matrix[i][0]==matrix[i][1] && matrix[i][0]==matrix[i][2] || matrix[0][i]==matrix[1][i]&& matrix[0][i]==matrix[2][i])
		return true;
    }
		if(matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2] || matrix[0][2]==matrix[1][1]&& matrix[1][1]==matrix[2][0])
		return true;
		
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(matrix[i][j]!='x' && matrix[i][j]!='0')
			{
				return false;
			}
		}
	}
	tie=true;
	return false;
	
}
	

int main()
{
		
	cout<<"Enter name of first person\n";
	getline(cin,n1);
	cout<<"Enter name of second person\n";
	getline(cin,n2);
     while(!mainfxn3())
     {
     	mainfxn1();
     	mainfxn2();
     	mainfxn3();
	 }
	 if(token=='x'&& tie==false)
	 {
	 	cout<<n2<<"Wins!!"<<endl;
	 }
	 else if(token=='0' && tie==false)
	 {
	 	cout<<n1<<"wins!!"<<endl;
	 }
	 else{
	 	cout<<"its a draw"<<endl;
	 }
}
