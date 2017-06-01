#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Set global constants for number of rows and columns
const int ROWS_DIVS = 5;
const int COLS_QTRS = 5;

void fillArray(string divNames[], int fillTable[][COLS_QTRS], int DIVS, int QTRS);
int getTotal(int[][COLS_QTRS]);
int getAverage(int[][COLS_QTRS]);
int getRowTotal(int[][COLS_QTRS], int);
int getColumnTotal(int[][COLS_QTRS], int);
int getHighest(int[][COLS_QTRS], int&, int&);
int getLowest(int[][COLS_QTRS], int&, int&);
void showArray(string divNames[], int fillTable[][COLS_QTRS], int DIVS, int QTRS, int arrayTotal, int arrayAverage, int highestRow, int highestColumn, int lowestRow, int lowestColumn, int highestValue, int lowestValue);

int main()
{
	//Define the array to hold the division names
	string divisionNames[5] = { "North", "South", "East", "West", "Qtr Totals" };

	//Define the array to hold the sales figures
	int table[ROWS_DIVS][COLS_QTRS];

	//Define variables to hold the totals, average, highest, and lowest figures.
	int arrayTotal;		//Total for the entire array
	int arrayAverage;	//To hold the average for the entire array

	//Define variables to hold row/division totals
	int northDivisionTotal, southDivisionTotal, eastDivisionTotal, westDivisionTotal;

	//Define variables to hold column/quarter totals
	int firstQuarterTotal, secondQuarterTotal, thirdQuarterTotal, fourthQuarterTotal;

	//Define variables to hold the highest and lowest values.
	int highestValue, lowestValue;

	//Define variables to hold the locations of the highest and lowest numbers in the array.
	int highestRow, highestColumn, lowestRow, lowestColumn;

	//Explain what the program is supposed to do.
	cout << "This program creates a table containing sales information for\n"
		<< "four divisions: North, South, East, and West, for four quarters.\n\n";
	cout << "It will also calculate the total sales, average sales, and the\n"
		<< "highest and lowest sales values you have entered.\n\n";

	//Ask the user to input values for the entire array except the totals in the last column and row.
	fillArray(divisionNames, table, ROWS_DIVS, COLS_QTRS);

	//Get the total for all the sales figures entered by the user
	arrayTotal = getTotal(table);

	//Get the average of the sales figures entered by the user
	arrayAverage = getAverage(table);

	//Get the row totals for each of the divisions, and input them into the table.
	northDivisionTotal = getRowTotal(table, 0);
	southDivisionTotal = getRowTotal(table, 1);
	eastDivisionTotal = getRowTotal(table, 2);
	westDivisionTotal = getRowTotal(table, 3);

	//Set the last element of each row to equal the division totals calculated above.
	table[0][4] = northDivisionTotal;
	table[1][4] = southDivisionTotal;
	table[2][4] = eastDivisionTotal;
	table[3][4] = westDivisionTotal;

	//Get the column totals for each of the quarters, and input them into the table.
	firstQuarterTotal = getColumnTotal(table, 0);
	secondQuarterTotal = getColumnTotal(table, 1);
	thirdQuarterTotal = getColumnTotal(table, 2);
	fourthQuarterTotal = getColumnTotal(table, 3);

	//Set the last element of each column to equal the quarter totals calculated above.
	table[4][0] = firstQuarterTotal;
	table[4][1] = secondQuarterTotal;
	table[4][2] = thirdQuarterTotal;
	table[4][3] = fourthQuarterTotal;

	//Set the very bottom right corner of the table to the total for all the sales figures.
	table[4][4] = arrayTotal;

	//Get the highest value entered by the user.
	highestValue = getHighest(table, highestRow, highestColumn);

	//Get the lowest value entered by the user.
	lowestValue = getLowest(table, lowestRow, lowestColumn);

	//Show the user the information about the sales figures they have entered
	showArray(divisionNames, table, ROWS_DIVS, COLS_QTRS, arrayTotal, arrayAverage, highestRow, highestColumn, lowestRow, lowestColumn, highestValue, lowestValue);

	//Show the user the numbers calculated given the information they provided.

	system("PAUSE");
	return 0;
}

void fillArray(string divNames[], int fillTable[][COLS_QTRS], int DIVS, int QTRS)
{
	cout << "Please enter the sales information now:\n\n";

	for (int index = 0; index < (DIVS - 1); index++)
	{
		for (int count = 0; count < (QTRS - 1); count++)
		{
			cout << divNames[index] << ", Quarter " << (count + 1) << ": $";
			cin >> fillTable[index][count];
		}
	}
}

