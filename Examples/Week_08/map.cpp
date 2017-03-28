#include <map>


int main()
{
	std::map<std::string, widget*> widget_map;

	widget_map["foo"] = new widget();

	widget * w = widget_map["foo"];
	std::map<std::string, widget*>::iterator it = widget_map.find("foo");
	if(it == widget_map.end())
	{
		//no key foo
	}
	
}
