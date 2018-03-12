#include <netinet/in.h>

#include <string.h>
#include <stdio.h>

#include "address.h"

int main() {
  int listenfd = 0, connfd = 0;
  struct sockaddr_in serv_addr;

  char sendBuff[1025];
  time_t ticks;

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  memset(&serv_addr, '0', sizeof(serv_addr));
  memset(sendBuff, '0', sizeof(sendBuff)); 

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(PORT);

  int br = bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
  if(br != 0) {
    printf("lascou\n");
    return 1;
  }

  listen(listenfd, 10);

  connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);

  //ticks = time(NULL);
  //snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n", ctime(&ticks));
  strncpy(sendBuff, "Eita, arretado\n", 1025);
  write(connfd, sendBuff, strlen(sendBuff));

  close(connfd);

  return 0;
}
