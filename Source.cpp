#include<iostream>
#include<string>
#include<ctime>
#include<conio.h>
#define numberticket 2
#define size 5
#define sizeD 50
using namespace std;
struct Date
{
	int day, month, year;
};
struct flight
{
	int flightnumber, numberofseats;
	string Dcity, Acity, Dtime, Atime, price;
	Date date_flight;
}opjectF, Flight[size] = { 0 };
struct Passenger
{
	int ID; Date date;
	char name, address;
	string first_name, second_name, phonenumber;
}passenger[sizeD], opjectP;
struct ticket
{
	int ticket_num, flight_num, passenger_ID;
	Date date_res, date;
}opjectT, Ticket[numberticket] = { 0 };
void adminAcc(){
	int i = 0; bool flag;
	string username = "";
	char password, pass[sizeD] = { "12345" };
	bool True = true;
	do{
		cout << "Enter username :\n";
		cin >> username;
		cout << "Enter password :\n";
		do{
			password = _getch(); _putch('*');
			if (password == 13)
				break;
			else{
				pass[i] = password;

				if (pass[i] == password)
					flag = 1;
				else
					flag = 0;
				i++;
			}
		} while (true);
		if (username == "admin" && flag == 1)
		{
			cout << endl << "welcome to admin\n";
			True = false;
		}
		else
			cout << "wrong " << "try again";
	} while (True != false);
}

