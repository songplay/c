/*
 * client: socket tcp
 * using send() and recv()
 * 1/25/2017
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#define	SIZE	512

main(int argc, char *argv[])
{
	int	tcpfd;
	size_t	size;
	int	ret;
	int	k, n;
	int	port;
	struct sockaddr_in		saddr;
	struct hostent  *server;
	char	buf[SIZE]  = "Hello";
	char	server_name[64];

	/* 1.  open socket */
	tcpfd = socket(AF_INET, SOCK_STREAM, 0);
	if (tcpfd < 0) {
		perror("socket: fails");
		exit (EXIT_FAILURE);
	}else
		printf("socket: ok\n");

	/* 2. conect to server */
	size = sizeof(saddr);
	bzero((char *) &saddr, size);

	saddr.sin_family= AF_INET;

	if (argc > 1)
		strcpy(server_name, argv[1]);

	server = gethostbyname(server_name);
	if (server == NULL){
		saddr.sin_addr.s_addr = inet_addr(server_name);
		if (saddr.sin_addr.s_addr == INADDR_NONE) {
			fprintf(stderr, "Bad name/address: %s\n", server_name);
			exit(EXIT_FAILURE);
		}
	} else
		bcopy((char *) server->h_addr, 
			(char *) &saddr.sin_addr.s_addr, server->h_length);

	if (argc > 2)
		port = atoi(argv[2]);
	else {
		port = 1100;
		printf("Set port# to default: %d\n",port);
	}

	saddr.sin_port = htons(port);

	ret = connect(tcpfd, (struct sockaddr *)&saddr, size);
	if (ret < 0) {
		fprintf(stderr, "connect to %s:%d: fail\n", server_name, port);
		exit (EXIT_FAILURE);
	} else
		printf("connect to %s: ok\n", server_name);

	/* 3. transmit data */
	for(k=0; k<3; k++){
		// read from console
		printf("TX: ");
		bzero(buf, SIZE);
		fgets(buf, SIZE -1,  stdin);

		size = strlen(buf);
		n = send(tcpfd, buf, size, 0);
		printf("Request to  send %d bytes; Sent %d bytes\n", size, n);
	
		/* receive data */
		bzero(buf, SIZE);
		size = recv(tcpfd, buf, SIZE, 0);
		printf("RX: %s\n", buf);
	}

	/* close it */
	close(tcpfd);
}
