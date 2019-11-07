#include <iostream>
#include <fstream>
#include <stdio.h>
#include<string.h>
#include<conio.h>

using namespace std;
class crim_rec
{
    char name[50], Gender,  addrs[25], offense[20], blood[5] ;
    int crime_code;
   
    public:
    void get();
    void write();
    void read();
    void search();
    void del();
    void mod();
    void disp();
}c;
void crim_rec::get()
{
    cout<<"Enter name of criminal:";
    cin>>name;
    cout<<"Enter the crime id:";
    cin>>crime_code;
    cout<<"Gender(m/f/other):";
    cin>>Gender;
    cout<<"Enter blood group (Ap/An/Bp/Bn/ABp/ABn/Op/On):";
    cin>>blood;
    cout<<"Enter address:";
    cin>>addrs;
    cout<<"Enter crime commited:";
    cin>>offense;
}
void crim_rec::disp()
{
    cout<<"\nThe record of criminal:\n";
    cout<<"Crime Id: "<<crime_code;
    cout<<"\nName of criminal: "<<name;
    cout<<"\nGender: "<<Gender;
    cout<<"\nBlood Group: "<<blood;
    cout<<"\nAddress: "<<addrs;
    cout<<"\nCrime: "<<offense<<endl;
}
void crim_rec::write()      //adding and then writing in the file
{
	fstream fp;
    char ch;
	fp.open("CBI.dat",ios::out|ios::app);
	do
	{
		get();
		fp.write((char*)&c,sizeof(c));
		cout<<"\n\nDo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}

void crim_rec::read()                   //reading and viewing the data
{
   fstream f;
   f.open("CBI.dat",ios::in|ios::binary);
   f.read(reinterpret_cast<char*>(&c),sizeof(c));
   while(!f.eof())
   {
   	disp();
   	f.read(reinterpret_cast<char*>(&c),sizeof(c));
   }
   f.close();
}

void crim_rec::search()
{
    char n[20];
    int flag=0;
    fstream fil;
	cout<<"Enter Name of the criminal to  be searched:";
    cin>>n;
	fil.open("CBI.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&c, sizeof(c));
		while(!fil.eof())
		{
			fil.read((char*)&c, sizeof(c));
			if(strcmpi(name,n)==0)
			{
				disp();
				flag=1;
			}
			}
	}
	fil.close();
	if(flag==0)
	{
		cout<<"Record not found"<<endl;
	}
}
void crim_rec::del()
{
   fstream fp,fp1;
    	char m[20];
	int flag=0;
    	cout<<"\n\n\n\tDELETE criminal...";
    	cout<<"\n\nEnter the criminals name  : ";
    	cin>>m;
    	fp.open("CBI.dat",ios::in|ios::binary);
		fp1.open("new.dat",ios::out|ios::binary); //temporary file
	while(!fp.eof())
	{
		fp.read((char*)&c,sizeof(c));
		if(fp.eof())
		break;
		if(strcmpi(name,m)!=0)  
		fp1.write((char*)&c,sizeof(c));
		else
	   	flag=1;
		}	 	
		fp1.close();
    	fp.close();
    	remove("CBI.dat");
    	rename("new.dat","CBI.dat");
    	if(flag==1)
     		cout<<"\n\n\tRecord Deleted ..";
    	else
     		cout<<"\n\nRecord not found";
}
void crim_rec::mod()
{
	fstream fp;
    char m[10];
	int found=0;
	system("cls");
	cout<<"\n\n\tMODIFY criminals RECORD.... ";
	cout<<"\n\n\tEnter The name of the criminal you want to modify:";
	cin>>m;
	fp.open("CBI.dat",ios::in|ios::out|ios::binary);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&c,sizeof(c)) && found==0)
	{
		if(strcmpi(name,m)==0)
		{
		    disp();
			cout<<"\nEnter The New Details of criminal"<<endl;
			get();
			double pos=-1*sizeof(c);
			
		    	fp.seekp(pos,ios::cur);
		    	fp.write((char*)&c,sizeof(c));
		    	cout<<"\n\n\t Record Updated";
		    	found=1;
		}
	}

    	fp.close();
    	if(found==0)
    		cout<<"\n\n Record Not Found ";
    	
}
void page()
{
	
	cout<<"\n\t\t\t\t\t\tCRIMINAL RECORDS";
	cout<<"\n\n\t\tMADE BY :\n\t\t\t\tPritisha Shrestha\n"; 
	cout<<"\t\t\t\tReeti Pradhananga\n";
	cout<<"\t\t\t\tYukti Bhatt\n";
	cout<<"\n\t\t\t\tKantipur Engineering College";
	getch();
}
int main()
{
    int ch;
    char choice;
    page();
    system("cls");
    do
    {
    system("cls");
    cout<<"\n MAIN MENU";
    cout<<"\n ********************************************";
    cout<<"\n\n *  1. View criminal details                 *";
    cout<<"\n\n *  2. Add new criminal details              *";
    cout<<"\n\n *  3. Search a criminal record              *";
    cout<<"\n\n *  4. Delete a criminal record              *";
    cout<<"\n\n *  5. Modify a criminal record              *";
    cout<<"\n ********************************************";
    cout<<"\n\n Enter your choice: ";
    cin>>ch;


    switch(ch)
    {
    case 1:
        
             c.read();    
        break;
    case 2:
        
            c.write();
            
            break;
    case 3:
            c.search();
            break;
    case 4:
        c.del();
        break;
    case 5:
        c.mod();
        break;
    default:
        {
        cout<<"\nerror!";
        }
        break;
    }
    cout<<"\ncontinue? (y/n)\n";
    cin>>choice;
    }while(choice=='y'||choice=='Y');
    cout<<"\nGood bye";
}

