
// CIS22B
// Lab3
// Juan Wang

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

enum status
{
	CHECKED_OUT, ON_SHELF
};

struct BookInfo
{
	string title;
	string author;
	string isbn;
	string rig_ID;		// used as the ID for each book
	int copies;			// total copies number of the book
	int available;		// current number of copies available in library
	status bStatus;
};

void add_saving_book(vector<BookInfo> &);
void searchByTitle(const vector<BookInfo> &, string);
void searchByAuthor(const vector<BookInfo> &, string);
void searchByISBN(const vector<BookInfo> &, string);
void checkOut(vector<BookInfo> &, string);
void checkIn(vector<BookInfo> &, string);
void listByStatus(const vector<BookInfo> &, status);
void sortByTitle(vector<BookInfo>);
void sortByAuthor(vector<BookInfo>);


int main(){

	string btile;
	string bauthor;
	string bisbn;
	string brig_ID;		// hold rigister number for a book 
	int num;
	status bstatus;

	vector<BookInfo> books {
		{ "The Absorbent Mind", "Montessori", "9780805041569", "259.901", 5, 3, ON_SHELF },
		{ "Little Women", "Louisa May Alcott", "9780194237574", "478.09", 4, 0, CHECKED_OUT },
		{ "Gone With The Wind", "Margaret Mitchell", "9781419891038", "334.7", 13, 6, ON_SHELF },
		{ "Pride And Prejudice", "Jane Austen", "9780553213102", "321.223", 6, 2, ON_SHELF },
		{ "Math", "Dan Green", "9780753464199", "008.001", 2, 0, CHECKED_OUT },
		{ "Starting Out With C++", "Tony Gaddis", "9780132772891", "209.456", 4, 3, ON_SHELF },
		{ "Programming With Java", "Barry A. Burd", "9780470371749", "155.23", 5, 1, ON_SHELF },
		{ "Data Structures", "Narasimha Karumanchi", "9781468108866", "005.133", 7, 0, CHECKED_OUT },
		{ "North And South", "Elizabeth Gaskell", "9781934648247", "789.456", 6, 5, ON_SHELF }
	};


	// call add_saving_book founction to add and save a new book
	cout << "Here comes  a new book!\n";
	add_saving_book(books);
	cout << "The new book is added to the library system.\n";

	// call searchByTitle function to search book by title
	cout << "\nPlease enter the book name you are searching for, with first character of each word capitalized : \n";
	cin.ignore();
	getline(cin, btile);
	searchByTitle(books, btile);

	// call searchByAuthor function to search book by author
	cout << "\nPlease enter the author name of the book you are searching for, with first character of each word capitalized:\n";
	getline(cin, bauthor);
	searchByAuthor(books, bauthor);

	// call searchByISBN function to search book by ISBN number
	cout << "\nPlease enter the ISBN number of the book you are searching for:\n";
	getline(cin, bisbn);
	searchByISBN(books, bisbn);

	// call checkOut founction to check out a book
	cout << "\nPlease enter the rigster ID of the book you wish to check out:\n";;
	getline(cin, brig_ID);
	checkOut(books, brig_ID);

	// call checkIn founction to check in a book
	cout << "\nPlease enter the rigster ID of the book you wish to check in:\n";;
	getline(cin, brig_ID);
	checkIn(books, brig_ID);

	// call listByStatus function to display books by status
	cout << "\nPlease enter the book status : 0 for CHECKED_OUT, 1 for ON_SHELF.\n";
	cin >> num;
	bstatus = static_cast<status>(num);
	listByStatus(books, bstatus);

	// call sortByTitle function to display book collections sorted by title
	sortByTitle(books);

	// call sortByAuthor function to display book collections sorted by author
	sortByAuthor(books);


	system("pause");
	return 0;

}

