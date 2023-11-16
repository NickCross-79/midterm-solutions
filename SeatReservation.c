#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Define a struct type, Seat, with required members.             (4 marks)
/***************************************************/
typedef struct Seat_struct{
   char *firstName[50];
   char *lastName[50];
   int amountPaid;
}Seat;

// Funciton prototypes
void ReserveSeat(Seat seats[],int seatNum, Seat seat);
void MakeSeatEmpty(Seat* seat);
bool IsSeatEmpty(Seat seat);
void PrintSeat(Seat seat);
void MakeAllEmpty(Seat seats[], int numSeats);
void PrintAll(Seat seats[], int numSeats);

int main(void) {
   const int NUM_SEATS = 5;
   char userKey;
   int  seatNum;
   Seat allSeats[NUM_SEATS];
   Seat currSeat;
   userKey = '-';
   seatNum = 0;

   // Empty all the seats                                       (2 marks)
   /*********************/
   MakeAllEmpty(allSeats, NUM_SEATS);


   while (toupper(userKey) != 'Q') {
      printf("Enter command ((P)rint/(R)eserve/(E)mpty/(Q)uit): \n");
      scanf(" %c", &userKey);
      
      if (toupper(userKey) == 'P') { 

         // Print all the seats                                 (2 marks)
         /*********************/
         for(int i = 0; i < NUM_SEATS; i++){
            PrintSeat(allSeats[i]);
         }
         
      }
      else if (toupper(userKey) == 'R') { 
         printf("Enter seat num: \n");
         scanf("%d", &seatNum);
         if (seatNum <=0 || seatNum>NUM_SEATS)
            printf("Invalid seat number!\n");
         else if (!IsSeatEmpty(allSeats[seatNum-1]))
            printf("Seat has already been reserved by someone.\n\n");
         else {
            printf("Enter first name: \n");
            scanf("%s", currSeat.firstName);
            printf("Enter last name: \n");
            scanf("%s", currSeat.lastName);
            printf("Enter amount paid: \n");
            scanf("%d", &currSeat.amountPaid);

            // Reserve the seat                                (2 marks)
            /******************/
            ReserveSeat(allSeats, seatNum, currSeat);

            printf("Seat Reserved.\n\n");
         }
      }
      else if (toupper(userKey) == 'E') { 
         printf("Enter seat num: \n");
         scanf("%d", &seatNum);
	      if (IsSeatEmpty(allSeats[seatNum-1]))
            printf("Seat is already empty.\n\n");
         else if (seatNum >0 && seatNum<=NUM_SEATS){
            MakeSeatEmpty(&allSeats[seatNum - 1]);
         }

            // Make the selected seat empty                    (2 marks)
            /******************************/


         else
            printf("Invalid seat number!\n");
      }         
      else if (toupper(userKey) == 'Q')
         printf("Goodbye...!\n");
      else
         printf("Invalid command.\n\n");
   }
   return 0;
}

// Implement the functions below.
/********************************/

// Reserve a seat                                      (2 marks)
void ReserveSeat(Seat seats[],int seatNum, Seat seat) {
   seats[seatNum - 1] = seat;

}

// Make one seat empty                                 (4 marks)
void MakeSeatEmpty(Seat* seat) {
   strcpy(seat->firstName,"empty");
   strcpy(seat->lastName,"empty");
   seat->amountPaid = 0;
}

// Make all seats empty using MakeSeatEmpty function   (3 marks)
void MakeAllEmpty(Seat seats[], int numSeats) {
   for(int i = 0; i < numSeats; i++){
      MakeSeatEmpty(&seats[i]);
   }
}

// Check if a seat is  empty                           (2 marks)
bool IsSeatEmpty(Seat seat) {
   if(strcmp(seat.firstName,"empty") == 0) return 1;
   return 0;
}

// Print a seat                                        (4 marks)
void PrintSeat(Seat seat) {
   printf("%s %s, Paid: %d\n", seat.firstName, seat.lastName, seat.amountPaid);
}

// Print all seats using PrintSeat function            (3 marks)
void PrintAll(Seat seats[], int numSeats) {
   for(int i = 0; i < numSeats; i++){
      PrintSeat(seats[i]);
   }
}
