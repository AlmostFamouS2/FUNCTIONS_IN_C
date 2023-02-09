int send_string(int sockfd, unsigned char *buffer) {
	int sent, to_send;
	to_send = strlen(buffer);

	while(to_send > 0) {
		sent = send(sockfd, buffer, to_send, 0);

		if(sent == -1)
			return 0;

		to_send -= sent;
		buffer += sent;  // Pula todos os bytes que ja foram enviados e aponta para o atual nao enviado.
	}
		return 1;
}

int recv_line(int sock, unsigned char *buf) {
	#define EOL "\r\n"
	#define EOL_SIZE 2
		unsigned char *ptr;
		int eol_matched = 0;

		ptr = buf;
		while(recv(sock, ptr, 1, 0) == 1) {  // Read a single byte 
			if(*ptr == EOL[eol_matched]) {
				eol_matched++;
				if (eol_matched == EOL_SIZE) {
					*(ptr+1-EOL_SIZE) = '\0';
					return strlen(buf);
				}
			}
			else {
				eol_matched = 0;
				ptr++;
			}
		}
 return 0;
}
