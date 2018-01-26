/*************************************************
* exemple de client UDP
* socket non connecte 
*************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>


#define LBUF 1024

struct sockaddr_in Sock = {AF_INET}; /* le reste est nul */

int main(int N, char*P[])
{
int sid, lg, n;
char buf[LBUF];
struct sockaddr_in Srec;
struct hostent *h;

/* on veut que l'utilisateur passe en parametres :
  - le nom du serveur
  - le port
  - le message
**************/
    if (N != 4) {
     fprintf(stderr,"Utilisation : %s nom_serveur port message !\n",
      P[0]);
     return 1;
    }
    /* creation du socket */
    if ((sid = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP)) < 0) {
        perror("socket");
        exit(2);
    }
    /* recuperation de l'adresse IP du serveur */
    if ((h=gethostbyname(P[1])) == NULL ) {
      fprintf(stderr,"Adresse serveur non trouvee !\n");
      exit(3);
    }

    /* MAJ de la structure de connexion */
    /* adresse IP */
    bcopy((void*)(h->h_addr),(void*)&(Sock.sin_addr), h->h_length);
    /* port */
    Sock.sin_port = htons(atoi(P[2]));
    /* envoi du message */
    if (sendto(sid,P[3], strlen(P[3]),0,(struct sockaddr*)&Sock,sizeof(Sock)) < 0) perror("sendto");
    else printf("Message envoye !\n");
    close(sid);
    return 0;
}
