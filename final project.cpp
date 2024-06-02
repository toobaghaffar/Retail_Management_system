
#include<ctime>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Item
{
	private:
		
		int quantity;
		string item_name,description;
		double price;
		
	public:
		
		Item ()
		{
			
		}
		
		void setitem_name(string name)
		{
			item_name=name;	
		}
		
		void setquantity(int q)
		{
			quantity=q;
		}
		
		void setdescription(string d)
		{
			description=d;
		}
		
		void setprice(double p)
		{
			price=p;
		}
		
		
		string getitem_name()
		{
			return	item_name;	
		}
		
		int getquantity()
		{
			return quantity;
		}
		
		string getdescription()
		{
			return	description;
		}
		
		double getprice()
		{
			return	price;
		}	
				
};

class user
{
	private:
		
		string password,username;
		
	public:
		
		user()
		{
			
		}
		
		void setusername(string name)
		{
			username=name;
		}
		
		void setpassword(string pass)
		{
			password=pass;
		}
		
		string getusername()
		{
			return username;
		}
		
		string getpassword()
		{
			return password;
		}
};

class Inventory
{
	public:
		
		Item item;
		
		//function for adding item
		void AddItem()
		{
			
			char choice;
			int quantity;
			string item_name,description;
			double price;
			
			ofstream write("Inventory.txt",ios::app);
		
			//to check if the file is open
			if(write.is_open())
			{
				do
				{
					//to enter the details of the item
					cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
					cout<<"\t\t\t\t\t                   Item Name(without sapce): ";
					cin.ignore();
					getline(cin,item_name);
					item.setitem_name(item_name);
					
					cout<<"\t\t\t\t\t                   Quantity: ";
					cin>>quantity;
					item.setquantity(quantity);
					
					cout<<"\t\t\t\t\t                   Description (without space): ";
					cin.ignore();
					getline(cin,description);
					item.setdescription(description);
					
					cout<<"\t\t\t\t\t                   Price: ";
					cin>>price;
					item.setprice(price);
					cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				
					//to write the details in the file
					write<<item.getitem_name()<<" "<<item.getquantity()<<" "<<item.getprice()<<" "<<item.getdescription()<<endl;
					
					//confirmation messsage
					cout<<"\t\t\t\t\t             Item added successfully."<<endl;	
					cout<<endl;
					
					//prompt to ask user if he want to add any ither item
					cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
					cout<<"\t\t\t\t\t        Do you want to add any other item?(y/n)"<<endl;
					cout<<"\t\t\t\t\t                   Your Choice: ";
					cin>>choice;
					cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
					
				}
				
				while(choice=='y'|| choice=='Y');
				
				//to close the file
				write.close();
			}
				
			else
			{
				//if file does not open
				cout<<"\t\t\t\t\t               Error opening file."<<endl;
			}
		}
		
