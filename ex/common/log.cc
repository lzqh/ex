#include "common/log.h"
#include <iostream>
namespace ex{
namespace common{

bool InitLog(const char* argv)
{
	// 设置可以缓冲日志的最大秒数，0指实时输出
	FLAGS_logbufsecs = 0;
	// 设置最大日志文件大小（以MB为单位）
	FLAGS_max_log_size = 10;
    FLAGS_log_dir ="/tmp/";
	 
    #if NDEBUG
		std::cout << "Build-RELASE" << std::endl;
		FLAGS_alsologtostderr = false;
	#else
		std::cout << "Build-DEBUG" << std::endl;
		//设置日志消息除日志文件之外同时输出到标准输出
		FLAGS_alsologtostderr = true;
		//设置记录到标准输出的颜色消息（如果终端支持）
		FLAGS_colorlogtostderr = true;
	#endif
    google::InitGoogleLogging(argv);
	return true;

}

void ShutdownLog()
{
    google::ShutdownGoogleLogging();  
}

}
}