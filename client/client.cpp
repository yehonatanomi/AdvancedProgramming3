#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "Knn.h"

using namespace std;


int main() {

    string unclassifiedN ;
    string outfileN ;
    cin>>unclassifiedN;
    cin>>outfileN;
    list<flower> unclassified;
    flowerLFromPath(&unclassified, unclassifiedN);
    ///sockt
    const char *ip_address = "127.0.0.1";
    const int port_no = 5555;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
///connect
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
    ///what to send
    string s = fromLtoS(unclassified);
    char data_addr[4096];
    strcpy(data_addr, s.c_str());
    int data_len = strlen(data_addr);
    ///send
    int sent_bytes = send(sock, data_addr, data_len, 0);
    if (sent_bytes < 0) {
        // error
    }
///recv
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        // connection is closed
    } else if (read_bytes < 0) {
        // error
    } else {
        string s(buffer);
        list<flower> classified = fromStoL(s);
        outFile(classified,outfileN);
        cout<<"success"<<endl;
    }
    close(sock);


    return 0;
}


