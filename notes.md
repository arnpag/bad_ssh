I guess I want to try to implement a rudimentary ssh server. This attempt is in c

Useful knowledge:
- socket(2): returns file descriptor for reading and writing. Needs `open(2)` for reading and writing with `read(2)`/`recv(2)` or `write(2)`/`send(2)`. I don't yet remember the difference between those calls.
  int socket(int domain, int type, int protocol)
  - domain - communication domain, e.g. IPV4/6 or Bluetooth or a myriad of other interesting stuff
  - type - usually just SOCK_STREAM, other options for datagrams and raw protocol access
  - protocol - specifies protocol to be used within the type. Usually 0, as most types have 1 protocol
