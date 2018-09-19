#include <iostream>
#include <fstream>
#include<conio.h>

using namespace std;

int main(int argc, char** argv) {
	char choice[1];
	cout << ">>>>>>>>>>>>> run\n";
	cout << "SELECT OPTION \n";
	cout << "1 -> Add host\n";
	cout << "2 -> Remove host\n";
	cout << "3 -> View all hosts\n";
	fstream fs , host;
	fs.open ("C:/xampp/apache/conf/extra/httpd-vhosts.conf", fstream::in | fstream::out | fstream::app);
	if(!fs.is_open())
    {
        cout<<"Could not open file C:/xampp/apache/conf/extra/httpd-vhosts.conf"<<endl;
    }
	host.open ("C:/Windows/System32/drivers/etc/hosts", fstream::in | fstream::out | fstream::app);
	if(!host.is_open())
    {
        cout<<"Could not open file C:/Windows/System32/drivers/etc/hosts"<<endl;
    }
	int command;
	cout << "Command : ";
	cin >> command;
	if(command == 1)
	{
		char directory[100];
		char host_name[100];
		cout << "Directory Name : ";
		cin >> directory;
		cout << "Host Name : ";
		cin >> host_name;
		
		fs << "\n\n<VirtualHost *:80>\n"<<
	    		"ServerAdmin webmaster@dummy-host2.example.com\n"<<
	    		"DocumentRoot \"C:/xampp/htdocs/"<< directory <<"\"\n"
	    		"ServerName "<< host_name<<"\n" <<
				"</VirtualHost>\n";
		fs.close();
	
		host << "	127.0.0.1       " << host_name << endl;
		host.close();	
		cout << "\n new host is added http://" << host_name << endl;	
		cout << "\n Please restart your apache server \n";
	}
	
	cout << "\n<<<<<<<<<<<< end\n";
	getch();
	return 0;
}