void add_saving_book(vector<BookInfo> &bookvec){
	// use a BookInfor struct variable to hold information for the new book
	BookInfo newbook;
	int number;
	cout << "Please enter the new book name with first character of each word capitalized:\n";
	getline(cin, newbook.title);
	cout << "Please enter the author name of the new book with first character of each word capitalized:\n";
	getline(cin, newbook.author);
	cout << "Please enter the ISBN number of the new book:\n";
	getline(cin, newbook.isbn);
	cout << "Please enter the register number of the new book:\n";
	getline(cin, newbook.rig_ID);
	cout << "Please enter the copies number of the new book:\n";
	cin >> number;
	newbook.copies = number;
	newbook.available = number;
	newbook.bStatus = ON_SHELF;
	// add this newbook struct to bookvec vector
	bookvec.push_back(newbook);
}


void searchByTitle(const vector<BookInfo> &Myvec, string mytle){
	int index;
	bool isFound = false;
	for (int i = 0; i < Myvec.size(); i++){
		if (Myvec[i].title == mytle){
			index = i;
			isFound = true;
			break;
		}
	}
	if (isFound == true){
		cout << "Follwing is the book information searched by title " << mytle << ": \n";
		cout << left << setw(25) << "Title" << left << setw(25) << "Author" << left << setw(20) << "ISBN" << left << setw(15) << "Rig. ID"
			<< left << setw(10) << "Copies" << left << setw(15) << "Available" << left << setw(15) << "Status" << endl;
		cout << left << setw(25) << Myvec[index].title << left << setw(25) << Myvec[index].author << left << setw(20) << Myvec[index].isbn
			<< left << setw(15) << Myvec[index].rig_ID << left << setw(10) << Myvec[index].copies << left << setw(15) << Myvec[index].available;
		if (Myvec[index].bStatus == 0){
			cout << left << setw(15) << "CHECKED_OUT" << endl;
		}
		else{
			cout << left << setw(15) << "ON_SHELF" << endl;
		}
	}
	else{
		cout << "Sorry, no matching information is found.\n\n";
	}
}


void searchByAuthor(const vector<BookInfo> &Myvec, string myath){
	int index;
	bool isFound = false;
	for (int i = 0; i < Myvec.size(); i++){
		if (Myvec[i].author == myath){
			index = i;
			isFound = true;
			break;
		}
	}
	if (isFound == true){
		cout << "Follwing is the book information searched by author " << myath << ": \n";
		cout << left << setw(25) << "Title" << left << setw(25) << "Author" << left << setw(20) << "ISBN" << left << setw(15) << "Rig. ID"
			<< left << setw(10) << "Copies" << left << setw(15) << "Available" << left << setw(15) << "Status" << endl;
		cout << left << setw(25) << Myvec[index].title << left << setw(25) << Myvec[index].author << left << setw(20) << Myvec[index].isbn
			<< left << setw(15) << Myvec[index].rig_ID << left << setw(10) << Myvec[index].copies << left << setw(15) << Myvec[index].available;
		if (Myvec[index].bStatus == 0){
			cout << left << setw(15) << "CHECKED_OUT" << endl;
		}
		else{
			cout << left << setw(15) << "ON_SHELF" << endl;
		}
	}
	else{
		cout << "Sorry, no matching information is found.\n";
	}
}


void searchByISBN(const vector<BookInfo> &Myvec, string myisbn){
	int index;
	bool isFound = false;
	for (int i = 0; i < Myvec.size(); i++){
		if (Myvec[i].isbn == myisbn){
			index = i;
			isFound = true;
			break;
		}
	}
	if (isFound == true){
		cout << "Follwing is the book information searched by ISBN number " << myisbn << ": \n";
		cout << left << setw(25) << "Title" << left << setw(25) << "Author" << left << setw(20) << "ISBN" << left << setw(15) << "Rig. ID"
			<< left << setw(10) << "Copies" << left << setw(15) << "Available" << left << setw(15) << "Status" << endl;
		cout << left << setw(25) << Myvec[index].title << left << setw(25) << Myvec[index].author << left << setw(20) << Myvec[index].isbn
			<< left << setw(15) << Myvec[index].rig_ID << left << setw(10) << Myvec[index].copies << left << setw(15) << Myvec[index].available;
		if (Myvec[index].bStatus == 0){
			cout << left << setw(15) << "CHECKED_OUT" << endl;
		}
		else{
			cout << left << setw(15) << "ON_SHELF" << endl;
		}
	}
	else{
		cout << "Sorry, no matching information is found.\n";
	}
}


