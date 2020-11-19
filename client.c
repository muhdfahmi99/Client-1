#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

int socd;
struct sockaddr_in server;
socd = socket(AF_INET, SOCK_STREAM, 0);
char *hantar;
char reply[4000];

if (socd == -1) {
printf("Tak boleh create socket");
}

server.sin_addr.s_addr = inet_addr("103.102.166.226");
server.sin_family = AF_INET;
server.sin_port = htons(80);

if(connect(socd, (struct sockaddr *)&server, sizeof(server))<0) {
puts("connect error");
return 1;
}

puts("Connected \n");

printf("Value yang disimpan: %d\n", socd);

hantar = "GET / HTTP1.1\r\n\r\n";

if(send(socd, hantar, strlen(hantar), 0) <0) {
printf("Tak berjaya hantar");
return 1;
}

puts("Data has been sent\n");

if(recv(socd, reply, 4000, 0)<0) {
printf("Tak berjaya baca");
}

puts("This server reply: \n");
puts(reply);

close(socd);
return 0;
}
