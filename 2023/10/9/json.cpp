/*************************************************************************
	> File Name: json.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年10月09日 星期一 10时13分16秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <variant>
#include <memory>

struct Json {
  std::variant<
    std::monostate, 
    bool,
    int,
    double,
    std::string,
    std::vector<Json>,
    std::map<std::string, Json>
  > value;

  Json() : value(std::monostate{}) {}
  Json(bool val) : value(val) {}
  Json(int val) : value(val) {}
  Json(double val) : value(val) {}
  Json(const char * val) : value(std::string(val)) {}
  Json(const std::string & val) : value(val) {}
  Json(const std::vector<Json> &val) : value(val) {}
  Json(const std::map<std::string, Json> &val) : value(val) {}

  Json & operator = (bool val);
  Json & operator = (int val);
  Json & operator = (double val);
  Json & operator = (const char * val);
  Json & operator = (const std::string & val);
  Json & operator = (const std::vector<Json> &val);
  Json & operator = (const std::map<std::string, Json> &val);


  Json & operator [] (int index);
  Json & operator [] (const char *key);
  Json & operator [] (const std::string &key);
  // operator bool();
  // operator int();
  // operator double();
  // operator string();

  std::string to_string();
};

Json & Json::operator = (bool val) {
  value = val;
  return *this;
}
Json & Json::operator = (int val) {
  value = val;
  return *this;
}
Json & Json::operator = (double val) {
  value = val;
  return *this;
}
Json & Json::operator = (const char * val) {
  value = std::string(val);
  return *this;
}
Json & Json::operator = (const std::string & val) {
  value = val;
  return *this;
}
Json & Json::operator = (const std::vector<Json> &val) {
  value = val;
  return *this;
}
Json & Json::operator = (const std::map<std::string, Json> &val) {
  value = val;
  return *this;
}

Json & Json::operator [] (int index) {
  if (value.index() == 5) {
    auto & arr = std::get<5>(value);
    if (arr.size() > index)
      return arr[index];
    throw "index out of range !";
  }
  throw "value is not array !";
}

Json & Json::operator [] (const char *key) {
  std::string k(key);
  return (*this)[k];
}

Json & Json::operator [] (const std::string &key) {
  if (value.index() == 6) {
    auto & mp = std::get<6>(value);
    return mp[key];
  }
  throw "value is not map !";
}

std::string Json::to_string() {
  int index = value.index();
  std::string str;
  switch (index) {
    case 1: {
      str = std::get<bool>(value) ? "true" : "false";
    } break;
    case 2: {
      str = std::to_string(std::get<int>(value));
    } break;
    case 3: {
      str = std::to_string(std::get<double>(value));
    } break;
    case 4: {
      str = std::get<std::string>(value);
    } break;
    case 5: {
      std::vector<Json> &arr = std::get<std::vector<Json>>(value);
      str += "[";
      for (int i = 0; i < arr.size(); i++) {
        str += (i ? ", " : "");
        str += arr[i].to_string();
      }
      str += "]";
    } break;
    case 6: {
      std::map<std::string, Json> &mp = std::get<std::map<std::string, Json>>(value);
      str += "{\n";
      for (auto && [k, v] : mp)
        str += k + " : " + v.to_string() + "\n";
      str += "}";
    } break;
    default: {
    }break;
  }
  return str;
}

int main() {
  Json json = std::vector<Json>{"hello", "world"};
  json = std::map<std::string, Json>(
    {
      {"bool", "true"},
      {"int", 1},
      {"double", 1.23},
      {"string", "hello"},
    }
  );
  std::cout << json.to_string() << std::endl;
  json["int"] = 2;
  std::cout << json.to_string() << std::endl;
  Json t = json;
  t["json"] = json;
  std::cout << t.to_string() << std::endl;
  // Json json = {
  //   {"a", 1},
  //   {"b", 3.14},
  //   {"c", "hello"},
  //   {"d", true},
  // };
  return 0;
}