		void EditItem()
		{
			bool found=false;
			char choose;
			string name,itemName;
			string descrip;
			int quan;
			int quantity;
			double pri;
			double price;
			string description;
			
			do
			{
				found=false;
				
				
				//for user to enter item name he wants to edit
				cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				cout<<"\t\t\t\t\t         Enter Item name you want to edit."<<endl;
				cout<<"\t\t\t\t\t               Item name: ";
				cin.ignore();
				getline(cin,name);
				item.setitem_name(name);
				cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				
				ifstream read ("Inventory.txt");
				ofstream temp("temp.txt");
				
				//to check if the files are open
				if(read.is_open()&& temp.is_open() )
				{
					
					while(read>>itemName>>quan>>pri>>descrip)
					{
						
					
						//to check if the item is present in the inventory or not
						if(itemName==item.getitem_name())
						{	
							found=true;
							int choice;
							cout<<endl;
							
							//to display the options to edit
							cout<<"\n\t\t\t\t\t           What do you want to edit?"<<endl;
							cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
							cout<<"\t\t\t\t\t                  1. Item name."<<endl;
							cout<<"\t\t\t\t\t                  2. Quantity."<<endl;
							cout<<"\t\t\t\t\t                  3. Description."<<endl;
							cout<<"\t\t\t\t\t                  4. Price."<<endl;
							cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
							cout<<endl;
							
							//prompt for user to enter his choice
							cout<<"\t\t\t\t\t                  Choice: ";
							cin>>choice;
							cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
							
							//to handle user choices
							switch(choice)
							{
								case 1:
								{
									cout<<"\t\t\t\t\t          Enter new name(without space): ";
									cin.ignore();
									getline(cin,itemName);
									cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
									break;
								}
								case 2:
								{
									
									cout<<"\t\t\t\t\t          Enter new quantity: ";
									cin>>quan;
									cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
									break;
								}	
								case 3:
								{
									cout<<"\t\t\t         Enter new description(without space): ";
									cin.ignore();
									getline(cin,description);
						
									cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
									break;
								}	
								case 4:
								{
									
									cout<<"\t\t\t         Enter new price: ";
									cin>>pri;
									cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
									break;
								}
								default:
									
									//for invalid input
									cout<<"\t\t\t             Invalid input."<<endl;
									break;
							}
						}	
						
						//to write the updated detail in the temporary file
						temp<< itemName << " " << quan<< " " << pri <<" "<<description<< endl;
						
					}
					
					//to close the text files
					read.close();
					temp.close();
					
					//to replace the temporary file with the orignal one
					remove("Inventory.txt");
					rename("temp.txt","Inventory.txt");
					
					if(found==true)
					{
						cout<<"\t\t\t\t\t                    Item edited successfully.                          \n"<<endl;	
					}					
		
					else
					{
						cout<<"\t\t\t\t\t                    Item not found.                                    \n"<<endl;
					}
					
					cout<<endl;
					
					//to ask user if wants to edit any other item
					cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
					cout<<"\t\t\t\t\t                 Do you want to edit any other item?(y/n): "<<endl;
					cout<<" \t\t\t\t\t                        Your choice: ";
					cin>>choose;
					cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
		
				
				}
				else
				{
					
					//error file not found
					cout<<"\t\t\t\t\t                Inventory file not found."<<endl;
					cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
					
				}
			}
			while(choose=='y'||choose=='Y');
			
		}
		
		void displayitem()
		{
			
			char choose;
			bool found=false;
			string item_name,descrip;
			int quan;
			double pri;
			string name;
			
			do
			{
				
				found=false;
				
				//to enter item name user wants to display
				cout<<endl;
				cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				cout<<"\t\t\t\t\t             Enter item you want to display: ";
				cin.ignore();
				getline(cin,name);
				item.setitem_name(name);
				cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				
				ifstream read("Inventory.txt");
				
				//to check if the file is open
				if(read.is_open())
				{
					
					//read the inventory file to find the item
					while(read>>item_name>>quan>>pri>>descrip)
					{
						
						//to check if the item matches the item entered by the user
						if(item_name==item.getitem_name())
						{	
						
							cout<<endl<<endl;
							
							//to display the details of entered item 
							cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
							cout<<"\t\t\t\t\t            Item name: "<<item_name<<endl;
							cout<<"\t\t\t\t\t            Quantity: "<<quan<<endl;
							cout<<"\t\t\t\t\t            Description: "<<descrip<<endl;
							cout<<"\t\t\t\t\t            Price: $"<<pri<<endl;
							cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
							
							found=true;
						}
						
					}
					
					if(found==false)
					{
						cout<<"\t\t\t\t\t              Item not found."<<endl;
						cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
					}
				}	

				else
				{
					cout<<"\t\t\t\t\t            Error . inventory file not found."<<endl;
					cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				}
				
				//to close the file
				read.close();
				
				//prompt if user want to diaplay any other item
				cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				cout<<"\t\t\t\t\t            Do you want to display any other item?(y/n)";
				cin>>choose;
				cout<<"\t\t\t\t\t-----------------------------------------------------------\n";	
			}	
			while(choose=='y'|| choose=='Y');

		
		}
		
