#ifndef RAII_SOCKET_H__
#define RAII_SOCKET_H__

class raii_socket
{
	private:
		int _socket_fd;

	public:
		raii_socket();
		virtual ~raii_socket();
};

#endif // ifndef RAII_SOCKET_H__

