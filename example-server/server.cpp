#include <iostream>
#include "TCPServer.h"

TCPServer tcp;

void * loop(void * m)
{
        pthread_detach(pthread_self());
	while(1)
	{
	srand(time(NULL));
//	char ch = 'a' + rand() % 26;
 //	string s(1,ch);
         string s = "thanks";
// cin>>s;
		string str = tcp.getMessage();
		if( str != "" )
		{
			cout << "Message:" << str << endl;
		
	                tcp.Send(s);
	            	tcp.clean();
		}
		
	usleep(1000);
	//	if(cin>>s)
		//{
		//	tcp.Send("server Message "+s);
		//	tcp.clean();
		//}

	}

	tcp.detach();
}

int main()
{
	pthread_t msg;
	tcp.setup(20000);
	if( pthread_create(&msg, NULL, loop, (void *)0) == 0)
	{
		tcp.receive();
	}
//	while(1)
//	{
//		string mess;
//		cin>>mess;
//		tcp.Send(mess);
//		sleep(1);
//	}

	return 0;
}