		void deleteitem()
		{
		
			string name,item_name,description;
			int quantity;
			double price;
			bool found=false;
			char choose;
			
			do
			{
				
				found=false;
				
				//prompt to enter the item name you want to delete
				cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				cout<<"\t\t\t\t\t        Enter item name you want to delete."<<endl;
				cout<<"\t\t\t\t\t                 Item name: ";
				cin.ignore();
				getline(cin,name);
				item.setitem_name(name);
				cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				
				ifstream read("Inventory.txt");
				ofstream write("temp.txt");
				
				//to check if the files are open
				if(read.is_open() && write.is_open())
				{
					while(read>>item_name>>quantity>>price>>description)
					{
					
						
						//to check the item
						if(item_name==item.getitem_name())
						{
							found=true;
						}
						
						else
						{
							
							//write all other item except deleted item in the temporary file
							write<<item_name<<" "<<quantity<<" "<<price<<" "<<description<<endl;
	
						}
					}
					
					//close the text files
					read.close();
					write.close();
					
					//replaces the temporary files with the orignal one
					remove("Inventory.txt");
					rename("temp.txt","Inventory.txt");
					
					if(found=false)
					{
						cout<<"\t\t\t\t\t              Item not found."<<endl;
						cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
					}
					
					else
					{
						cout<<"\t\t\t\t\t              Item deleted successfully."<<endl;	
						cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
					}
					
				}
				
				else
				{
					cout<<"\t\t\t\t\t                 Error opening file."<<endl;
					cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				}
				
				//to ask if he wants to delete any other item
				cout<<"\t\t\t\t\t               Do you want to delete any other item?(y/n): ";
				cin>>choose;
				cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				
			}
			while(choose=='y'||choose=='Y');
		
		
		}
		
					
		void view_inventory()
		{
			
			string item_name;
			string description;
			int quantity;
			double price;
			int counter=0;
			
			cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
			
			ifstream read("Inventory.txt");
			
			if(read.is_open())
			{
				while(read>>item_name>>quantity>>price>>description)
				{
					Item item;
					++counter;
					
					cout<<"\t\t\t\t\t           Item No: "<<counter<<endl;
					cout<<"\t\t\t\t\t           Item name: "<<item_name<<endl;
					cout<<"\t\t\t\t\t           Quantity: "<<quantity<<endl;
					cout<<"\t\t\t\t\t           Description: "<<item.getdescription()<<endl;
					cout<<"\t\t\t\t\t           Price: "<<price<<endl;
					cout<<endl;
				}
			}
			cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
			
		}
		
		
	
};


class ADMIN
{
	public:
		
		Inventory inventory;
		
		//function to handle admin login
		bool Adminlogin()
		{
			user user1;
			string username,password,user,pw;
			
			//prompt to enter username and password
			cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
			cout<<"\t\t\t\t          		Enter username: ";
			cin>>username;
			user1.setusername(username);
			
			cout<<"\t\t\t\t\t                Enter password: ";
			cin>>password;
			user1.setpassword(password);
			
			cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
			
			ifstream read("admin.txt");
			
			//to check if the file is open or not
			if(read.is_open())
			{
				while(getline(read,user)&& getline(read,pw))
				{
					if(user==user1.getusername()&&pw==user1.getpassword())
					{
						//successfull login
						cout<<"\t\t\t\t\t           Login Successfully!                 \n\n"<<endl;
						read.close();
						return true;
				
					}
				}
				
				//login error
				cout<<"\t\t\t\t\t          Login error. Invalid username or password.\n\n"<<endl;
				read.close();
				return false;
					
			}
			
				else
				{
					cout<<"\t\t\t\t\t         Unable to find admin.txt file.              \n\n"<<endl;
					return false;
				}
						
	}
	
	
		void AdminMenue()
		{
			char choose;
			int choice;
			
			do
			{
				
				//display the admin
				cout<<"\t\t\t\t\t                    Admin Menue                "<<endl;
				cout<<"\t\t\t\t\t----------------------------------------------------------\n";
				cout<<"\t\t\t\t\t|                 1. Manage inventory.                    | "<<endl;
				cout<<"\t\t\t\t\t|                 2. View sales log.                      |"<<endl;
				cout<<"\t\t\t\t\t|                 3. Create salesperson account.          |"<<endl;
				cout<<"\t\t\t\t\t|                 4. View sales person details.           |"<<endl;
				cout<<"\t\t\t\t\t|                 5. log out.                             |"<<endl;
				cout<<"\t\t\t\t\t----------------------------------------------------------\n";
				cout<<"\t\t\t\t\t                Enter your choice:";
				cin>>choice;
				cout<<endl;
				
				//handle the user's input
				switch (choice)
				{
					case 1:
					{
						manageinventory();
						break;
					}
					case 2:
					{	
						ViewSales();
						break;
					}
					case 3:
					{	
						CreateAccount();
						break;
					}
					case 4:
					{
						view_details();
						break;
						
					}
					case 5: 
					
					{
					   cout<<"\t\t\t\t\t           Logging out......";
					   break;	
					}
					default:
						cout<<"\t\t\t\t\t         Invalid Input."<<endl;
						AdminMenue();				
				}
				
				//ask the user if he wants to return to the main menue
				cout<<"\t\t\t\t\t       Do you want to return to the menue?(y/n): ";
				cin>>choose;
				
			}
			while(choose=='y'||choose=='Y');

		}
	
