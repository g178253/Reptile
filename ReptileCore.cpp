#include "pch.h"
#include "ReptileCore.h"
#include "Net.h"

namespace Reptile
{
	using namespace std;

	string ReptileCore::generate_result()
	{
		auto url = get_url();
		auto cmd = get_command();
		auto src = ts.get_source(url, cmd);
		tp.execute(src);
		return src;
	}

	void TextProcessor::execute(string& src)
	{
		cout << src;
	}

	TextSource::TextSource() : pNet{ new Net{} } {}
	TextSource::~TextSource() {}

	string TextSource::get_source(const string& url, const string& cmd)
	{
		pNet->start(url, 80);
		pNet->send_command(cmd);
		auto r = pNet->get_string();
		pNet->stop();
		return r;
	}
}