void checkOut(vector<BookInfo> &Myvec, string Myrigid){
	int index;
	for (int i = 0; i < Myvec.size(); i++){
		if (Myvec[i].rig_ID == Myrigid){
			index = i;
			break;
		}
	}
	if (Myvec[index].available > 0){
		Myvec[index].available -= 1;
		if (Myvec[index].available == 0){
			Myvec[index].bStatus = CHECKED_OUT;
			cout << "Check out is finished.\n";
			cout << "Following is the current store information of the book you checked out in the library.\n";
			cout << left << setw(25) << "Title" << left << setw(25) << "Author" << left << setw(20) << "ISBN" << left << setw(15) << "Rig. ID"
				<< left << setw(10) << "Copies" << left << setw(15) << "Available" << left << setw(15) << "Status" << endl;
			cout << left << setw(25) << Myvec[index].title << left << setw(25) << Myvec[index].author << left << setw(20) << Myvec[index].isbn
				<< left << setw(15) << Myvec[index].rig_ID << left << setw(10) << Myvec[index].copies << left << setw(15) << Myvec[index].available
				<< left << setw(15) << "CHECKED_OUT" << endl;
		}
		cout << "Check out is finished.\n";
		cout << "Following is the current store information of the book you checked out in the library.\n";
		cout << left << setw(25) << "Title" << left << setw(25) << "Author" << left << setw(20) << "ISBN" << left << setw(15) << "Rig. ID"
			<< left << setw(10) << "Copies" << left << setw(15) << "Available" << left << setw(15) << "Status" << endl;
		cout << left << setw(25) << Myvec[index].title << left << setw(25) << Myvec[index].author << left << setw(20) << Myvec[index].isbn
			<< left << setw(15) << Myvec[index].rig_ID << left << setw(10) << Myvec[index].copies << left << setw(15) << Myvec[index].available
			<< left << setw(15) << "ON_SHELF" << endl;
	}
	else{
		cout << "Sorry, the book you wish to check out is not available right now in the library.\n";
	}
}


void checkIn(vector<BookInfo> &Myvec, string Myrigid){
	int index;
	for (int i = 0; i < Myvec.size(); i++){
		if (Myvec[i].rig_ID == Myrigid){
			index = i;
			break;
		}
	}
	Myvec[index].available += 1;
	if (Myvec[index].bStatus == CHECKED_OUT){
		Myvec[index].bStatus = ON_SHELF;
	}
	cout << "Check in is finished.\n";
	cout << "Following is the current store information of the book you checked in in the library.\n";
	cout << left << setw(25) << "Title" << left << setw(25) << "Author" << left << setw(20) << "ISBN" << left << setw(15) << "Rig. ID"
		<< left << setw(10) << "Copies" << left << setw(15) << "Available" << left << setw(15) << "Status" << endl;
	cout << left << setw(25) << Myvec[index].title << left << setw(25) << Myvec[index].author << left << setw(20) << Myvec[index].isbn
		<< left << setw(15) << Myvec[index].rig_ID << left << setw(10) << Myvec[index].copies << left << setw(15) << Myvec[index].available
		<< left << setw(15) << "ON_SHELF" << endl;
}