		void manageinventory()
		{
			
			int choice;
			cout<<endl;
			
			
			//display the inventory menue
			cout<<"\t\t\t\t\t                    Inventory Menue                    "<<endl;
			cout<<"\t\t\t\t\t----------------------------------------------------------\n";
			cout<<"\t\t\t\t\t|                    1. Add item to inventroy.            |"<<endl;
			cout<<"\t\t\t\t\t|                    2. Edit item in inventory.           |"<<endl;
			cout<<"\t\t\t\t\t|                    3. Display item in inventory.        |"<<endl;
			cout<<"\t\t\t\t\t|                    4. Delete any item in inventory.     |"<<endl;
			cout<<"\t\t\t\t\t|                    5. View inventory.                   |"<<endl;
			cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
			cout<<"\t\t\t\t\t                    Your choice: ";
			cin>>choice;
			cout<<endl;
			
			//handle the user's choice
			switch(choice)
			{
				case 1:
				{
					inventory.AddItem();
					break;
				}
				case 2:
				{
					inventory.EditItem();
					break;	
				}
				case 3:
				{
					inventory.displayitem();
					break;	
				}
				case 4:
				{
					inventory.deleteitem();
					break;
				}
				case 5:
				{
					inventory.view_inventory();	
				}	
				default:
					cout<<"\t\t\t\t\t                 Invalid input."<<endl;
					cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
					manageinventory();	
					
			}
		}	

	
	void ViewSales()
	{
		
		string date;
		bool found=false;
		string d;
		string customer_name,Fname,Lname;
		string item_name;
		double sale;
		int Quantity;
		string da;
		float price;
		cout<<endl;
		
		//to input the date
		cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
		cout<<"\t\t\t\t\t             Enter date (YYYY-MM-DD): ";
		cin>>d;
		cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
		
		ifstream read("sales.txt");
		
		//to check if the file is open
		if(read.is_open())
		{
			
			while(read>>date>>Fname>>Lname>>sale)
			{
				
				//to compare the date
				if(d==date)
				{
					cout<<endl;
					cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
					cout<<"\t\t\t\t\t                customer name: "<<Fname<<" "<<Lname<<endl;
					
					ifstream sale_file("cus_sale.txt");
					
					sale_file.is_open();
					
					while(sale_file>>da>>customer_name>>item_name>>Quantity>>price)
					{
						
						if(da==d&&customer_name==Fname)
						{
							cout<<"\t\t\t\t\t      Item name: "<<item_name<<endl;
							cout<<"\t\t\t\t\t      Quantity: "<<Quantity<<endl;
							cout<<"\t\t\t\t\t      Price: $"<<price<<endl;
						}
						
						
					}
					//to close the file
					sale_file.close();
					
					cout<<"\t\t\t\t\t         Sale: $ "<<sale<<endl;
					cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
					
				}
			}
			
		}
		else
		{
			cout<<"\t\t\t\t\t                       ERROR!"<<endl;
		}
		
	
		
	}

	
	bool CreateAccount()
	{
		user user1;
		string username,password;
		char choice;
		string first_name;
		string last_name;
		string phone_no;
		
		do
		{
			ofstream file("salesperson.txt",ios::app);
			
			//to check if the file is open
			if(file.is_open())
			{
				cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				cout<<"\t\t\t\t\t                   Enter a username: ";
				cin>>username;
				user1.setusername(username);
				
				cout<<"\t\t\t\t\t                   Select a password: ";
				cin>>password;
				user1.setpassword(password);
				
				cout<<"\t\t\t\t\t                   First name: ";
				cin>>first_name;
				
				cout<<"\t\t\t\t\t                   Last name: ";
				cin>>last_name;
				
				cout<<"\t\t\t\t\t                   Phone no(0000-0000000): ";
				cin>>phone_no;
				
				cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				
				//to enter the details of salesperson in the file
				file<<user1.getusername()<<" "<<user1.getpassword()<<" "<<first_name<<" "<<last_name<<" "<<phone_no<<endl;
				
				//closes the file
				file.close();
				cout<<endl;	
			}
			
			else
			{
				cout<<"\t\t\t\t\t            Error....!"<<endl;
			}
			
			//asks if he want to create another account
			cout<<"\t\t\t\t\t      Do you want to create another account?(y/n): ";
			cin>>choice;	
		}
		
		while(choice=='y'||choice=='Y');

	}
	
