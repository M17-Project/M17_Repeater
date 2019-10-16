#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

FILE *fp;
uint8_t c=0;
uint8_t cnt=0;
uint8_t rx_buff[100];

//UDP
struct sockaddr_in servaddr, cliaddr;

int main(int argc, char *argv[])
{
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 
	memset(rx_buff, 0, 100);
	
	servaddr.sin_family = AF_INET; //IPv4 
	servaddr.sin_addr.s_addr = inet_addr(argv[1]);//INADDR_ANY; 
	servaddr.sin_port = htons(atoi(argv[2])); 
	bind(sockfd, (const struct sockaddr*)&servaddr, sizeof(servaddr));

	fp = fopen("/dev/ttyS0", "rb"); //sudo stty -F /dev/ttyS0 115200 raw

	while(1)
	{
		if(fread(&rx_buff[cnt], 1, 94, fp)==94)
		{
			if(rx_buff[0]=='A')
				//cnt++;
			//if(cnt==94)
			{
				//uint32_t id_from=(rx_buff[20]<<16) | (rx_buff[21]<<8) | rx_buff[22];
				//uint32_t id_to=(rx_buff[23]<<16) | (rx_buff[24]<<8) | rx_buff[25];
				//uint16_t frame_num=((rx_buff[1]&0x0F)<<8) | rx_buff[2];
				
				//printf("%d->%d\n", id_from, id_to);
				//if(!(frame_num%10))
					//printf("%d\n", frame_num);
				sendto(sockfd, &rx_buff[35+1], 16, MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr));
				//usleep(40000);
				//sendto(sockfd, "\n", 2, 
				//	MSG_CONFIRM, (const struct sockaddr *) &servaddr,  
				//	sizeof(servaddr));	
				//memset(rx_buff, 0, 100);
				//cnt=0;
			}
		}

		//fp = fopen("/dev/ttyS0", "wb");
      //fwrite(argv[1], 1, strlen(argv[1]), fp);
		//fclose(fp);
      //sleep(1);
	}

    return 0;
}
