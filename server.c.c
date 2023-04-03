//UDP Socket to create half dublex program or Chat Program in UDP
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<unistd.h>

int main(){
system("clear");
int sendfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
if(sendfd==-1)
{
perror("Socket creation failed\n");
exit(0);
}
struct sockaddr_in server,client;
server.sin_family=AF_INET;
server.sin_port=htons(5000);
server.sin_addr.s_addr=INADDR_ANY;
char snd[50],rcv[50];
while(1)
{
printf("Enter the message which you want to send to receiver: ");
gets(snd);
int size=sizeof(client);
sendto(sendfd,snd,strlen(snd),0,(struct sockaddr*)&server,sizeof(server));
if(strcmp(snd,"exit")==0)
break;
int len=recvfrom(sendfd,rcv,sizeof(rcv),0,(struct sockaddr*)&client,&size);
rcv[len]='\0';
if(strcmp(rcv,"exit")==0)
break;
printf("Message from receiver is that: %s\n",rcv);
}
close(sendfd);
}

