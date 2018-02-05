/* Exemple d'un client UDP qui envoie un message a un serveur via son port 
  Syntaxe de la commande :
cliudp nom_du_serveur port message
***********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

extern int h_errno;

struct sockaddr_in Sock = {AF_INET }; /* le reste est NUL !! */

int main(int N, char *P[])
{
int sid, n;
socklen_t ld;
struct hostent *h;

   /* verification des parametres */
   if (N != 4) {
      fprintf(stderr,"Utilisation : %s nom_du_serveur port message\n",P[0]);
      return 1;
   }
   /* creation du socket */
   if ((sid = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
      perror("socket"); return 2;
   }
   /* initialisation de la structure Sock avec l'add. IP et le port du serveur*/
   Sock.sin_port = htons(atoi(P[2]));
   /* interrogation du reseau (DNS et autres) pour obtenir l'IP du serveur */
   if ((h=gethostbyname(P[1])) == NULL) {
      fprintf(stderr,"gethostbyname : erreur %d !\n",h_errno); return 3;
   }
   /* mise en place de l'adresse IP du serveur dans Sock */
   bcopy((void*)h->h_addr,(void*)&Sock.sin_addr,h->h_length);
   ld = (socklen_t)sizeof(Sock);
   if (sendto(sid,(void*)P[3],(size_t)strlen(P[3]),0,(struct sockaddr*)&Sock,ld)
      < 0) perror("sendto");
   else printf("Message envoye !!\n");
}

