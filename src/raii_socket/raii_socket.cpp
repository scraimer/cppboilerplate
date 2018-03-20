#include <unistd.h>
#include "raii_socket.h"

static const int invalid_socket = -1;

raii_socket::raii_socket() : _socket_fd(invalid_socket)
{
}

raii_socket::~raii_socket()
{
	if( _socket_fd != invalid_socket )
	{
		close( _socket_fd );
		_socket_fd = invalid_socket;
	}
}

