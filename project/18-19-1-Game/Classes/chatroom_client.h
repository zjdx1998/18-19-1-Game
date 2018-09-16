#pragma once
#include<iostream>
using std::cout;
using std::endl;

#define BUFFER_SIZE 1024
#define MAX_SOCKET_AMOUNT 4
#define CLOCK_TIME boost::posix_time::milliseconds(100)
#include<boost/thread.hpp>
#include<boost/asio.hpp>
#include<boost/smart_ptr.hpp>
#include<boost/ref.hpp>
#include<boost/bind.hpp>
#include<iostream>
#include<boost/asio/steady_timer.hpp>
#include<boost/asio/system_timer.hpp>
#include<boost/asio/high_resolution_timer.hpp>
#include<string>
#include<boost/function.hpp>
#include<vector>
#include<boost/atomic.hpp>
#include <sstream>
#include <boost/function.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>
#include "chat_message.h"
#include <list>
#include "cocos2d.h"

using std::list;
using namespace boost::asio;
using boost::system::error_code;
using ip::tcp;

class ChatroomClient
{
	typedef boost::shared_ptr<ip::tcp::socket> sockptr;
	typedef boost::shared_array<char> buffers;
	typedef boost::shared_ptr<ChatMessage> msg_ptr;
	typedef list<boost::shared_ptr<ChatMessage>> msglist;
	typedef boost::shared_ptr<boost::asio::streambuf> buffer;


private:
	static ChatroomClient* instance;
	io_service& io;
	sockptr sock;
	boost::asio::streambuf buf;
	boost::function<void(msg_ptr)> on_recieve;
	bool is_on_recieve_setted;
	bool is_connected;
	msglist ml;


public:
	/*
	** ���캯����
	** ����1��io_servce
	*/
	ChatroomClient(io_service &io_);;

	/*
	** ����tcp����
	** ֮����Ҫio_serce.poll()
	*/
	void start(std::string ipv4);
	void read_thread();
	void timing_thread_func();
	void timer_handler(boost::system::error_code ec, deadline_timer * timer);
	;
	
	/*
	** ����һ����Ϣ
	*/
	void post(ChatMessage msg);

	void postToServer();

	void close();
	/*
	** ���ûص�����
	*/
	void set_on_recieve(boost::function<void(msg_ptr)> call_back_func);

	// use only for debug
	//you are not supposed to use this
	void post_helloworld();

	void write_handler(boost::system::error_code ec, string * str);

	static ChatroomClient* get_instance();



private:

	void connect_handler(boost::system::error_code ec);
	void read();
	void call_callback(msg_ptr mp);
	void read_handler(boost::system::error_code ec, size_t bites_trans);
	
};

/*
** ����ǻص�������ʾ��
** ÿ��������Ϣ����ʱ�ͻ�����������
** mp����Ϣ��ChatMessage��ָ�룬
*/
void client_message_listener(boost::shared_ptr<ChatMessage> mp);

/*
** �������������
** ����1���ص�����
** ���鿪һ�����߳���ִ�б�����
*/
ChatroomClient* client_start(std::string ipv4, boost::function<void(boost::shared_ptr<ChatMessage>)> on_recieve);