int getTotal(int totalTable[][COLS_QTRS])
{
	//Define an accumulator to hold the total
	int arrayTotal = 0;

	for (int index = 0; index < (ROWS_DIVS - 1); index++)
	{
		for (int count = 0; count < (COLS_QTRS - 1); count++)
		{
			arrayTotal += totalTable[index][count];
		}
	}

	return arrayTotal;
}

int getAverage(int averageTable[][COLS_QTRS])
{
	//Define an accumulator to hold the total
	int arrayTotal = 0;

	//Define a variable to hold the average
	int arrayAverage;

	//Start by getting the array total
	for (int index = 0; index < (ROWS_DIVS - 1); index++)
	{
		for (int count = 0; count < (COLS_QTRS - 1); count++)
		{
			arrayTotal += averageTable[index][count];
		}
	}

	//Calculate the average
	arrayAverage = arrayTotal / ((ROWS_DIVS - 1) * (COLS_QTRS - 1));

	return arrayAverage;
}

int getRowTotal(int rowTotalTable[][COLS_QTRS], int ROW)
{
	//Define an accumulator variable for the row total
	int rowTotal = 0;

	for (int index = 0; index < (COLS_QTRS - 1); index++)
	{
		rowTotal += rowTotalTable[ROW][index];
	}

	return rowTotal;
}

int getColumnTotal(int columnTotalTable[][COLS_QTRS], int COLUMN)
{
	//Define an accumulator variable for the column total
	int columnTotal = 0;

	for (int index = 0; index < (ROWS_DIVS - 1); index++)
	{
		columnTotal += columnTotalTable[index][COLUMN];
	}

	return columnTotal;
}

int getHighest(int highestTable[][COLS_QTRS], int &highestRow, int &highestColumn)
{
	//Initialize all the variables.
	highestRow = 0;
	highestColumn = 0;
	int highestValue = highestTable[0][0];

	for (int index = 0; index < (ROWS_DIVS - 1); index++)
	{
		for (int count = 0; count < (COLS_QTRS - 1); count++)
		{
			if (highestTable[index][count] > highestValue)
			{
				highestValue = highestTable[index][count];
				highestRow = index;
				highestColumn = count;
			}
		}
	}

	return highestValue;
}

int getLowest(int lowestTable[][COLS_QTRS], int &lowestRow, int &lowestColumn)
{
	//Initialize all the variables.
	lowestRow = 0;
	lowestColumn = 0;
	int lowestValue = lowestTable[0][0];

	for (int index = 0; index < (ROWS_DIVS - 1); index++)
	{
		for (int count = 0; count < (COLS_QTRS - 1); count++)
		{
			if (lowestTable[index][count] < lowestValue)
			{
				lowestValue = lowestTable[index][count];
				lowestRow = index;
				lowestColumn = count;
			}
		}
	}

	return lowestValue;
}

void showArray(string divNames[], int fillTable[][COLS_QTRS], int DIVS, int QTRS, int arrayTotal, int arrayAverage, int highestRow, int highestColumn, int lowestRow, int lowestColumn, int highestValue, int lowestValue)
{
	cout << "\nHere is the information you have entered.\n\n";
	
	cout << setw(12) << right << " ";
	for (int index = 0; index < (QTRS - 1); index++)
		cout << setw(12) << right << "Quarter " << (index + 1);
	cout << setw(12) << right << "Div Total";
	cout << endl;

	for (int index = 0; index < (DIVS); index++)
	{
		cout << setw(12) << right << divNames[index];
		for (int count = 0; count < (QTRS); count++)
		{
			cout << setw(12) << right << fillTable[index][count] << " ";
		}
		cout << endl << endl;
	}

	//Display the total for the entire array for the user.
	cout << "The total for all the sales figures you entered is $" << arrayTotal << ".";
	cout << endl;

	//Display the average for the entire array for the user.
	cout << "The average for all the sales figures you entered is $" << arrayAverage << ".";
	cout << endl;

	//Display the quarter for the highest sales.
	cout << "The highest sales figure of $" << highestValue << " occurred in " << divNames[highestRow] << " Division, in Quarter " << (highestColumn + 1);
	cout << endl;

	//Display the quarter for the lowest sales.
	cout << "The lowest sales figure of $" << lowestValue << " occurred in " << divNames[lowestRow] << " Division, in Quarter " << (lowestColumn + 1);
	cout << endl << endl;
}