/*
 * client: lab 3
 * 1/25/2017
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>

#define	SIZE	1024

main(int argc,char *argv[])
{
	int	tcpfd;
	int	ret;
	size_t	size, len;
	char	txbuf[SIZE],  rcbuf[SIZE];
	struct sockaddr_in	saddr;

	// step 1, socket
	tcpfd = socket(AF_INET, SOCK_STREAM, 0);

	// 2. connect
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = inet_addr("192.168.1.106");
	saddr.sin_port = htons(1100);
	ret = connect(tcpfd, (struct sockaddr *)&saddr, size);

	// 3. tx and rx
	bzero(txbuf, SIZE);
	send(tcpfd, txbuf, len, 0);

	bzero(rcbuf, SIZE);
	recv(tcpfd, rcbuf, len, 0);

	// 4. close it
	close(tcpfd);
}
