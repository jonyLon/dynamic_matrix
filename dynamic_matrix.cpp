#include <iostream>
#include <string>
using namespace std;
int** createMatrix(const int& row, const int& col) {
	int** arr = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}
	return arr;
}
string** createMatrix(const int& row, const int& col, bool isStr) {
	string** arr = new string* [row];
	for (size_t i = 0; i < row; i++)
	{
		arr[i] = new string[col];
	}
	return arr;
}
void print(int** arr, const int& row, const int& col) {
	for (size_t i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void fill(int** arr, const int& row, const int& col, int min = 1, int max = 30) {
	for (size_t i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			arr[i][j] = min + rand() % (max - min + 1);
		}
	}
}
void matrixTransposition(int**& arr, int &row, int &col) {
	int** tmp = createMatrix(col, row);
	for (size_t r = 0; r < row; r++)
	{
		for (size_t c = 0; c < col; c++) {
			tmp[c][r] = arr[r][c];
		}
		delete[]arr[r];
	}
	delete[]arr;
	int rtmp = row;
	row = col;
	col = rtmp;
	arr = tmp;
}




void addRecord(string** &arr, int index, string New = "") {
	string name, number;
	cout << "Enter person's " << New << " name: ";
	cin >> name;
	cout << "Enter person's " << New << " phone number: ";
	cin >> number;
	arr[0][index] = name;
	arr[1][index] = number;
	cout << endl;
}
void printRecords(string** arr, const int& col) {
	for (size_t i = 0; i < col; i++)
	{
		cout << "Name: " << arr[0][i] << "\tPhone number: " << arr[1][i] << endl;
	}
}
void printRecord(string** arr, const int& col) {
		cout << "Name: " << arr[0][col] << "\tPhone number: " << arr[1][col] << endl;
}
void editRecord(string** arr, const int& col) {
	addRecord(arr, col, "new");
}
int searchRecord(string** arr, const int& col, string key, bool isName) {
	int row = 1;
	if (isName) {
		row = 0;
	}
	for (int i = 0; i < col; i++)
	{
		if (arr[row][i] == key) {
			return i;
		}
	}
	return -1;
}


int main()
{
 //   int row = 4, col = 8;
	//int** Matrix = createMatrix(row, col);
	//fill(Matrix, row, col);
	//print(Matrix, row, col);
	//matrixTransposition(Matrix, row, col);
	//print(Matrix, row, col);

	const int rows = 2;
	int records, index;
	cout << "Enter amount of records you wish to add: ";
	cin >> records;
	string** Records = createMatrix(rows, records, true);
	for (int i = 0; i < records; i++)
	{
		addRecord(Records, i);
	}
	cout << "Enter index of record you wish to edit: ";
	cin >> index;
	editRecord(Records, index);

	printRecords(Records, records);
	bool isName;
	string searchVal;
	cout << "Enter 1 if you want to search by name or 0 for search by phone: ";
	cin >> isName;
	cout << "Enter search value: ";
	cin >> searchVal;
	int recInd = searchRecord(Records, records, searchVal, isName);
	cout << recInd << endl;
	if (recInd != -1) {
		printRecord(Records, recInd);
	}
	
}

