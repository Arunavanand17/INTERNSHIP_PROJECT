//workflow:
//1. making the box function modular to it's level best
//2.implementation of color

//3.using animations and transitions in switching phase or display phase
//4.use of graphics.h to show how list is formed;
//5.complete the project making it more dynamic
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
int isAnimated = 1;
void horizontalline(int x1,int y1,int x2,int y2);
void corners(int x1,int y1,int x2,int y2);
void jointers(int x1,int y1,int x2,int y2);
void verticalline(int x1,int y1,int x2,int y2);
void box(int x1,int y1,int x2, int y2,int y3,int y4);
void typetext(int x,int y,char *text,int color);
void loadingscreen();
void exitscreen();
void visualizedLinkedList();

void exitscreen(){
	int i;
	clrscr();
	textbackground(BLACK);
	box(10,5,70,7,20,22);
	gotoxy(30,6);
	textcolor(YELLOW);
	cprintf("SYSTEM EXIT SEQUENCE");
	gotoxy(25,12);
	textcolor(LIGHTCYAN);
	cprintf("Closing Database Modules...");



	gotoxy(20,14);cprintf("[");
	gotoxy(61,14);cprintf("]");

	textcolor(RED);
	for(i=0;i<40;i++) {
		gotoxy(21+i,14);
		cprintf("%c", 219);

		gotoxy(38,16);
		textcolor(WHITE);
		cprintf("%d%%", (i*100)/39);

		textcolor(RED);
		delay(60);
	}
	gotoxy(25,18);
	textcolor(YELLOW);
	cprintf("Exit ready !Press any key...");

	fflush(stdin);
	getch();
	}
void loadingscreen() {
	int i;
	clrscr();
	textbackground(BLACK);
	box(10,5,70,7,20,22);
	gotoxy(30,6);
	textcolor(YELLOW);
	cprintf("SYSTEM BOOT SEQUENCE");
	gotoxy(25,12);
	textcolor(LIGHTCYAN);
	cprintf("Loading Database Modules...");


	gotoxy(20,14);cprintf("[");
	gotoxy(61,14);cprintf("]");

	textcolor(LIGHTGREEN);
	for(i=0;i<40;i++) {
		gotoxy(21+i,14);
		cprintf("%c", 219);

		gotoxy(38,16);
		textcolor(WHITE);
		cprintf("%d%%", (i*100)/39);

		textcolor(LIGHTGREEN);
		delay(60);
	}
	gotoxy(25,18);
	textcolor(YELLOW);
	cprintf("Boot Complete!Press any key...");

	fflush(stdin);
	getch();
	isAnimated=0;
}
void typetext(int x,int y,char *text,int color){
	int i=0;
	gotoxy(x,y);
	textcolor(color);
	while(text[i]!='\0' ){
		cprintf("%c", text[i]);
		delay(40);
		i++;
	}
}
void horizontalline(int x1,int y1,int x2,int y2){
	int i;
	int j;
	textcolor(LIGHTCYAN);
	for(i=x1+1;i<x2;i++){
		gotoxy(i,y1);cprintf("%c",205);
		if(isAnimated == 1){

			delay(15);
			}
		}
	for(j=x1+1;j<x2;j++){
		gotoxy(j,y2);cprintf("%c",205);
		if(isAnimated==1){

			delay(15);
			}
		}


	}

void verticalline(int x1,int y1,int x2, int y2){
	int l;
	int k;
	textcolor(LIGHTCYAN);

	for(l=y1+1;l<y2;l++){
		gotoxy(x1,l);cprintf("%c",186);
		if(isAnimated==1){

			delay(20);
			}
		}
	for(k=y1+1;k<y2;k++){
		gotoxy(x2,k);cprintf("%c",186);
		if(isAnimated==1){

			delay(20);
			}
		}
	}
void corners(int x1,int y1,int x2,int y2){
	textcolor(LIGHTCYAN);
	gotoxy(x1,y1);cprintf("%c",201);
	gotoxy(x2,y2);cprintf("%c",188);
	gotoxy(x1,y2);cprintf("%c",200);
	gotoxy(x2,y1);cprintf("%c",187);
	}