	void view_details()
	{
		string F_name;
		string L_name;
		string username;
		string password;
		string phone;
		int count=0;
		
		ifstream read("salesperson.txt");
		
		cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
		if(read.is_open())
		{
			while(read>>username>>password>>F_name>>L_name>>phone)
			{
				++count;
				
				cout<<"\t\t\t\t\t            SALESPERSON No: "<<count<<endl;
				cout<<"\t\t\t\t\t            Username: "<<username<<endl;
				cout<<"\t\t\t\t\t          	 	Password:  "<<password<<endl;
				cout<<"\t\t\t\t\t            First name: "<<F_name<<endl;
				cout<<"\t\t\t\t\t            Last name: "<<L_name<<endl;
				cout<<"\t\t\t\t\t            Phone no: "<<phone<<endl;
				cout<<endl;
				
			}
			cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
		}
	}
	
	
};

class SalesPerson
{
public:
		
		bool login()
		{
			user user2;
			string phone;
			string first_name;
			string last_name;
			string n,p,name,pass;
			
			cout<<endl;
			cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
			cout<<"\t\t\t\t\t                Enter username: ";
			cin>>n;
			user2.setusername(n);
			
			cout<<"\t\t\t\t\t                Enter password: ";
			cin>>p;
			user2.setpassword(p);
			cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
			
			ifstream read("salesperson.txt");
			
			//check if the file is open
			if(read.is_open())
			{
				while(read>>name>>pass>>first_name>>last_name>>phone)
				{
					if(name==user2.getusername()&&pass==user2.getpassword())
					{
						
						//successfull login
						cout<<"\t\t\t\t\t              Login Successfully!"<<endl;
						cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
						read.close();
						return true;
				
					}
				}
				
				//login error
				cout<<"\t\t\t\t\t               Login error. Invalid username or password."<<endl;
				cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				
				//closes the file
				read.close();
				return false;	
			}
			else
			{
				cout<<"\t\t\t\t\t              Unable to find salesperson.txt file. "<<endl;
				cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				return false;
			}
			
		}
		
