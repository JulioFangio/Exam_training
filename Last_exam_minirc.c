#include <unistd.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <netinet/in.h>

// Structure pour représenter un client
typedef struct s_client {
    int id;
    char msg[100000];
} t_client;

// Variables globales
int maxfd = 0, gid = 0;
char recv_buffer[120000], send_buffer[120000];
t_client clients[1024];
// Définit les ensembles de descripteurs de fichiers pour les entrées/sorties et les descripteurs de fichiers actuels
fd_set read_set, write_set, current;

// Fonction pour afficher un message d'erreur et quitter
void err(char *msg)
{
    if (msg)
        write(2, msg, strlen(msg));
    else
        write(2, "Fatal error", 11);
    write(2, "\n", 1);
    exit(1);
}

// Fonction pour envoyer un message à tous les clients sauf un
void send_to_all(int except)
{
    for (int fd = 0; fd <= maxfd; fd++)
    {
        if (FD_ISSET(fd, &write_set) && fd != except)
            if (send(fd, send_buffer, strlen(send_buffer), 0) == -1)
                err(NULL);
    }
}

int main(int ac, char **av)
{
    // Vérifie le nombre d'arguments
    if (ac != 2)
        err("Wrong number of arguments");

    // Crée le socket du serveur 
    struct sockaddr_in serveraddr;
    // declare la taille de la structure
    socklen_t len;

    // Crée le socket du serveur viq la fonction socket en utilisant le protocole TCP(SOCK_STREAM) IPV4 via AF_INET et stocke le descripteur de fichier dans serverfd
    int serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd == -1) err(NULL);
    maxfd = serverfd;

    // Initialise les ensembles de descripteurs de fichiers
    // FD_ZERO met à zéro l'ensemble de descripteurs de fichiers
    FD_ZERO(&current);
    // FD_SET ajoute un descripteur de fichier serverfd à l'ensemble des descripteurs de fichiers current ce qui signifie que serverfd est surveillé pour les entrées/sorties
    FD_SET(serverfd, &current);
    // bzero met à zéro la mémoire de clients
    bzero(clients, sizeof(clients));
    // bzero met à zéro la structure serveraddr pour eviter toute donee residuelle
    bzero(&serveraddr, sizeof(serveraddr));

    // Configure l'adresse du serveur
    // sin8_family est le type de protocole utilisé et est égal à AF_INET pour IPV4
    serveraddr.sin_family = AF_INET;
    // sin_addr.s_addr est l'adresse IP du serveur et est égal à INADDR_ANY pour accepter les connexions de n'importe quelle adresse IP
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    // sin_port est le port du serveur et est égal à atoi(av[1]) pour convertir le premier argument en entier
    serveraddr.sin_port = htons(atoi(av[1]));

    // Lie et écoute sur le socket du serveur
    // bind lie le socket du serveur à l'adresse du serveur et listen écoute les connexions entrantes sur le socket du serveur jusqu'à 100 connexions
    if (bind(serverfd, (const struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1 || listen(serverfd, 100) == -1)
        err(NULL);

    while (1)
    {
        // Copie les ensembles de descripteurs de fichiers
        read_set = write_set = current;
        // select surveille les entrées/sorties des descripteurs de fichiers surveillés et bloque jusqu'à ce qu'une entrée/sortie soit prête
        if (select(maxfd + 1, &read_set, &write_set, 0, 0) == -1) continue;

        for (int fd = 0; fd <= maxfd; fd++)
        {
            // Vérifie si le descripteur de fichier est prêt pour la lecture
            if (FD_ISSET(fd, &read_set))
            {
                // Vérifie si le descripteur de fichier est celui du serveur
                // Cette partie sert a accepter une nouvelle connexion client
                if (fd == serverfd)
                {
                    // Accepte une nouvelle connexion client
                    int clientfd = accept(serverfd, (struct sockaddr *)&serveraddr, &len);
                    if (clientfd == -1) continue;
                    if (clientfd > maxfd) maxfd = clientfd;
                    clients[clientfd].id = gid++;
                    FD_SET(clientfd, &current);
                    // Met le message suivant dans le buffer send_buffer qui sera ensuite envoyé à tous les clients dans la fonction send_to_all
                    sprintf(send_buffer, "server: client %d just arrived\n", clients[clientfd].id);
                    send_to_all(clientfd);
                    break;
                }
                // Sinon, le descripteur de fichier est celui d'un client existant
                else
                {
                    // Reçoit des données d'un client existant
                    int ret = recv(fd, recv_buffer, sizeof(recv_buffer), 0);
                    if (ret <= 0)
                    {
                        // Le client a quitté
                        sprintf(send_buffer, "server: client %d just left\n", clients[fd].id);
                        send_to_all(fd);
                        FD_CLR(fd, &current);
                        close(fd);
                        break;
                    }
                    else
                    {
                        // Traite les données reçues
                        for (int i = 0, j = strlen(clients[fd].msg); i < ret; i++, j++)
                        {
                            clients[fd].msg[j] = recv_buffer[i];
                            if (clients[fd].msg[j] == '\n')
                            {
                                clients[fd].msg[j] = '\0';
                                sprintf(send_buffer, "client %d: %s\n", clients[fd].id, clients[fd].msg);
                                send_to_all(fd);
                                bzero(clients[fd].msg, strlen(clients[fd].msg));
                                j = -1;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    return (0);
}
