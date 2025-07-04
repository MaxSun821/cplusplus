#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ofstream;
using std::ifstream;
using std::ostream;
using std::istream;
using std::istringstream;
using std::ostringstream;

class Date {
	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
	}

	operator bool()
	{
		if (_year == 0)
			return false;
		else
			return true;
	}
private:
	int _year;
	int _month;
	int _day;
};

istream& operator >> (istream& in, Date& d) {
	in >> d._year >> d._month >> d._day;
	return in;
}

//ofs << winfo._date;
ostream& operator << (ostream& out, const Date& d) {
	//out << d._year << "年" << d._month << "月" << d._day<<"日";
	//out << d._year << "/" << d._month << "/" << d._day;
	out << d._year << " " << d._month << " " << d._day;

	return out;
}

struct ServerInfo {
	// char address[32]; // IP address or URL
	string address; // IP address or URL
	int port;        // Port number
	Date date; // Date of the server info
};

class BinIO {
public:
	BinIO(const char* filename = "info.bin") : filename_(filename) {}
	void Write(const ServerInfo& server) {
		ofstream ofs(filename_, ofstream::out | ofstream::binary);
		if (!ofs) {
			cout << "Error opening file for writing." << endl;
			return;
		}
		ofs.write(reinterpret_cast<const char*>(&server), sizeof(ServerInfo));
	}
	void Read(ServerInfo& server) {
		ifstream ifs(filename_, ifstream::in | ifstream::binary);
		if (!ifs) {
			cout << "Error opening file for reading." << endl;
			return;
		}
		ifs.read(reinterpret_cast<char*>(&server), sizeof(ServerInfo));
		if (!ifs) {
			cout << "Error reading from file." << endl;
		}
	}
private:
	string filename_;
};


//int main() {
//	ServerInfo server = { "192.0.0.1", 8080, {2022, 2, 2} };
//	BinIO binIO;
//	binIO.Write(server);
//	return 0;
//}

//int main() {
//	BinIO binIO;
//	ServerInfo server;
//	binIO.Read(server);
//	return 0;
//}

class TextIO {
public:
	TextIO(const char* filename = "info.txt") : filename_(filename) {}
	void Write(const ServerInfo& server) {
		ofstream ofs(filename_);
		if (!ofs) {
			cout << "Error opening file for writing." << endl;
			return;
		}
		ofs << server.address << " " << server.port << " " << server.date << endl;
	}
	void Read(ServerInfo& server) {
		ifstream ifs(filename_);
		if (!ifs) {
			cout << "Error opening file for reading." << endl;
			return;
		}
		ifs >> server.address >> server.port >> server.date;
	}
private:
	string filename_;
};

//int main() {
//	ServerInfo server = { "https://legacy.cplusplus.com/reference/fstream/ifstream/ifstream/", 8080, { 2022, 4, 10 } };
//	TextIO textIO;
//	textIO.Write(server);
//
//	ServerInfo readServer;
//	textIO.Read(readServer);
//
//	cout << "Address: " << readServer.address << endl;
//	cout << "Port: " << readServer.port << endl;
//	cout << "Date: " << readServer.date << endl;
//	return 0;
//}

int main() {
	int age = 0;
	cin >> age;
	ostringstream oss;
	oss << "SELECT * FROM users WHERE age > " << age << ";";

	string str = oss.str();

	cout << str << endl;

}