I guess I want to try to implement a rudimentary ssh server. This attempt is in c

Useful knowledge:
- socket(2): returns file descriptor for reading and writing. Needs `open(2)` for reading and writing with `read(2)`/`recv(2)` or `write(2)`/`send(2)`. I don't yet remember the difference between those calls.

  `int socket(int domain, int type, int protocol)`
  - domain - communication domain, e.g. IPV4/6 or Bluetooth or a myriad of other interesting stuff
  - type - usually just SOCK_STREAM, other options for datagrams and raw protocol access
  - protocol - specifies protocol to be used within the type. Usually 0, as most types have 1 protocol

- gcc: preprocesses, compiles, assembles, and links
  - -c compile or assemble, but do not link. Creates .o files from input files
  - -o _file_
  - -E stop after preprocessing stage

- open(2)
  - opens a file for reading and returns a file descriptor
  - not for opening a socket fd, for files

- recv(2)
  - only differs from read(2) in that it allows for flags. With zero flags it is generally equivalent
 
- connect(2)
  - `int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);`
  - connects to socket on specified address
  - returns 0 on success, -1 on failure
  - client initiating connection with server
 
- bind(2)
  - assigns a name to the socket, i.e. attaching an address to a socket fd
  - see ip(7) for AF_INET details

- getaddrinfo(2)
  - man page contains example client and server
 
- ip(7)

- inet_ntop
  - converts network address binary to readable string
  - `const char *inet_ntop(int address_family, const void *restrict src, char dst[size], socklen_t size);`
  - places readable string into dst buffer
