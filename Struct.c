/* Becca Billman, Struct ,COP 3223C, CR02, 07/22/2018*/

//Pre-processor directives
#include <stdio.h>

//have to declare so that the program knows this function exists
struct hotel_room{

int hotel_roomNumber;

int numbpeople;

int bookedpeople;

};
  //section for guest 
    int get_Total_Guest(struct hotel_room hotel[10]){
    int i;
    int total11 =0;
    for(i=0;i<10;i++){
    if(hotel[i].bookedpeople==1)
    total11+=hotel[i].numbpeople;
}

return total11;

}

void Checkin(struct hotel_room hotel[10]){
//section for room number 
    int hotel_roomNumber;
    //ask user to enter room number they would like 
    printf("Enter hotel_room number : ");
    scanf("%d",&hotel_roomNumber);
    if(hotel_roomNumber<0 || hotel_roomNumber>10){
        //if room doesnt exist i.e. over 10 print out 
        printf("hotel_room doesn't exist!!!\n");

return;

}
    //section for number of people in the room 
    if(hotel[hotel_roomNumber-1].bookedpeople==0){
    hotel[hotel_roomNumber-1].bookedpeople =1;
    
    //ask user to enter number of people in the room 
    printf("Enter number of people : ");
    scanf("%d",&hotel[hotel_roomNumber-1].numbpeople);
    
    //print when booking works 
    printf("room booked successfully.\n");

}else{
    //print if the room is already taken 
    printf("room is already booked!!!\n");

}


}
   //section for check out 
    void CheckOut(struct hotel_room hotel[10]){
    int hotel_roomNumber;
    
    //ask user to enter number 
    printf("Enter hotel_room number : ");
    scanf("%d",&hotel_roomNumber);
    if(hotel_roomNumber<0 || hotel_roomNumber>10){

    //print if the number is over 10 
    printf("hotel_room doesn't exist!!!\n");

return;

}

    if(hotel[hotel_roomNumber-1].bookedpeople==0){
    //print if the room is open 
    printf("room is not booked yet!!!\n");

}else{

    hotel[hotel_roomNumber-1].bookedpeople =0;
    hotel[hotel_roomNumber-1].numbpeople =0;
    
    //print when they check out 
    printf("Check-out successfully.\n");

}

}
    //availablity section 
    void print(struct hotel_room hotel[10]){
        
    //show what rooms are still open 
    printf("Following rooms are available for booking\n");
    int i;
    for(i=0;i<10;i++){
    if(hotel[i].bookedpeople==0){

    //print a list of rooms not booked
    printf("hotel_room number %d\n",i+1);

}

}

}
 //Main Function
int main()

{

//variable declarations
int hotel_roomNumber;
struct hotel_room hotel[10];
int i;
for(i=0;i<10;i++){


hotel[i].hotel_roomNumber = i+1;

hotel[i].bookedpeople = 0;

hotel[i].numbpeople=0;

}

//While loop
while(1){

//Print the list 
printf("1) To check in (enter: 1)\n"
"2) To check out (enter 2)\n"
"3) To print availability (enter: 3)\n"
"4) To quit (enter: 4)");

printf("\nPlease enter the option : ");

int option;

scanf("%d",&option);

//if elese loop
if(option==1){

Checkin(hotel);

}else if(option==2){

CheckOut(hotel);

}else if(option==3){

print(hotel);

}else if(option==4){

break;

}
//to give space to see new section 
printf("\n");

}
//End of main 
return 0;

}