void clientAcc(){
	string username; char pass[sizeD]; string usernameTry; char passwordTry;
	bool flag = 0, flagP; int i = 0;
	do{

		cout << "Enter username :\n";
		cin >> usernameTry;
		if (username == usernameTry)
		{
			cout << "Enter password :\n";
			do{
				passwordTry = _getch(); _putch('*');
				if (passwordTry == 13)
					break;
				else{

					if (pass[i] == passwordTry)
					{
						flagP = 1;
					}
					else
					{
						flagP = 0;
					}
					i++;
				}
			} while (true);
			cout << endl;
			if (flagP == 0)
				cout << "The password was wrong !!!\nplease try again.... \n";
			else
			{
				cout << "Welcome to our PROGRAM !!\n";
				flag = 1;
			}
		}
		else
		{
			cout << "The user name was wrong !!!\nplease try again.... \n";
		}


	} while (!flag);
}
void signUp(){
	cin.ignore();
	bool flagS = 1, flagN = 1;
	Passenger newClient;
	srand(unsigned(time(0)));
	newClient.ID = 1 + rand() % 99;
	cout << "Type your name : ";
	cin >> newClient.name;
	cin.ignore();
	cout << "Type your address : ";
	cin >> newClient.address;
	cout << "Type yuor Phone Number : ";
	cin >> newClient.phonenumber;
	cout << "Type your Date Of Birth (day/month/year) : ";
	cin >> newClient.date.day >> newClient.date.month >> newClient.date.year;
	cin.ignore();
	bool flag = true;
	int i = 0;
	char password, pass[sizeD];
	do{
		flag = false;
		bool flagS = false, flagN = false;
		cout << "Type your Password .....\n Note :: Must be more than 8 characters including at least one number and one special character...\n";
		do{
			password = _getch(); _putch('*');
			if (password == 13)
				break;
			else{
				pass[i] = password;
				i++;
			}
		} while (true);
		cout << endl;
		for (int z = 0; z < i; z++){
			if (pass[z] >= 48 && pass[z] <= 57)
				flagN = true;
			if ((pass[z] >= 33 && pass[z] <= 47) || (pass[z] >= 58 && pass[z] <= 64))
				flagS = true;
		}

		if ((flagS == true) && (flagN == true) && (i >= 8))
		{
			cout << "Valide Password ...\nCongrats!! ..you created a NEW account.." << endl;
			flag = false;
		}
		else
		{
			cout << "invalide password..\nPlease try again..\n";
			flag = true;
			pass[sizeD] = cin.sync();
		}
	} while (flag == true);

}
void cancel_reservation()
{
	cout << "Enter a pssenger ID to delete";
	int a, k = 0, i = 0;
	cin >> a;

	if (passenger[i].ID == a)
		k = i;
	else i++;



	for (int j = k; j < 2; j++)
	{

		passenger[j].ID = passenger[j + 1].ID;
		passenger[j].date.day = passenger[j + 1].date.day;
		passenger[j].date.month = passenger[j + 1].date.month;
		passenger[j].date.year = passenger[j + 1].date.year;
		passenger[j].address = passenger[j + 1].address;

		passenger[j].name = passenger[j + 1].name;
		passenger[j].first_name = passenger[j + 1].first_name;
		passenger[j].second_name = passenger[j + 1].second_name;
		passenger[j].phonenumber = passenger[j + 1].phonenumber;
	}
	for (int j = k; j < 2; j++)
	{
		cout << passenger[j].ID << endl << passenger[j].date.day << '/' << passenger[j].date.month << '/' << passenger[j].date.year << endl << passenger[j].address << endl << passenger[j].name << endl << passenger[j].first_name << endl << passenger[j].second_name << endl << passenger[j].phonenumber << endl;
	}
}
void add_reservation()
{
	cout << "Please Enter Date Of The Day (Day,Month,Year) : ";
	cin >> opjectT.date_res.day >> opjectT.date_res.month >> opjectT.date_res.year;
	cout << "Please Enter Date Of Journey (Day,Month,Year) : ";
	cin >> opjectF.date_flight.day; cin >> opjectF.date_flight.month; cin >> opjectF.date_flight.year;
	cout << "1.Chicago  2.Paris  3.Riyadh   4.Amesterdam  \n";
	int travel;
	cout << "Please Enter The Number Of City You Want To Travel To It : "; cin >> travel;
	cout << "                      * Flights Found *                   \n";
	cout << "\tDeparture time\t\tArrival time\t\tPrices\n";
	cout << "(1)\t" << "10:00\t\t\t14:05\t\t\t2500 $\n";
	cout << "(2)\t" << "14:00\t\t\t18:05\t\t\t2000 $\n";
	cout << "(3)\t" << "18:00\t\t\t22:05\t\t\t2300 $\n";
	cout << "(4)\t" << "20:30\t\t\t03:00\t\t\t1900 $\n";
	int n_flight;
	cout << "Please Enter Your Choice : "; cin >> n_flight;
	cout << "Enter Your First Name : "; cin >> opjectP.first_name;
	cout << "Enter Your Second Name : "; cin >> opjectP.second_name;
	cout << "Please Enter Your ID : "; cin >> opjectP.ID;
	opjectT.passenger_ID = opjectP.ID;
	cout << "Please Entre Your Phone Number : "; cin >> opjectP.phonenumber;
	switch (n_flight)
	{
	case 1:
		opjectF.flightnumber = 1001; opjectT.flight_num = 1001; opjectF.numberofseats = 25;  opjectF.Dtime = "10:00";
		opjectF.Atime = "14:05";  opjectF.price = " 2500 $"; opjectF.Dcity = "Egypt";
		if (travel == 1) opjectF.Acity = "Chicago"; else if (travel == 2) opjectF.Acity = "paris";
		else if (travel == 3) opjectF.Acity = "Riyadh"; else opjectF.Acity = "Amesterdam";
		cout << "\t\t\t*Flight Details*\t\t\t\n";
		cout << "Date Of Flight is : " << opjectF.date_flight.day << "/" << opjectF.date_flight.month << "/" << opjectF.date_flight.year << "\n";
		cout << "Flight Number is : " << opjectF.flightnumber << "\n" << "Number Of Avilable Seats is : "
			<< opjectF.numberofseats << "\nDeparture Time : " << opjectF.Dtime << "\tArrival Time : " << opjectF.Atime <<
			"\nDeparture City : " << opjectF.Dcity << "\t\t" << "Arrival City : " << opjectF.Acity << "\t";
		cout << "\nPrice Of Flight is : " << opjectF.price << "\n";
		cout << "\t\t\t*Ticket Details*\t\t\t\n";
		cout << "Date of your Reservation is : " << opjectT.date_res.day << "/" << opjectT.date_res.month << "/" << opjectT.date_res.year << "\n";
		opjectT.ticket_num = 875302;
		cout << "Ticket Number is : " << opjectT.ticket_num << "\nFlight Number : " << opjectT.flight_num <<
			"\nYour Name is : " << opjectP.first_name << " " << opjectP.second_name << "\nYour ID is : " << opjectT.passenger_ID << "\n";
		break;
	case 2:
		opjectF.flightnumber = 1002; opjectT.flight_num = 1002; opjectF.numberofseats = 20;  opjectF.Dtime = "14:00";
		opjectF.Atime = "18:05";  opjectF.price = " 2000 $"; opjectF.Dcity = "Egypt";
		if (travel == 1) opjectF.Acity = "Chicago"; else if (travel == 2) opjectF.Acity = "paris";
		else if (travel == 3) opjectF.Acity = "Riyadh"; else opjectF.Acity = "Amesterdam";
		cout << "\t\t\t*Flight Details*\t\t\t\n";
		cout << "Date Of Flight is : " << opjectF.date_flight.day << "/" << opjectF.date_flight.month << "/" << opjectF.date_flight.year << "\n";
		cout << "Flight Number is : " << opjectF.flightnumber << "\n" << "Number Of Avilable Seats is : "
			<< opjectF.numberofseats << "\nDeparture Time : " << opjectF.Dtime << "\tArrival Time : " << opjectF.Atime <<
			"\nDeparture City : " << opjectF.Dcity << "\t\t" << "Arrival City : " << opjectF.Acity << "\t";
		cout << "\nPrice Of Flight is : " << opjectF.price << "\n";
		cout << "\t\t\t*Ticket Details*\t\t\t\n";
		cout << "Date of your Reservation is : " << opjectT.date_res.day << "/" << opjectT.date_res.month << "/" << opjectT.date_res.year << "\n";
		opjectT.ticket_num = 680981;
		cout << "Ticket Number is : " << opjectT.ticket_num << "\nFlight Number : " << opjectT.flight_num <<
			"\nYour Name is : " << opjectP.first_name << " " << opjectP.second_name << "\nYour ID is : " << opjectT.passenger_ID << "\n";
		break;
	case 3:
		opjectF.flightnumber = 1003; opjectT.flight_num = 1003; opjectF.numberofseats = 11;  opjectF.Dtime = "18:00";
		opjectF.Atime = "22:05";  opjectF.price = " 2300 $"; opjectF.Dcity = "Egypt";
		if (travel == 1) opjectF.Acity = "london"; else if (travel == 2) opjectF.Acity = "paris";
		else if (travel == 3) opjectF.Acity = "egypt"; else opjectF.Acity = "dubai";
		cout << "\t\t\t*Flight Details*\t\t\t\n";
		cout << "Date Of Flight is : " << opjectF.date_flight.day << "/" << opjectF.date_flight.month << "/" << opjectF.date_flight.year << "\n";
		cout << "Flight Number is : " << opjectF.flightnumber << "\n" << "Number Of Avilable Seats is : "
			<< opjectF.numberofseats << "\nDeparture Time : " << opjectF.Dtime << "\tArrival Time : " << opjectF.Atime <<
			"\nDeparture City : " << opjectF.Dcity << "\t\t" << "Arrival City : " << opjectF.Acity << "\t";
		cout << "\nPrice Of Flight is : " << opjectF.price << "\n";
		cout << "\t\t\t*Ticket Details*\t\t\t\n";
		cout << "Date of your Reservation is : " << opjectT.date_res.day << "/" << opjectT.date_res.month << "/" << opjectT.date_res.year << "\n";
		opjectT.ticket_num = 807623;
		cout << "Ticket Number is : " << opjectT.ticket_num << "\nFlight Number : " << opjectT.flight_num <<
			"\nYour Name is : " << opjectP.first_name << " " << opjectP.second_name << "\nYour ID is : " << opjectT.passenger_ID << "\n";
		break;
	case 4:
		opjectF.flightnumber = 1004; opjectT.flight_num = 1004; opjectF.numberofseats = 6;  opjectF.Dtime = "20:30";
		opjectF.Atime = "03:00";  opjectF.price = " 1900 $"; opjectF.Dcity = "Egypt";
		if (travel == 1) opjectF.Acity = "Chicago"; else if (travel == 2) opjectF.Acity = "paris";
		else if (travel == 3) opjectF.Acity = "Riyadh"; else opjectF.Acity = "Amesterdam";
		cout << "\t\t\t*Flight Details*\t\t\t\n";
		cout << "Date Of Flight is : " << opjectF.date_flight.day << "/" << opjectF.date_flight.month << "/" << opjectF.date_flight.year << "\n";
		cout << "Flight Number is : " << opjectF.flightnumber << "\n" << "Number Of Avilable Seats is : "
			<< opjectF.numberofseats << "\nDeparture Time : " << opjectF.Dtime << "\tArrival Time : " << opjectF.Atime <<
			"\nDeparture City : " << opjectF.Dcity << "\t\t" << "Arrival City : " << opjectF.Acity << "\t";
		cout << "\nPrice Of Flight is : " << opjectF.price << "\n";
		cout << "\t\t\t*Ticket Details*\t\t\t\n";
		cout << "Date of your Reservation is : " << opjectT.date_res.day << "/" << opjectT.date_res.month << "/" << opjectT.date_res.year << "\n";
		opjectT.ticket_num = 896043;
		cout << "Ticket Number is : " << opjectT.ticket_num << "\nFlight Number : " << opjectT.flight_num <<
			"\nYour Name is : " << opjectP.first_name << " " << opjectP.second_name << "\nYour ID is : " << opjectT.passenger_ID << "\n";
		break;
	default:
		cout << "Please Entre a Right Number";

	}
}
void modify_reservation()