void jointers(int x1,int y1,int x2,int y2){
	textcolor(LIGHTCYAN);

	gotoxy(x1,y1);cprintf("%c",204);
	gotoxy(x2,y1);cprintf("%c",185);
	gotoxy(x1,y2);cprintf("%c",204);
	gotoxy(x2,y2);cprintf("%c",185);
	}
void box(int x1,int y1,int x2,int y2,int y3,int y4){

	corners(x1,y1,x2,y4);
	horizontalline(x1,y1,x2,y2);

	horizontalline(x1,y3,x2,y4);
	verticalline(x1,y1,x2,y4);
	jointers(x1,y2,x2,y3);

}
//task1 completed made the box layout modular
//now i m thinking of making the whole layout and  then put animations
//colors and graphics  into it.
// now making the logical part

struct StudentDetails {
	char name[20];
	int roll;
	struct StudentDetails *prev;
	struct StudentDetails *next;
	};

struct StudentDetails *head = NULL;


//add record function
void addrecord() {
	int duplicateFound = 0;
	int choice;
	struct StudentDetails *newDetail = (struct StudentDetails *)malloc(sizeof(struct StudentDetails));
	struct StudentDetails *checker = head;

	if(newDetail==NULL) {
		printf("\nMemory allocation failed!\n");
		return;
		}
	clrscr();
	box(10,5,70,7,20,22);
	gotoxy(25,6);printf("Enter Student Details");
	gotoxy(15,9);printf("Enter name : ");
	fflush(stdin);
       //	scanf("%[ ^\n]", newDetail->name);
       gets(newDetail->name);
	gotoxy(15,10);printf("Enter Roll Number : ");
	scanf("%d", &newDetail->roll);
	//checking for duplicate entry
	while(checker!=NULL) {
		if(checker->roll==newDetail->roll)
		{
			duplicateFound = 1;
			break;
		}
			checker=checker->next;
		}
		if(duplicateFound==1) {
			gotoxy(15,23);
			textcolor(LIGHTRED);
			cprintf("No duplicated entry allowed");
			textcolor(WHITE);
			free(newDetail);
			gotoxy(1,24);
			getch();
			return;
			}

	newDetail->prev=NULL;
	newDetail->next=NULL;


	if(head==NULL) {
		head=newDetail;
		gotoxy(15,23);printf("List was empty!Record added");
		gotoxy(1,25);getch();
		return;
		}

	gotoxy(15,13);printf("1. Insert at Beginning");
	gotoxy(15,14);printf("2. Insert at End");
	gotoxy(15,15);printf("3. Insert after a specific roll number : ");
	gotoxy(15,16);printf("4. Insert before a specific roll number : ");
	gotoxy(15,18);printf("Enter your Choice : ");
	fflush(stdin);
	scanf("%d", &choice);

	switch(choice) {
		case 1:
		{
			newDetail->next=head;
			head->prev=newDetail;
			head=newDetail;
			gotoxy(15,23);printf("Record added at the beginning");
			break;
		}

		case 2:
		{
			struct StudentDetails *temp = head;
			while(temp->next!=NULL){
				temp=temp->next;
				}
			temp->next = newDetail;
			newDetail->prev=temp;
			gotoxy(15,23);printf("Record added at the end");
			break;
		}

		case 3:
		{
			int targetroll;
			struct StudentDetails *searchTemp = head;
			gotoxy(15,21);printf("Enter the target roll here : ");
			scanf("%d", &targetroll);

			while(searchTemp!=NULL && searchTemp->roll!=targetroll){
				searchTemp=searchTemp->next;
				}
			if(searchTemp==NULL){
				gotoxy(15,23);printf("Roll number not found!Failed");
				free(newDetail);
				}
			else{
				newDetail->next = searchTemp->next;
				newDetail->prev = searchTemp;
				if(searchTemp->next != NULL) {
					searchTemp->next->prev = newDetail;
					}
				searchTemp->next = newDetail;
				gotoxy(15,23);printf("Record added sucessfully!");
				}
				break;
			}

		case 4:
		{
			int targetroll;
			struct StudentDetails *searchTemp = head;
			gotoxy(15,21);printf("Enter target roll here :");
			scanf("%d", &targetroll);
			if(head->roll == targetroll) {
				newDetail->next=head;
				head->prev=newDetail;
				head= newDetail;
				gotoxy(15,23);printf("Record added successfully.");
				break;
			}
			while(searchTemp->next!= NULL && searchTemp->next->roll!=targetroll){
				searchTemp=searchTemp->next;
				}
			if(searchTemp->next == NULL){
				gotoxy(15,23);printf("Roll number not found!Failed.");
				free(newDetail);
				}
			else{
				newDetail->next= searchTemp->next;
				newDetail->prev=searchTemp;
				searchTemp->next->prev=newDetail;
				searchTemp->next=newDetail;
				gotoxy(15,23);printf("Record added successfully");
				}
				break;
			}

		default:
			gotoxy(15,21);printf("Invaild choice!Record discarded.");
			free(newDetail);
			break;
		}
		gotoxy(1,24);getch();
	}