		void view_inventory1()
		{
			
			string item_name;
			string description;
			int quantity;
			double price;
			int counter=0;
			
			cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
			
			ifstream read("Inventory.txt");
			
			if(read.is_open())
			{
				while(read>>item_name>>quantity>>price>>description)
				{
					++counter;
					
					cout<<"\t\t\t\t\t           Item No: "<<counter<<endl;
					cout<<"\t\t\t\t\t           Item name: "<<item_name<<endl;
					cout<<"\t\t\t\t\t           Quantity: "<<quantity<<endl;
					cout<<"\t\t\t\t\t           Description: "<<description<<endl;
					cout<<"\t\t\t\t\t           Price: "<<price<<endl;
					cout<<endl;
				}
			}
			cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
			
		}
		
		
		
		
		void salesperson_menue()
		{
			int choice;
			char choose;
			do
			{
				cout<<endl;
				
				//display the sales person menue
				cout<<"\t\t\t\t\t              Sales person menue"<<endl;
				cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				cout<<"\t\t\t\t\t|              1. Search item                              |"<<endl;
				cout<<"\t\t\t\t\t|              2. View inventory                           |"<<endl;
				cout<<"\t\t\t\t\t|              3. Make sales                               |"<<endl;
				cout<<"\t\t\t\t\t|              4. log out                                  |"<<endl;
				cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				cout<<endl;
				cout<<"\t\t\t\t\t             Enter your choice: ";
				cin>>choice;
				cout<<endl;
				
				switch(choice)
				{
					case 1:
				
						searchitem();
						break;

						
					case 2:
						
						view_inventory1();
						break;
					
					case 3:
	
						makesale();
						update();
						break;				 		
		
					
					case 4: 
					
						cout<<"\t\t\t\t\t            Logging out........."<<endl;
						break;
					
					
					default:
						cout<<"\t\t\t\t\t            Invalid input."<<endl;		
						
				}
				
				cout<<"\t\t\t\t\t             Do you want to return to the menue?(y/n): ";
				cin>>choose;
				
			}
			while(choose=='y'||choose=='Y');
				
		}
	
	
		

	
		
		
		void makesale()
		{
			
			char choice;
			int customerno;
			double Total_Bill=0;
			string Fname,Lname;
			cout<<endl;
			
			cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
			cout<<"\t\t\t\t\t                 First name: ";
			cin>>Fname;
			
			cout<<"\t\t\t\t\t                 Last name: ";
			cin>>Lname;
	
			
			
			
			do
			{
				string itemName,descrip;
				int quan,quantity;
				double price;
				string name;
				
				bool found=false;
				
				cout<<"\t\t\t\t\t          	  Item name: ";
				cin>>name;
			
				
				ifstream file("Inventory.txt");
				ofstream write1("temp.txt",ios::app);
				if(file.is_open()&&write1.is_open())
				{
					while(file>>itemName>>quan>>price>>descrip)
					{
						
						if(itemName==name)
						{
							found=true;
							cout<<"\t\t\t\t\t              Quantity: ";
							cin>>quantity;
							if(quantity<=quan)
							{
								double total_sale=0;
								total_sale=price*quantity;
								cout<<"\t\t\t\t\t            Total: "<<total_sale<<endl;
								
								quan-=quantity;
								Total_Bill=Total_Bill+total_sale;
								
								ofstream write2("cus_sale.txt",ios::app);
								
								if(write2.is_open())
								{
									write2<<getCurrentDate()<<" "<<	Fname<<" "<<itemName<<" "<<quantity<<" "<<total_sale<<endl;
									write2.close();									
								}
								
								else
								{
									cout<<"\t\t\t\t\t            Error in opening file."<<endl;
								}
								
							}
							
							else
							{
								cout<<"\t\t\t\t\t           Not enough quantity in the stock."<<endl;
							}
							
						}
						write1<<itemName<<" "<<quan<<" "<<price<<" "<<descrip<<endl;
						

					}
					
					file.close();
					write1.close();
					remove("Inventory.txt");
		
					rename("temp.txt","Inventory.txt");
					
					
					
					if(found==0)
					{
						cout<<"\t\t\t\t\t               Item not found."<<endl;
					}					

				}
				
				else
				{
				
					cout<<"\t\t\t\t            Error in opening inventory file."<<endl;	
					cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				}
				
				cout<<"\t\t\t\t\t             Do you want to buy any other item?(y/n): ";
				cin>>choice;
				
				if(choice=='n'|| choice=='N')
				{
					if(found==true)
					{
						cout<<"\t\t\t\t\t	      Total bill: "<<Total_Bill<<endl;
						cout<<"\t\t\t\t\t         Sale successfull!....."<<endl;
						cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
						
					}
				}
			
			}
			
			while(choice=='y'||choice=='Y');
			
		 	ofstream write("sales.txt",ios::app);	
		 	
			if(write.is_open())
			{
				write<<getCurrentDate()<<" "<<Fname<<" "<<Lname<<" "<<Total_Bill<<endl;
				write.close();	
			}
				
		}
		

	
		string getCurrentDate() 
		{
        	time_t now = time(0);
 	    	tm *ltm = localtime(&now);
    	    char date[20];
        	strftime(date, 20, "%Y-%m-%d", ltm);
	        return string(date);
    	}
		
		
		void searchitem()
		{
			Item item;
			char choose;
			bool found=false;
			string item_name,descrip;
			int quan;
			double pri;
			string name;
			
			do
			{
				found=false;
				
				cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				cout<<"\t\t\t\t\t             Enter item you want to search: ";
				cin.ignore();
				getline(cin,name);
				item.setitem_name(name);
				cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				
				ifstream read("Inventory.txt");
				
				if(read.is_open())
				{
					while(read>>item_name>>quan>>pri>>descrip)
					{
						
						
						if(item_name==item.getitem_name())
						{	
							cout<<"\t\t\t\t\t            Item name: "<<item_name<<endl;
							cout<<"\t\t\t\t\t            Quantity: "<<quan<<endl;
							cout<<"\t\t\t\t\t            Description: "<<descrip<<endl;
							cout<<"\t\t\t\t\t            Price: $"<<pri<<endl;
							cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
							found=true;
						}
					}
					
					if(found==false)
					{
						cout<<"\t\t\t\t\t              Item not found."<<endl;
						cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
					}
				}	

				else
				{
					cout<<"\t\t\t\t\t            Error . inventory file not found."<<endl;
					cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				}
				
				read.close();
				
				cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				cout<<"\t\t\t            Do you want to search any other item?(y/n): ";
				cin>>choose;
				cout<<"\t\t\t\t\t-----------------------------------------------------------\n";	
			}
				
			while(choose=='y'|| choose=='Y');

		
		}
							
