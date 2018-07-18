#include <iostream>
#include <signal.h>
#include <vector>
#include <string>
#include "TCPClient.h"

TCPClient tcp;

void sig_exit(int s)
{
	tcp.exit();
	exit(0);
}

int main(int argc, char *argv[])
{
	signal(SIGINT, sig_exit);

       // tcp.setup("218.192.168.170",20000);
        tcp.setup("127.0.0.1",20000);
	string str;
	string  str_sum = "";
while(1)
{
	        cin>>str_sum;
		//str_sum.push_back(str);
		//continue;
		//str_sum += str;
		
		//srand(time(NULL));
		//tcp.Send(to_string(rand()%25000));
		tcp.Send(str_sum);
		string rec = tcp.receive();
		if( rec != "" )
		{
			cout << "Server Response:" << rec << endl;
		}
	        //str_sum.clear();
		//vector<string>().swap(str_sum);
	//	str_sum = "";
		sleep(1);
 }
	return 0;
}
