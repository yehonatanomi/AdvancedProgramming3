#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "Knn.h"
string knnEuclidean(string s, string classifiedF,int k);
int main() {
    list<flower> unclassified;
    const int server_port = 5555;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    if (listen(sock, 8) < 0) {
        perror("error listening to a socket");
    }

    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sock,  (struct sockaddr *) &client_sin,  &addr_len);
    if (client_sock < 0) {
        perror("error accepting client");
    }
    char buffer[4096];
    char data_addr[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        cout<<"connection is closed"<<endl;
    }
    else if (read_bytes < 0) {
        cout<<"error read_bytes"<<endl;
    }
    else {
       string l (buffer);
        unclassified = fromStoL(l);
       string s = knnEuclidean(l,"classified.csv", 11);
       strcpy(data_addr, s.c_str());
    }

    read_bytes = sizeof (data_addr);
    int sent_bytes = send(client_sock, data_addr, read_bytes, 0);

    if (sent_bytes < 0) {
        perror("error sending to client");
    }
    cout<<"connection is closed"<<endl;
    close(sock);
    return 0;
}




string knnEuclidean(string s, string classifiedF,int k){
    list<flower> classified ,unclassified ;
    flowerL(&classified,"classified.csv");
    unclassified = fromStoL(s);
    list<flower> out[3];
    knn(classified,unclassified,k,out);
   return fromLtoS(out[0]);
}
