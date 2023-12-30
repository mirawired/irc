#include "Server.hpp"

void Server::processPing(int fd, const std::vector<std::string> &tokens) {
	if (tokens.size() <= 1) {
		serverReply(fd, "", ERR_NOORIGIN);
	} else if (tokens[1] != serverName) {
		serverReply(fd, "", ERR_NOSUCHSERVER);
	} else {
		std::string pong = ":42.IRC PONG " + tokens[1];
		serverReply(fd, pong, PONG);
	}
}