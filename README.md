# Advanced Programming - Task 3
On this task we upgraded our last server - client interaction program, now, the client has several options when it comes to his communication with the server.

Again, the connection between the server and the client is made by the TCP protocol.

# How we implemented
1. The client part and server part are being seperated.
2. We used the "commander" design pattern (for commands handling in the server).
3. Explanation about the command classes:
 - The base command class is an abstract class which has access to client data and IO.
 - Each subclass of the base class implements an execution by its own way.
 - The commands are being put in a vector (in the same order as the menu).

# How to run
In order to run the project you will need to use a Linux distribution:

1. You need to clone the repository:
    
    $ git clone https://github.com/yehonatanomi/AdvancedProgramming3
2. Compile the project:

   $ mkdir build

   $ cd build

   $ cmake ..

   $ make
3. Run the server:

   $ cd server

   $ ./Server
4. For each client, open a new window of your linux distribution and run the client:

   $ cd client

   $ ./Client


# Important Note:
We worked together through Yehonatan's computer so all commits except the readme commit were made by his user. 

Functions that were made by Alon has the comment "by alon" above them.