{
	cout << "enter ticket number";
	int x;
	cin >> x;
	for (int i = 0; i < numberticket; i++)
	{
		if (Ticket[i].ticket_num == x)
		{
			cout << "if you want modfiy ticket_number or passenger_id or flight_number"
				<< "enter 'y'";
			char ch;
			cin >> ch;
			if (ch == 'y')
			{
				cout << "ticket_number:1\npassenger_id:2\nflight_number : 3\n";
				int z;
				cin >> z;
				cout << "enter the new value ";
				int y;
				cin >> y;
				switch (z){
				case 1:Ticket[i].ticket_num = y;
					cout << Ticket[i].ticket_num << endl << Ticket[i].passenger_ID << endl << Ticket[i].flight_num << endl << Ticket[i].date.day << "|" << Ticket[i].date.month << "|" << Ticket[i].date.year;
					break;
				case 2:Ticket[i].passenger_ID = y;
					cout << Ticket[i].ticket_num << endl << Ticket[i].passenger_ID << endl << Ticket[i].flight_num << endl << Ticket[i].date.day << "|" << Ticket[i].date.month << "|" << Ticket[i].date.year;
					break;
				case 3:Ticket[i].flight_num = y;
					cout << Ticket[i].ticket_num << endl << Ticket[i].passenger_ID << endl << Ticket[i].flight_num << endl << Ticket[i].date.day << "|" << Ticket[i].date.month << "|" << Ticket[i].date.year;
					break;
				default:cout << "choose right";
				}
			}
			else {
				cout << "if you want to modfiy date press:1";
				int num;
				cin >> num;
				cout << "enter new day,month,year";
				int Day, Month, Year;
				cin >> Day >> Month >> Year;
				switch (num)
				{
				case 1:Ticket[i].date.day = Day;
					Ticket[i].date.month = Month;
					Ticket[i].date.year = Year;
					cout << Ticket[i].ticket_num << endl << Ticket[i].passenger_ID << endl << Ticket[i].flight_num << endl << Ticket[i].date.day << "|" << Ticket[i].date.month << "|" << Ticket[i].date.year;
					break;
				default:cout << "choose right";
				}
			}

		}
	}

}
void show_reservation()
{
	cout << "Please Enter your ID \n";
	int h;
	cin >> h;
	for (int i = 0; i < numberticket; i++)
	{
		if (h == Ticket[i].passenger_ID)
		{
			cout << Ticket[i].ticket_num << endl << Ticket[i].flight_num << endl << Ticket[i].date.day << '/' << Ticket[i].date.month << '/' << Ticket[i].date.year << endl;
		}
		else
		{
			cout << "Wrong ID ,Try again";
			cin >> h;
			break;
		}
	}
}
void search_plane()
{
	cout << "Enter the required flight number \n";
	int a;
	cin >> a;
	for (int i = 0; i < size; i++)
	{
		if (Flight[i].flightnumber == a)
		{
			cout << "The flight number is: " << Flight[i].flightnumber << "\t The flight available seats are: " << Flight[i].numberofseats << "\t The Departure info.(City,Time): " << Flight[i].Dcity << "\t" << Flight[i].Dtime << "\t The Arrival info.(City,Time): " << Flight[i].Acity << "\t" << Flight[i].Atime << endl;
		}
		else
		{
			cout << "Flight not ,found try again";
		}
	}
}
void add_flight()
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter the flight information \n";
		cout << "1.Enter the flight number \n";
		cin >> Flight[i].flightnumber;
		cout << "2.Enter the number of seats \n";
		cin >> Flight[i].numberofseats;
		cout << "3.Enter Departure info.(City,Time)\n";
		cin >> Flight[i].Dcity >> Flight[i].Dtime;
		cout << "4.Enter Arrival info.(City,Time)\n";
		cin >> Flight[i].Acity >> Flight[i].Atime;
	}
}
void delete_flight()
{
	cout << "Enter a flight number to delete";
	int a, k = 0, i = 0;
	cin >> a;

	if (Flight[i].flightnumber == a)
		k = i;
	else i++;



	for (int j = k; j < 2; j++)
	{

		Flight[j].flightnumber = Flight[j + 1].flightnumber;
		Flight[j].numberofseats = Flight[j + 1].numberofseats;
		Flight[j].Dcity = Flight[j + 1].Dcity;
		Flight[j].Dtime = Flight[j + 1].Dtime;
		Flight[j].Acity = Flight[j + 1].Acity;
		Flight[j].Atime = Flight[j + 1].Atime;
	}
	for (int j = k; j < 3; j++)
	{
		cout << Flight[j].flightnumber << endl << Flight[j].numberofseats << endl << Flight[j].Dcity << Flight[j].Dtime << "\n" << Flight[j].Acity << Flight[j].Atime;
	}
}
void update_flight()
{
	cout << "Enter the flight number to update\n";
	int a;
	cin >> a;
	for (int i = 0; i < size; i++)
	{
		if (Flight[i].flightnumber == a)
		{
			cout << "If you want to update the number of seats,Arrival time or Departure time press Y \n";
			char y;
			cin >> y;
			if (y == 'y' || y == 'Y')
			{
				cout << "If you want to update:\n the number pf seats press:1\n the Departure time press:2\n the Arrival time presss:3\n";
				int k;
				cin >> k;
				cout << "Enter the new value ";
				int j;
				cin >> j;
				switch (k)
				{
				case 1:
					Flight[i].numberofseats = j;
					cout << "The flight number is: " << Flight[i].flightnumber << "\n" << "the number of seats are: " << Flight[i].numberofseats << "\n" << "Departure info.(City,Time): " << Flight[i].Dcity << ',' << Flight[i].Dtime << "\n" << "Arrival info.(City,Time): " << Flight[i].Acity << ',' << Flight[i].Atime << endl;
					break;
				case 2:
					Flight[i].Dtime = j;
					cout << "The flight number is: " << Flight[i].flightnumber << "\n" << "the number of seats are: " << Flight[i].numberofseats << "\n" << "Departure info.(City,Time): " << Flight[i].Dcity << ',' << Flight[i].Dtime << "\n" << "Arrival info.(City,Time): " << Flight[i].Acity << ',' << Flight[i].Atime << endl;
					break;
				case 3:
					Flight[i].Atime = j;
					cout << "The flight number is: " << Flight[i].flightnumber << "\n" << "the number of seats are: " << Flight[i].numberofseats << "\n" << "Departure info.(City,Time): " << Flight[i].Dcity << ',' << Flight[i].Dtime << "\n" << "Arrival info.(City,Time): " << Flight[i].Acity << ',' << Flight[i].Atime << endl;
					break;
				default:
					cout << "Choose a right number" << endl;
				}
			}
			else
			{
				cout << "If you want to update :\n Arrival city press:1\n Departure city press:2\n";
				int s;
				cin >> s;
				cout << "Enter the new city\n";
				string m;
				cin >> m;
				switch (s)
				{
				case 1:
					Flight[i].Acity = m;
					cout << "The flight number is: " << Flight[i].flightnumber << "\n" << "the number of seats are: " << Flight[i].numberofseats << "\n" << "Departure info.(City,Time): " << Flight[i].Dcity << ',' << Flight[i].Dtime << "\n" << "Arrival info.(City,Time): " << Flight[i].Acity << ',' << Flight[i].Atime << endl;
					break;
				case 2:
					Flight[i].Dcity = m;
					cout << "The flight number is: " << Flight[i].flightnumber << "\n" << "the number of seats are: " << Flight[i].numberofseats << "\n" << "Departure info.(City,Time): " << Flight[i].Dcity << ',' << Flight[i].Dtime << "\n" << "Arrival info.(City,Time): " << Flight[i].Acity << ',' << Flight[i].Atime << endl;
					break;
				default:
					cout << "Choose a right number" << endl;
				}
			}
		}
		else
		{
			cout << "Wrong Flight number ,try again";
			cin >> a;
			continue;
		}
	}
}
int main()
{
	for (int i = 0; i <3; i++)
	{

		cout << "f.n";
		cin >> Flight[i].flightnumber;
		cout << "f.s";
		cin >> Flight[i].numberofseats;
		cout << "f.Dtime";
		cin >> Flight[i].Dtime;
		cout << "f.Dcity";
		cin >> Flight[i].Dcity;
		cout << "f.Atime";
		cin >> Flight[i].Atime;
		cout << "f.Acity";
		cin >> Flight[i].Acity;
	}
	for (int j = 0; j < 3; j++)
	{
		cout << "ID";
		cin >> Ticket[j].passenger_ID;
		cout << "number of ticket";
		cin >> Ticket[j].ticket_num;
		cout << "flight number";
		cin >> Ticket[j].flight_num;
		cout << "date";
		cin >> Ticket[j].date.day >> Ticket[j].date.month >> Ticket[j].date.year;


	}
	for (int q = 0; q < 3; q++)
	{
		cout << "ID";
		cin >> passenger[q].ID;
		cout << "Date";
		cin >> passenger[q].date.day >> passenger[q].date.month >> passenger[q].date.year;
		cout << "name";
		cin >> passenger[q].name;
		cout << "adress";
		cin >> passenger[q].address;
		cout << "first name";
		cin >> passenger[q].first_name;
		cout << "second name";
		cin >> passenger[q].second_name;
		cout << "phone number";
		cin >> passenger[q].phonenumber;
	}

	cout << "if you admn: 1" << endl << "if you new passenger: 2";

	bool flag = true;
	while (flag)
	{
		int r;
		cin >> r;
		if (r == 1)
		{
			cout << "add :1\ndelete :2\nsearch :3\nupdate" << "write your choose:";
			int c;
			cin >> c;
			switch (c)
			{
			case 1:
				add_flight();
				break;
			case 2:
				delete_flight();
				break;
			case 3:
				update_flight();
				break;

			default:
				cout << "choose right number ";
			}
		}
		else
		{
			cout << "log in\sign up :1\n search :2\n add :3\n cancel:4\nmodfiy:5\nshow reservation :6\n" << "write your choose";
			int a;
			cin >> a;
			switch (a)
			{
			case 1:
				signUp();
				break;
			case 2:
				search_plane();
				break;
			case 3:

				add_reservation();
				break;
			case 4:
				cancel_reservation();
			case 5:
				modify_reservation();
				break;
			case 6:
				show_reservation();

				break;
			default:
				cout << "choose right number ";

			}
			cout << "if you continue to use program press 'y'\n";
			char f;
			cin >> f;
			if (f != 'y')
				flag = false;
		}
	}
	return 0;
}