		void update()
		{
			string item_name,description;
			int quantity;
			double price;
			
			ifstream read("Inventory.txt");
			ofstream write("temp.txt",ios::app);
			
			if(read.is_open() && write.is_open())
			{
				while(read>>item_name>>quantity>>price>>description)
				{
				
					
					if(!quantity==0)
					{
						write<<item_name<<" "<<quantity<<" "<<price<<" "<<description<<endl;
					}
					
				}
				
			read.close();
			write.close();
			
			remove("Inventory.txt");
			rename("temp.txt","Inventory.txt");
			}
		}
		
		
					
		
};	
		
	
	
int main()
{
	
	int choice;
	
	//display the welcome menue
	cout<<"\t\t\t\t\t*********************************************************\n";
	cout<<"\t\t\t\t\t*                                                       *\n";
	cout<<"\t\t\t\t\t*         Welcome to retail management system           * \n";
	cout<<"\t\t\t\t\t*                                                       *\n";
	cout<<"\t\t\t\t\t*********************************************************\n\n";
	
	
	//main meue
	cout<<"\t\t\t\t\t                        MENUE                              \n";
	cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
	cout<<"\t\t\t\t\t|               Press 1 for Admin menue                    |"<<endl;
	cout<<"\t\t\t\t\t|               Press 2 for sales person menue             |"<<endl;
	cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
	cout<<"\t\t\t\t\t                Enter your choice: ";
	cin>>choice;
	
	//handle the user's choice
	switch(choice)
	{
		case 1:
			{
				ADMIN obj;
				
				if(obj.Adminlogin())
				{
					//successfull login
					obj.AdminMenue();
				}
				else
				{
					
					//login error
					cout<<"\t\t\t\t\t            Sorry . You can't login to the system."<<endl;
					cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				}
				break;
			}
		case 2:
			{
				SalesPerson person;	
				
				if(person.login())	
				{
					//successfull login
					person.salesperson_menue();		
				}
				else
				{
					
					//login error
					cout<<"\t\t\t\t\t            You can't login to the system."<<endl;
					cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
				}
				break;
			}
		default:
			cout<<"\t\t\t\t\t           	Invalid input."<<endl;	
			cout<<"\t\t\t\t\t-----------------------------------------------------------\n";
	}
	return 0;
	
}