void displayrecords() {

		int y =9;
		struct StudentDetails *temp = head;
		clrscr();
		box(10,5,70,7,20,22);
		gotoxy(25,6);printf("ALL STUDENT RECORDS");

		if(head==NULL) {
			gotoxy(15,12);printf("No reeords found! The list is empty");
			gotoxy(1,24);getch();
			return;
			}
		while(temp!=NULL && y<18){
			gotoxy(15,y);printf("Name: %s | Roll: %d |", temp->name, temp->roll);
			temp=temp->next;
			y+=2;
			}
		gotoxy(15,21);printf("Press any key to return");
		gotoxy(1,24);getch();

		}
void searchroll() {
	int userroll;
	int found = 0;
	struct StudentDetails *temp = head;
	clrscr();
	box(10,5,70,7,20,22);
	gotoxy(28,6);printf("Search Record");

	if(head==NULL){
		gotoxy(15,12);printf("No Student Record was found!");
		gotoxy(1,24);getch();
		return;
		}
	gotoxy(15,10);printf("Enter roll number to search :");
	scanf("%d", &userroll);

	while(temp!=NULL) {
		if(temp->roll==userroll) {
			gotoxy(15,13);printf("---Record Found---");
			gotoxy(15,14);printf("Name : %s", temp->name);
			gotoxy(15,15);printf("Roll : %d", temp->roll);
			found=1;
			break;
			}
		temp=temp->next;
	}
	if(found==0){
		gotoxy(15,14);printf("Roll Number %d is not present.", userroll);
		}
	gotoxy(1,24);getch();
}


void deleterecords() {

	int uniqueid;
	struct StudentDetails *temp = head;
	clrscr();
	box(10,5,70,7,20,22);
	gotoxy(28,6);printf("Delete Record");

	if(head==NULL) {
		gotoxy(15,12);printf("There is no data nothing to delete");
		gotoxy(1,24);getch();
		return;
	}
	gotoxy(15,10);printf("Enter roll number to delete : ");
	scanf("%d", &uniqueid);

	if(temp->roll==uniqueid) {
		head=temp->next;
		if(head!=NULL) {
			head->prev = NULL;
		}
		free(temp);
		gotoxy(15,14);printf("Record has been sucessfully deleted");
		gotoxy(1,24);getch();
		return;
		}
	while(temp!=NULL && temp->roll != uniqueid) {
		temp=temp->next;
		}
	if(temp==NULL) {
		gotoxy(15,14);printf("No record was found");
		}
		else{
			if(temp->next==NULL) {
				temp->prev->next=NULL;
				}
			else{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				}
				free(temp);
				gotoxy(15,14);printf("Record has been successfully deleted.");
			}
			gotoxy(1,24);getch();
		}
