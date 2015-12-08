#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "raii_socket.h"

// Just construct and destruct an instance
TEST(raii_socket_test, ctor_dtor)
{
	raii_socket s;
}

