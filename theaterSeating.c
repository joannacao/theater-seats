#include <stdio.h>

void displaySeatingChart(char arr[][30]); //displays seating chart
void sellTickets(char array[][30], float price[15], int row, int column, float *tSales);
//the above is a function to sell a ticket and update the seating chart and totalSale accordingly
void seatStats(char arr[][30]); //functions that returns info about seats
int seatsSold(char arr[][30]); //returns the number of seats sold
int rowSeatsLeft(char arr[][30], int row); //returns the number of seats available in an indicated row
int answer; //variable for user input

int main(){
	char auditorium[15][30]; //creates seating chart
	float price[15]; //empty list that will contain prices per row
	float totalSales = 0.0; //the total amount of money made from selling seats
	int row = 0, column = 0; //row and column variable to iterate through the seating chart

	for (int r = 0; r < 15; r++){ //initializes auditorium to having empty seats
		for (int c = 0; c < 30; c++){
			auditorium[r][c] = '*';
		}
	}

	printf("Enter the seat prices by row: "); //allows user to indicate row prices
	while (row < 15){
		printf("\nRow %d: ", row+1);
		fflush(stdout);
		scanf("%f", &price[row]);
		row++;
	}

	displaySeatingChart(auditorium); //displays the current seating chart (should be empty)

	while(answer != 4){ //keeps looping until user wants to quit
		printf("\nWould you like to: "); //options
		printf("\n1) Enter a sold ticket");
		printf("\n2) Check the total sale of tickets");
		printf("\n3) Check how many seats were sold and current seat availability");
		printf("\n4) Quit");
		printf("\nChoose 1-4: ");
		fflush(stdout);
		scanf("%d", &answer); //input choice
		if (answer == 1){
			printf("Enter the row number of the seat: ");
			fflush(stdout);
			scanf("%d", &row); //input row number of seat sold
			while (row < 1 || row > 15){ //input validation
				printf("\nThis row does not exist. Please enter 1-15: ");
				fflush(stdout);
				scanf("%d", &row);
			}
			printf("Enter the column number of the seat: ");
			fflush(stdout);
			scanf("%d", &column); //input column number of seat sold
			while (column < 1 || column > 30){ //input validation
				printf("\nThis row does not exist. Please enter 1-30: ");
				fflush(stdout);
				scanf("%d", &column);
			}
			sellTickets(auditorium, price, row, column, &totalSales); //updates
			displaySeatingChart(auditorium); //displays seating chart to indicate sold ticket
		} else if (answer == 2){
			printf("The total sales for seats is $%f.", totalSales); //prints out totalSales
		} else if (answer == 3){
			seatStats(auditorium); //prints seat stats
		} else {
			break;
		}
	}

	printf("Thank you!");

	return 0;
}

void displaySeatingChart(char arr[][30]){ //prints out seating chart by iterating throug	
	printf("                      Seats\n"); //the rows
	printf("          123456789012345678901234567890\n"); //labels the columns
	for (int r = 1; r < 16; r++){
		if (r < 10){
			printf("Row %d     ", r); //labels the row
		} else {
			printf("Row %d    ", r);
		}
		for (int c = 1; c < 31; c++){
			printf("%c", arr[r-1][c-1]); //print out the seat
		} //(whether it's available or not)
		printf("\n");
	}
	printf("\n");
}

void sellTickets(char array[][30], float price[15], int row, int column, float *totalSales){
	array[row-1][column-1] = '#'; //marks the seat in that row and column as unavailable
	*totalSales = *totalSales + price[row-1]; //adds the price of that seats to totalSales
}

int seatsSold(char arr[][30]){
	int numOfSeats = 0; //creates and initializes numOfSeats to 0
	for (int r = 0; r < 15; r++){
		for (int c = 0; c < 30; c++){
			if (arr[r][c] == '#'){ //if an element in the seating chart has a "#"
				numOfSeats++; //increments the sold seats
			}
		}
	}
	return numOfSeats;
}

void seatStats(char arr[][30]){
	int seatSold = seatsSold(arr); //stores the int returned from seatsSold()
	int allSeatsLeft = (15*30) - seatSold; //available seats is total seats - the seats sold
	printf("We have sold %d seats.", seatSold); //prints the sold seats
	printf("\nThe total number of seats left is %d.", allSeatsLeft); //prints available seats
	for (int rows = 0; rows < 15; rows++){ //iterates through all the rows
		int seatsLeft = 0;
		seatsLeft += rowSeatsLeft(arr, rows); //finds the seats left in each row
		printf("\nThere are %d seats left in row %d.", seatsLeft, rows+1); //prints out the seats left in that row
	}
}

int rowSeatsLeft(char arr[][30], int row){
	int rowSeats = 0;
	for (int c = 0; c < 30; c++){
		if (arr[row][c] == '*'){ //checks the indicated row for any available seats
			rowSeats++; //increments if it finds an available seats
		}
	}

	return rowSeats;
}




