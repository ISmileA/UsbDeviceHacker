#pragma once
#include <iostream>
using namespace std;

class ClientResponse{

public:
    string error(string reason){
        return ("{\"status\":\"error\",\"reason\":\""+reason+"\"}");
    }
    std::string nice(){
        return "{\"status\":\"ok\"}";
    }
};