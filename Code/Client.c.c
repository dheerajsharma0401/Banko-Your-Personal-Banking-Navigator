//Client Side



#include<stdio.h>//STD I/O
#include<stdlib.h>//LIB OPERATIONS
#include<string.h>//STRING OPERATIONS
#include<sys/types.h>//DIFFERENT TYPES OF DATA TYPES
#include<sys/socket.h>//
#include<arpa/inet.h> //MICRO DEFINE OR FUNCTION DEFINE
#include  <sys/socket.h>//SYSTEM CALLS
#include<netinet/in.h>/* Provides support for 3rd party protocol stack*/
void main(void)
{int clifd,n;
	int bytesReceived=0;
	struct sockaddr_in clientaddr;
	char recvBuff[3000];
 
	//socket
 
	clifd=socket(AF_INET,SOCK_STREAM,0); //0 indicates optional. AF :- All families
	if(clifd==-1)
		perror("\n Socket is not created.");
	else
		printf("\n Socket created successfully.");
 
	//sockaddr_in
 
	clientaddr.sin_family=AF_INET; //sin:- sockaddr_in
	clientaddr.sin_addr.s_addr=inet_addr("10.0.2.15");
	clientaddr.sin_port=htons(3848);//hostbyte order to network byte order conversion
 
	// bind
 
	if(bind(clifd,(struct sockaddr *)&clientaddr,sizeof(clientaddr))==-1)
		perror("\n Bind unsuccessful");
	Else	
		printf("\n Bind successful.");
 
	//connect
 
	if(connect(clifd,(struct sockaddr *)&clientaddr,sizeof(clientaddr))==-1) //clientaddr must have the values of server.
		perror("\n Connection failed ");
	else
		printf("\n Connection established ");
 
	
 
         int i=0;
	printf("\n**WELCOME TO BANKO**\n");
	printf("\n\t\nTo which of the following Landmarks you are closest:");
	printf("\n1:NEAR Shivajinagar\n");
	printf("\n2:NEAR ShivajiChowk(Hinjewadi)\n");
	printf("\n3:NEAR Bhartyavidhyapeeth\n");
	printf("\n4:EXIT\n");
	printf("\nSelect nearest choice of your current location\n");
	printf("\n\n\n\t\t\tBANKO---BANKO---BANKO");
 
	  int choice;
	  printf("\n\nEnter your choice::");
      scanf("%d",&choice);
switch(choice)
{
case 1:
printf("So you are near Shivaji Nagar");
break;
 
case 2:
printf("So you are near ShivajiChowk(Hinjewadi)");
break;
case 3:
printf("So you are near BhartiyaVidhyapeeth");
 
}
      n=write(clifd,&choice,sizeof(int));
 
 
	   while((bytesReceived = read(clifd, recvBuff, 3000)) > 0)
    {
        printf("\nBytes received %d\n",bytesReceived);
        // recvBuff[n] = 0;
       // fwrite(recvBuff, 1,bytesReceived,fp);
        printf("%s \n", recvBuff);
    }
	close(clifd);
 
}
