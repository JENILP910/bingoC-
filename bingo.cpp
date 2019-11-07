#include<iostream>
#include<fstream>
#include<string.h>
#include <ctime>
#include <iomanip>
#include<unistd.h>
#include<cstdlib>
#include<windows.h>
char userName[50];
using namespace std;
class color{
	public:
		void red(string x){
			HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( k,FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout <<x;
		}
		void green(string x){
			HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( k,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout <<x;
		}
		void blue(string x){
			HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( k,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << x;
		}
		void yellow(string x){
			HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( k,FOREGROUND_RED|FOREGROUND_GREEN| FOREGROUND_INTENSITY);
			cout <<x;
		}
		void pink(string x){
			HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( k,FOREGROUND_RED|FOREGROUND_BLUE| FOREGROUND_INTENSITY);
			cout <<x;
		}
		void lightBlue(string x){
			HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( k,FOREGROUND_GREEN|FOREGROUND_BLUE| FOREGROUND_INTENSITY);
			cout << x;
		}
		void white(string x){
			HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( k,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE| FOREGROUND_INTENSITY);
			cout << x;
		}
		void grey(string x){
			HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( k,FOREGROUND_RED & FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << x;
		}
};

void rightString(char*n){
	std::cout.width(100); std::cout << std::internal << n << '\n';
}
void centerString(char*n){
	std::cout.width(50); std::cout << std::internal << n << '\n';
}
void loginUser();
void signUser();
void homeMenu();
void leaderboard();
void howToPlay();
void savedGame();
void newGame();
void randomGrid();
class user{
	private:
	public:
		char name[50];
		char username[50];
		char password[50];
		double won;
		double lost;
		double total;
		void login(){
			cout << "\n \n";
			HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( k, FOREGROUND_RED & FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			std::cout.width(52); std::cout << std::internal <<"Login Menu:"<< '\n';
			std::cout.width(52); std::cout << std::internal <<"-------------"<< '\n';
			std::cout.width(60); std::cout << std::internal << "Please enter your username: ";
			cin >> username;
			std::cout.width(60); std::cout << std::internal << "Please enter your password: ";
			cin >> password;
		}
		void signUp(){
			cout << "\n \n";
			HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( k, FOREGROUND_RED & FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			std::cout.width(52); std::cout << std::internal <<"Sign Up Menu:"<< '\n';
			std::cout.width(52); std::cout << std::internal <<"-------------"<< '\n';
			std::cout.width(60); std::cout << std::internal << "Please enter your full name: ";
			cin >> name;
			std::cout.width(60); std::cout << std::internal  << "Please enter valid username: ";
			cin >> username;
			std::cout.width(60); std::cout << std::internal << "Please enter password: ";
			cin >> password;
			won=0;
			lost=0;
			total=won+lost;
		}
};
class matrix{
	public:
		char username[50];
		int id;
		int grid[5][5];
		
		/*int checkNo(int n){
			int count=0;
 			for (int i=0;i<25;i++){
 				if(i==n){
 					cout << "\t \t \t \t \t "<<"O" << "\t";
				 }
				 else{ 	
 					cout <<  "\t \t \t \t \t "<< i << "\t";
				 }
				 if(count==5){
				 	count =0;
				 	cout << "\n";
				 } 
				count ++;
			 }
		}*/
		void getElement(){
			cout << "Please enter no.'s for 5*5 Game grid:- " << endl;
			strcpy(username,userName);
			srand(time(0));
			id=rand();
			/*cout << "\t \t \t \t \t \t  Already used number's are:- " << endl;
			cout << "\t \t \t \t \t \t ----------------------------" << endl;*/
			int i,j;
			for(i=0;i<5;i++){
				for(j=0;j<5;j++){
					cout << "\t";
					cin >> grid[i][j];
				}
			}
		}
		
		void displayElement(){
			//system("cls");
			HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( k,FOREGROUND_RED & FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << "\n Your Matrix Grid:-";
			cout << "\n -----------------" << endl;
			color c;
			c.yellow("Game id: "); cout<< id <<endl;
			cout << "\n";
			HANDLE ii=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( ii,FOREGROUND_RED & FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			int i,j;
			for(i=0;i<5;i++){
				for(j=0;j<5;j++){
					cout << grid[i][j];
					cout << "\t";
				}
				cout << "\n";
			}
			
		}
		void randomNo(){
			system("cls");
			HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( k,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			std::cout.width(60); std::cout << std::internal <<"The bingo Game"<< '\n';
			std::cout.width(63); std::cout << std::internal <<"playing is always fun."<< '\n';
				// current date/time based on current system
   				time_t now = time(0);
			   // convert now to string form
			   char* dt = ctime(&now);
			   rightString(dt);
			   	if(strcmp(userName,"")!=0){
			   			std::cout.width(110); std::cout << std::internal <<"Welcome: ";
			   			rightString(userName);
				   }
			SetConsoleTextAttribute ( k,FOREGROUND_RED & FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			int randomNo;
			randomNo=1+rand()%25;
			cout << "Random No. is: " << randomNo <<endl;
			sleep(1);
				int x,y;
				for(x=0;x<5;x++){
					for(y=0;y<5;y++){
						if(grid[x][y]==randomNo){
							grid[x][y]=0;
						}
					}
				}
				game();
				displayElement();
				askAgain();
		}
		void askAgain(){
				char opt;
		cout << "Please enter 'Y' to generate random no. and 'S' to save the game. ";
		cin >> opt;
		if(opt=='Y' || opt=='y'){
			randomNo();
		}
		else{
			saveGame();
		}
		}
		void saveGame(){
			int recordNo=0;
			ifstream infile("matrix.txt");
			ofstream outfile("tempp.txt");
			matrix check;
			while(!infile.eof()){
				if(infile.read(reinterpret_cast<char*>(&check),sizeof(check))>0){
					if(check.id==this->id){
						outfile.seekp(recordNo*sizeof(check));
						outfile.write(reinterpret_cast<char*>(this),sizeof(*this));
						cout << "Game Succesfully saved.";
						homeMenu();
					}
					else{
						recordNo++;
					}
				}
				else{
					outfile.write(reinterpret_cast<char*>(this),sizeof(*this));
					cout << "Game Succesfully saved.";
					outfile.close();
					homeMenu();		
				}
					
			}
			
		}
		int row(){
			int point=0;
			int noOfzero=0;
			int i,j;
			for(i=0;i<5;i++){
	
					if(grid[i][0]==0 && grid[i][1]==0 &&grid[i][2]==0 &&grid[i][3]==0 &&grid[i][4]==0){
						
						noOfzero +=1;
					}

			}
			HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( k,FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "\n \tNO. of zero row: " << noOfzero <<endl;
			return noOfzero;
		}	
		int column(){
			int point=0;
			int noOfzero=0;
			int j;
			for(j=0;j<5;j++){
	
					if(grid[0][j]==0 && grid[1][j]==0 &&grid[2][j]==0 &&grid[3][j]==0 &&grid[4][j]==0){
						noOfzero +=1;
	
				}

			}
			HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( k,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "\tNO. of zero column: " << noOfzero <<endl;
			return noOfzero;
		}
		int diagonal(){
			int noOfzero1=0;
			int noOfzero2=0;
			if(grid[0][0]==0 && grid[1][1]==0 &&grid[2][2]==0 &&grid[3][3]==0 &&grid[4][4]==0){
			 noOfzero1 +=1;
			}
			if(grid[0][4]==0 && grid[1][3]==0 &&grid[2][2]==0 &&grid[3][1]==0 &&grid[4][0]==0){
			 noOfzero2 +=1;
			}
			HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( k,FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "\tNO. of diagonal match: " << (noOfzero1+noOfzero2) <<endl;
			return (noOfzero1+noOfzero2);
		}	
		void game(){
			int tPoint;
			tPoint=row()+column()+diagonal();
			if(tPoint >= 5){
				HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute ( k,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "\n \t\tB";sleep(1);
				HANDLE l=GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute ( l,FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "I";sleep(1);
				HANDLE m=GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute ( m,FOREGROUND_GREEN & FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "N";sleep(1);
				HANDLE n=GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute ( n,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "G";sleep(1);
				HANDLE o=GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute ( 0,FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "0";sleep(1);
				sleep(2);
				HANDLE p=GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute ( p,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << "\t -->Congratulations,You Win.!!!";
				sleep(3);
				user player;
				user pla;
				ifstream infile1("user.txt",ios::app);
				ofstream outfile1("temp.txt");
					while(!infile1.eof()){
						if(infile1.read(reinterpret_cast<char *>(&player),sizeof(player))>0){
							if(strcmp(player.name,userName)==0){
								strcpy(pla.name,player.name);
								strcpy(pla.username,player.username);
								strcpy(pla.password,player.password);
								pla.won=player.won+1;
								pla.lost=player.lost;
								pla.total=player.total+1;
								outfile1.write(reinterpret_cast<char *>(&pla),sizeof(pla));
							}
							else{
								outfile1.write(reinterpret_cast<char *>(&player),sizeof(player));
							}
						}
					}
					user pp;
					outfile1.close();
					ofstream outfile2("user.txt");
					ifstream infille("temp.txt");
					while(!infille.eof()){
						if(infille.read(reinterpret_cast<char *>(&pp),sizeof(pp))>0){
								outfile2.write(reinterpret_cast<char *>(&pp),sizeof(pp));
						}
					}
					remove("temp.txt");
				homeMenu();
		}
	}
};
class menu{
	public:
		void banner(){
			cout << "\n \n";
			HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			std::cout.width(60); std::cout << std::internal <<" The bingo Game"<< '\n';
			std::cout.width(63); std::cout << std::internal <<"playing is always fun";
			color c;
			c.lightBlue(" :)");
			cout << '\n';
			c.green("");
				// current date/time based on current system
   				time_t now = time(0);
			   // convert now to string form
			   char* dt = ctime(&now);
			   rightString(dt);
			   	if(strcmp(userName,"")!=0){
			   			std::cout.width(100); std::cout << std::internal <<"Welcome: "<< '\n';
			   			rightString(userName);
				   }
			   
		}
		void list(){
			system("cls");
			banner();
			cout << "\n \n";
			HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( k, FOREGROUND_RED & FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout <<"\t \t \t \t \t 1.Login" <<endl;
			cout <<"\t \t \t \t \t 2.Sign Up"<<endl;
			cout << "\t \t \t \t \t 3.Exit"<<endl;
			cout << "\n \t \t \t \t \t   What you you want to do? ";
			int choice;
			cin >> choice;
				switch(choice){
					case 1:
						loginUser();
						break;
					case 2:
						signUser();
						break;
					case 3:
						cout << "Bye bye";
						break;
					default:
						cout << "Please enter valid choice";
				}
		}
		
};
void loginUser(){
	system("cls");
	menu m;
	m.banner();
	user login,check;
	ifstream userLog("user.txt");
	login.login();
	while(!userLog.eof()){
	if(userLog.read(reinterpret_cast<char*>(&check),sizeof(check))>0){
	  if (strcmp(check.username,login.username)==0 && strcmp(check.password,login.password)==0){
			color c;
			cout << "\n\t \t \t \t Welcome: ";c.lightBlue(check.name);cout<< "\n \n"; 
			cout << "\t \t \t \t \t ";
				c.white("Logining in ");
						sleep(1);
						c.green(".");
						sleep(1);
						c.green(".");
						sleep(1);
						c.green(".");
						sleep(1);
						c.green(".");
						c.green(".");
						sleep(1);
						c.green(".");
						sleep(1);
						c.green(".");
			strcpy(userName,check.name);
				homeMenu();
			break;	 
		}
	}
		else{
			HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( k, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "\n \t \t \t \t Wrong Username and password." << endl;
			cout << "\t \t \t \t Please re-enter your username and password.";
			sleep(3);
			loginUser();
		}	
}
}
void signUser(){
	system("cls");
	menu m;
	m.banner();
	user newUser;
	newUser.signUp();
	ofstream newUserr("user.txt",ios::app);
		newUserr.write(reinterpret_cast<char*>(&newUser),sizeof(newUser));
	HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute ( k, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n \n";
	cout << "\t Press any key to return to main menu.";
	char ch;
	cin >> ch;
		if(ch !='\0'){
			m.list();
		}
	}
void homeMenu(){
	menu m;
	system("cls");
	m.banner();
	HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( k, FOREGROUND_RED & FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "\n \n";
			cout << "\t \t \t \t Game Menu-"<<endl;
			cout <<"\t \t \t \t \t 1.New Game" <<endl;
			cout <<"\t \t \t \t \t 2.Saved Game"<<endl;
			cout << "\t \t \t \t \t 3.Random Grid"<<endl;
			cout << "\t \t \t \t \t 4.Leaderboard"<<endl;
			cout << "\t \t \t \t \t 5.How to play?"<<endl;
			cout << "\t \t \t \t \t 6.Logout"<<endl;
			color c;
			cout << "\t \t \t \t \t ";
			c.green("What do you want to do? ");
			int choice;
			cin >> choice;
				switch(choice){
					case 1:
						newGame();
						break;
					case 2:
						savedGame();
						break;
					case 5:
						howToPlay();
						break;
					case 4:
						leaderboard();
						break;
					case 3:
						randomGrid();
						break;
					case 6:
						color c;
			cout << "\n\t \t \t \t Good Bye: ";c.lightBlue(userName);cout<< "\n \n"; 
			cout << "\t \t \t \t \t ";
				c.white("Logining out ");
						sleep(1);
						c.green(".");
						sleep(1);
						c.green(".");
						sleep(1);
						c.green(".");
						sleep(1);
						c.green(".");
						strcpy(userName,"");
						menu m;
						m.list();
						break;
			}
			
}
void randomGrid(){
	system("cls");
	menu m;
	m.banner();
	HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute ( k, FOREGROUND_RED & FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	user use;
	ifstream randomGrid("randomGrid.txt");
	cout < "\n \n \n";
	while(!randomGrid.eof()){
		int c=0;
		matrix ranGrid;
			if(randomGrid.read(reinterpret_cast<char*>(&ranGrid),sizeof(ranGrid))>0){
				if(c>=5){	
					break;
				}
				ranGrid.displayElement();
			}
		}
		SetConsoleTextAttribute ( k, FOREGROUND_RED | FOREGROUND_INTENSITY);
		int ch;
		cout << "\n \t Which game to continue:<Please enter game Id> ";
		cout << "\n \t\t Press '0' to return back to main menu. ";
		cin >>ch;
		if (ch==0){
			sleep(1);
			homeMenu();
		}
		else{
		//load the selected game
		int gameId;
		ifstream infile("randomGrid.txt");
		matrix rGrid;
		while(!infile.eof()){
			if(infile.read(reinterpret_cast<char*>(&rGrid),sizeof(rGrid))>0){
				//if(strcmp(rGrid.username,'all')==0){	
					gameId=rGrid.id;
					if(ch == gameId){
						//ifstream infile("matrix.txt");
						rGrid.randomNo();
						
				}
				//}
			}
		}		
}
		
}
void leaderboard(){
	system("cls");
	menu m;
	m.banner();
	HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute ( k, FOREGROUND_RED & FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	user use;
	ifstream leader("user.txt");
	cout < "\n \n \n";
	cout << "\tLeaderboard:-"<< endl;
	cout << "\t-----------"<< endl;
	std::cout.width(11); std::cout << std::internal <<"Name";
	std::cout.width(18); std::cout << std::internal <<"Username";
	std::cout.width(10); std::cout << std::internal <<"Won";
	std::cout.width(10); std::cout << std::internal <<"Loss";
	std::cout.width(10); std::cout << std::internal <<"Total" ;
	std::cout.width(16); std::cout << std::internal <<"Performance" <<endl;
	std::cout.width(11); std::cout << std::internal <<"-----";
	std::cout.width(18); std::cout << std::internal <<"--------";
	std::cout.width(10); std::cout << std::internal <<"---";
	std::cout.width(10); std::cout << std::internal <<"----";
	std::cout.width(10); std::cout << std::internal <<"-----" ;
	std::cout.width(16); std::cout << std::internal <<"----------" <<endl;
	double performance;
	while(!leader.eof()){
	if(leader.read(reinterpret_cast<char*>(&use),sizeof(use))>0){
		if(strcmp(use.name,userName)==0){
			HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( k,FOREGROUND_RED|FOREGROUND_GREEN| FOREGROUND_INTENSITY);
					
		}
		else{
			HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute ( k,FOREGROUND_RED & FOREGROUND_GREEN| FOREGROUND_INTENSITY);
			if(use.won==0){
				HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute ( k,FOREGROUND_RED| FOREGROUND_INTENSITY);
			}
		}
	    std::cout.width(12); std::cout << std::internal << use.name;
		std::cout.width(18); std::cout << std::internal << use.username;
		std::cout.width(8); std::cout << std::internal << use.won;
		std::cout.width(8); std::cout << std::internal << use.lost;
		std::cout.width(10); std::cout << std::internal << use.total;
		if(use.total==0){
			performance=0;
		}
		else{	
			performance=(use.won/use.total)*100;
		}
		std::cout.width(16);cout << performance <<"%" <<endl;
	}
}
	int ch;
	//HANDLE m=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute ( k, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n \t Please press 0 to return back to home.";
	cin >> ch;
	if (ch==0){
		homeMenu();
	}
	else{
		system("cls");
		leaderboard();
	}
}
void howToPlay(){
	system("cls");
	menu m;
	m.banner();
	HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute ( k, FOREGROUND_RED & FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\n \n \n";
	cout << "\t Instruction:-" <<endl;
	cout << "\t ----------- "<< endl;
	std::cout.width(10); std::cout << std::internal << "\n \t \t 1.Understand the goal of Bingo. Bingo cards are different in the United States versus in the UK and Australia.If you are playing American Bingo: Your goal is to cover five squares in a vertical, horizontal, or diagonal row. Cards in the US are 5 rows by 5 rows with a letter from the word BINGO written above each vertical row. The numbers on each square are generated at random. There are 75 balls with either a B, I, N, G, or O on them as well as a number. These letter-number combinations should occasionally coordinate with a square on your card." << endl;
	std::cout.width(10); std::cout << std::internal << "\n \t\t 2.Designate a caller if you are playing at home. If you are playing in a hall, a caller will have already been chosen. The caller is the person who selects balls that have numbers and letters written on them. He or she calls the number-letter combination out to the players."<< endl;
	int ch;
	//HANDLE m=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute ( k, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n \t Please press 0 to return back to home.";
	cin >> ch;
	if (ch==0){
		homeMenu();
	}
	else{
		system("cls");
		howToPlay();
	}
}
void savedGame(){
		system("cls");
		menu m;
		m.banner();
		cout << "\n \n \n";
		HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute ( k, FOREGROUND_RED & FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Your Saved Games:-"<<endl;
		ifstream infile("matrix.txt");
		while(!infile.eof()){
		matrix rGrid;
			if(infile.read(reinterpret_cast<char*>(&rGrid),sizeof(rGrid))>0){
				if(strcmp(userName,rGrid.username)==0){	
					rGrid.displayElement();
				}
			}
		}
		//ask user which saved game to continue
		SetConsoleTextAttribute ( k, FOREGROUND_RED | FOREGROUND_INTENSITY);
		int ch;
		cout << "\n \t Which game to continue:<Please enter game Id> ";
		cout << "\n \t\t Press '0' to return back to main menu. ";
		cin >>ch;
		if (ch==0){
			sleep(1);
			homeMenu();
		}
		else{
		//load the selected game
		int gameId;
		ifstream infile("matrix.txt");
		matrix rGrid;
		while(!infile.eof()){
			if(infile.read(reinterpret_cast<char*>(&rGrid),sizeof(rGrid))>0){
				if(strcmp(userName,rGrid.username)==0){	
					gameId=rGrid.id;
					if(ch == gameId){
						//ifstream infile("matrix.txt");
						
						rGrid.randomNo();
						
				}
				}
				else{
					continue;
				}
			}
		}		
}
}
void newGame(){
	system("cls");
	menu m;
	m.banner();
	matrix newGrid;
	newGrid.getElement();
	system("cls");
	m.banner();
	HANDLE k=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute ( k, FOREGROUND_RED & FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	newGrid.randomNo();
}
int main(){
	menu m;
	m.banner();
	m.list();
}

