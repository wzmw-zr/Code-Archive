/*************************************************************************
	> File Name: 7.smart_ptr.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月17日 星期一 23时25分12秒
 ************************************************************************/

#include <string>
#include <iostream>
#include <memory>
#include <cassert>
#include <vector>
using namespace std;

const int CAP_NUM = 16;
class Object
{
public:
    string str_object;
	static shared_ptr<Object> getObj();
protected:
	Object(){}

};
struct Position:Object
{
	bool used;
	Position* next;
} buffer[CAP_NUM];
Position* unused ;
Object* createObj()
{
    if (unused == nullptr) return nullptr;
    Position *ret = unused;
    //cout << ret << " " << ret->next << endl;
    unused = unused->next;
    return (Object *) ret;
}
bool destroyObj(Object* obj)
{
    //cout << obj << endl;
    Position *temp = reinterpret_cast<Position *>(obj);
    //cout << obj << endl;
    //cout << buffer << endl;
    //cout << (Position *) obj - (Position *) buffer << endl;
    if ((temp - (Position *) buffer < 0) || (temp - (Position *) buffer > 15)) {
        //cout << "invalid_address" << endl;
        return false;
    }
    temp->used = false;
    temp->next = unused;
    unused = temp;
    return false;
}
shared_ptr<Object> Object::getObj()
{
	shared_ptr<Object>obj(createObj(), destroyObj);
	return obj;
}
void bufferInit()
{
	unused = &buffer[0];
	for (int i = 0; i < CAP_NUM-1; i++)
	{
		buffer[i].used = false;
		if (i!=CAP_NUM-1)
		{
			buffer[i].next = &buffer[i + 1];
		}
	}
	buffer[CAP_NUM - 1].next = NULL;
    for (int i = 0; i < CAP_NUM; i++) {
        cout << buffer + i << " " << buffer[i].next << endl;
    }
}
void assert_obj(Object* obj)
{
	auto destroy_result = destroyObj(obj);
	assert(destroy_result == false);
}

int main()
{
	bufferInit();
	{
		Object* obj = buffer - sizeof(Position);
        //cout << obj << endl;
		assert_obj(obj);
	}

	{
		int getAddr;
		Object* obj = reinterpret_cast<Object*>(&getAddr);
		assert_obj(obj);
	}

	{
		Object* obj = nullptr;
		assert_obj(obj);
	}

	{
		Object* obj = buffer + CAP_NUM + 1;
		assert_obj(obj);
	}

	{
		Object* obj = createObj();
		destroyObj(obj);
		assert_obj(obj);
	}

	{
		vector<shared_ptr<Object>> vec_obj;
		for (int i = 0; i < CAP_NUM; i++)
		{
			auto p = Object::getObj();
			if (p != nullptr)
			{
				p->str_object = "" + to_string(i);
				cout << p->str_object << endl;
			}
			vec_obj.push_back(p);
            cout << vec_obj.size() << endl;
		}
		auto p_blank = Object::getObj();
        //cout << p_blank << endl;
		//assert(p_blank == nullptr);

	}
	cout << "all tests done!" << endl;
	return 0;
}
