#include <iostream>
#include <map>
#include <memory>

struct Object
{
	virtual void run() = 0;
};

struct Foo : public Object
{
	virtual void run() override
	{
		std::cout << "running foo algorithm\n";
	}
};

struct Bar : public Object
{
	virtual void run() override
	{
		std::cout << "running bar algorithm\n";
	}
};

struct Depth : public Object
{
	virtual void run() override
	{
		std::cout << "Running depth algorithm\n";
	}
};

struct Kruskal : public Object
{
	virtual void run() override
	{
		std::cout << "Running kruskal algorithm\n";
	}
};





struct ObjectTemplate
{
private:
	ObjectTemplate() {};

public:
	static ObjectTemplate *instance;

	std::map<std::string, std::unique_ptr<Object>> objectTemplates;

	void registerDefaultObjects()
	{
		registerObject("foo", new Foo);
		registerObject("bar", new Bar);
		registerObject("depth", new Depth);
		registerObject("kruskal", new Kruskal);
	}


	void registerObject(const std::string &s, Object *o)
	{
		objectTemplates[s] = std::unique_ptr<Object>(o);
	}

	Object *createObject(const std::string &s)
	{
		auto found = objectTemplates.find(s) != objectTemplates.end();
		if (!found)
			return nullptr;
		return objectTemplates[s].get();
	}

	static ObjectTemplate *getInstance()
	{
		if (!instance)
		{
			instance = new ObjectTemplate;
			instance->registerDefaultObjects();
		}
		return instance;
	}
};



struct Algorithm
{
	Object *proxy;

	Algorithm(const std::string &type)
	{
		setType(type);
	}

	void setType(const std::string &type)
	{
		proxy = ObjectTemplate::getInstance()->createObject(type);
	}

	void run() { if (proxy) proxy->run(); }
};




//std::map<std::string, std::unique_ptr<Object>> ObjectTemplate::objectTemplates;

ObjectTemplate *ObjectTemplate::instance = nullptr;


int main(int argc, char **argv)
{
	Algorithm a(argv[1]);

	a.setType("foo");
	a.run();

	a.setType("depth");
	a.run();

	return 0;
}

