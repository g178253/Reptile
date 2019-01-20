#include "pch.h"
#include "DoubanReptile.h"

void DoubanReptile::print()
{
	auto r = generate_result();
	std::cout << r;
}

string DoubanReptile::get_url()
{
	return string{ "www.douban.com" };
}

string DoubanReptile::get_command()
{
	auto r = "GET /group/10658/ HTTP/1.1\r\n"
		"Host: www.douban.com\r\n"
		"Connection: keep-alive\r\n"
		"Upgrade-Insecure-Requests: 1\r\n"
		"User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36\r\n"
		"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\n"
		"Referer: https://www.douban.com/group/\r\n"
		"Accept-Encoding: gzip, deflate, br\r\n"
		"Accept-Language: zh-CN,zh;q=0.9\r\n";
	return r;
}
