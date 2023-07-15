import socket
def udp_client(port):
    host = input("Enter the server IP address: ")
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    print(f"Connected to server: {host}:{port}")
    while True:
        message = input("Client: ")
        client_socket.sendto(message.encode(), (host, port))
        response, server_address = client_socket.recvfrom(1024)
        print(f"Server: {response.decode()}")
        if message.lower() == "bye":
            print("Closing the connection.")
            break
    client_socket.close()
port = int(input("Enter the port number: "))
udp_client(port)