void listByStatus(const vector<BookInfo> &Mypvec, status Mysts){
	cout << "Boook collections listed by status you just entered:\n";
	cout << left << setw(25) << "Title" << left << setw(25) << "Author" << left << setw(20) << "ISBN" << left << setw(15) << "Rig. ID"
		<< left << setw(10) << "Copies" << left << setw(15) << "Available" << left << setw(15) << "Status" << endl;
	for (int i = 0; i < Mypvec.size(); i++){
		if (Mypvec[i].bStatus == Mysts){
			cout << left << setw(25) << Mypvec[i].title << left << setw(25) << Mypvec[i].author << left << setw(20) << Mypvec[i].isbn
				<< left << setw(15) << Mypvec[i].rig_ID << left << setw(10) << Mypvec[i].copies << left << setw(15) << Mypvec[i].available;
			if (Mypvec[i].bStatus == 0){
				cout << left << setw(15) << "CHECKED_OUT" << endl;
			}
			else{
				cout << left << setw(15) << "ON_SHELF" << endl;
			}
		}
	}
}


void sortByTitle(vector<BookInfo> Myvec){
	// use selection sorting algorithm to sort the copyarray by title
	int startScan;
	int minIndex;
	string minTitle;
	BookInfo minValue;
	for (startScan = 0; startScan < Myvec.size() - 1; startScan++){
		minIndex = startScan;
		minTitle = Myvec[startScan].title;
		minValue = Myvec[startScan];
		for (int index = startScan + 1; index < Myvec.size(); index++){
			if (Myvec[index].title < minTitle){
				minTitle = Myvec[index].title;
				minIndex = index;
				minValue = Myvec[index];
			}
		}
		Myvec[minIndex] = Myvec[startScan];
		Myvec[startScan] = minValue;
	}
	// display result on screen
	cout << "\nFollowing displays the book collections sorted by title:\n";
	cout << left << setw(25) << "Title" << left << setw(25) << "Author" << left << setw(20) << "ISBN" << left << setw(15) << "Rig. ID"
		<< left << setw(10) << "Copies" << left << setw(15) << "Available" << left << setw(15) << "Status" << endl;
	for (int j = 0; j < Myvec.size(); j++){
		cout << left << setw(25) << Myvec[j].title << setw(25) << Myvec[j].author << setw(20) << Myvec[j].isbn
			<< left << setw(15) << Myvec[j].rig_ID << setw(10) << Myvec[j].copies << setw(15) << Myvec[j].available;
		if (Myvec[j].bStatus == 0){
			cout << left << setw(15) << "CHECKED_OUT" << endl;
		}
		else{
			cout << left << setw(15) << "ON_SHELF" << endl;
		}
	}

}


void sortByAuthor(vector<BookInfo> Myvec){
	// use selection sorting algorithm to sort the copyarray by title
	int startScan;
	int minIndex;
	string minAuthor;
	BookInfo minValue;
	for (startScan = 0; startScan < Myvec.size() - 1; startScan++){
		minIndex = startScan;
		minAuthor = Myvec[startScan].author;
		minValue = Myvec[startScan];
		for (int index = startScan + 1; index < Myvec.size(); index++){
			if (Myvec[index].author < minAuthor){
				minAuthor = Myvec[index].author;
				minIndex = index;
				minValue = Myvec[index];
			}
		}
		Myvec[minIndex] = Myvec[startScan];
		Myvec[startScan] = minValue;
	}
	// display result on screen
	cout << "\nFollowing displays the book collections sorted by author:\n";
	cout << left << setw(25) << "Title" << left << setw(25) << "Author" << left << setw(20) << "ISBN" << left << setw(15) << "Rig. ID"
		<< left << setw(10) << "Copies" << left << setw(15) << "Available" << left << setw(15) << "Status" << endl;
	for (int j = 0; j < Myvec.size(); j++){
		cout << left << setw(25) << Myvec[j].title << setw(25) << Myvec[j].author << setw(20) << Myvec[j].isbn
			<< left << setw(15) << Myvec[j].rig_ID << setw(10) << Myvec[j].copies << setw(15) << Myvec[j].available;
		if (Myvec[j].bStatus == 0){
			cout << left << setw(15) << "CHECKED_OUT" << endl;
		}
		else{
			cout << left << setw(15) << "ON_SHELF" << endl;
		}
	}

}

