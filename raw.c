#include <netinet/ip.h>

int main(){

	struct iphdr raw_ip;
		raw_ip.version = 0x4;
		raw_ip.ihl = 0x5;
		raw_ip.tos = 0x0;
		raw_ip.tot_len = (unsigned short )0x00ff; // 255 bytes packet
		raw_ip.id = (unsigned short)0x34f6;  // Random ID
		raw_ip.frag_off = 0x4000; // Don't fragment
		raw_ip.ttl = 0xff; // TTL = 255
		raw_ip.protocol = 0x11;  // 17 (UDP)
		raw_ip.saddr = (unsigned int)0x11111111; // 17.17.17.17
		raw_ip.daddr = (unsigned int)0xc8a80001; // 192.168.0.1
		//raw_ip.check
	return 0;
}