void displaymainmenu() {
	int input;
	while(1){
		textbackground(BLACK);
		textcolor(WHITE);
		clrscr();
		box(10,5,70,7,20,22);
	       //gotoxy(35,6);printf("MAIN MENU");
	       typetext(32,6,"STUDENT RECORD SYSTEM", YELLOW);
	       textcolor(WHITE);
		gotoxy(15,9);cprintf("1. Enter Student Record");
		gotoxy(15,11);cprintf("2. Display Record");
		gotoxy(15,13);cprintf("3. Search Record");
		gotoxy(15,15);cprintf("4. Delete Record");
		gotoxy(15,17);cprintf("5. Visualize the concept ");
		gotoxy(15,19);cprintf("6. Exit");

		gotoxy(15,21);textcolor(LIGHTGREEN);cprintf("Enter your choice : ");
		textcolor(WHITE);
		fflush(stdin);
		scanf("%d", &input);

		if(input==6) {
			clrscr();
			printf("\nExited from the menu , thanks for visiting");
			getch();
			break;
			}


			switch(input) {
			case 1:
			{	int i;
				clrscr();
				printf("Adding function activating soon...");
				//dot animation
				for(i=0;i<3;i++){
					delay(400);
					printf(".");
					}
					delay(500);



				addrecord();
				break;
			}
			case 2:
			{
				int j;
				clrscr();
				printf("Display engine starting...");
				for(j=0;j<3;j++)
				{
					delay(400);
					printf(".");
					}
					delay(500);

				displayrecords();
				break;
			}
			case 3:
			{       int k;
				clrscr();
				printf("Search engine starting...");
				for(k=0;k<3;k++){
					delay(400);
					printf(".");
					}
					delay(500);
				searchroll();
				break;
			}
			case 4:
			{       int l;
				clrscr();
				printf("Deletion mechanism starting...");
				for(l=0;l<3;l++)
				{	delay(400);
					printf(".");
					}
					delay(500);

				deleterecords();
				break;
			}
			case 5:


			{       int m;
				clrscr();
				printf("Starting the visulaizer engine ");
				for(m=0;m<3;m++){
					delay(400);
					printf(".");
					}
					delay(500);

				visualizedLinkedList();
				break;
			}
			default:
				gotoxy(15,22);printf("Invalid Input!Press any key..");
				gotoxy(1,24);getch();
				break;
			}
		}
	}

void visualizedLinkedList() {
	int gd = DETECT, gm;
	struct StudentDetails *temp = head;
	int startX = 50;
	int startY = 150;
	char rollText[10];



	//start graphics mode
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");





	setcolor(YELLOW);
	outtextxy(180, 50, "DOUBLY LINKED LIST VISUALIZER");
	if(head==NULL) {
		setcolor(LIGHTRED);
		outtextxy(250,200, "Database is empty");
		}
	else{
		while(temp!=NULL) {
			setcolor(CYAN);
			rectangle(startX, startY, startX+90, startY+30);

			setcolor(YELLOW);
			line(startX+30, startY, startX +30, startY+30);
			line(startX+60, startY, startX+60, startY+30);

			setcolor(WHITE);
			outtextxy(startX +5, startY+10, "PR");
			outtextxy(startX+65, startY+10, "NX");

			sprintf(rollText, "%d", temp->roll);
			outtextxy(startX +35,startY+10, rollText);

			if(temp->next!=NULL) {
				setcolor(LIGHTGREEN);
				line(startX+90, startY+12, startX+130, startY+15);
				outtextxy(startX+120,startY+12,">");
				outtextxy(startX +95,startY + 12,"<");
				}

				startX = startX +130;

				if(startX>520) {
					startX = 50;
					startY = startY+80;
					}
				temp=temp->next;
				delay(400);
				}
			}

	setcolor(WHITE);
	outtextxy(180, 400, "Press any key to return to the Main Menu");

	getch();
	closegraph();

}

int main() {
	loadingscreen();
	displaymainmenu();
	exitscreen();
	return 0;
	}





