/*
 * =====================================================================================
 *
 *       Filename:  json_test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017/02/15 16时44分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chen Xi (happyleaf), happyleaf.cx
 *   Organization:  
 *
 * =====================================================================================
 */


#include    <stdio.h>
#include    <stdlib.h>
#include <json/json.h>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>
using namespace std;

int main(int argc, char *argv[]) {
    char *json = " \
{ \n\
    \"encoding\" : \"UTF-8\", \n\
     \n\
    \"plug-ins\" : [ \n\
        \"python\", \n\
        \"c++\",  \n\
        \"ruby\" \n\
        ], \n\
         \n\
    \"indent\" : {  \"length\" : 3, \"use_space\": true } \n\
}\n";
    Json::Value root(json);
    cout<<root.asString()<<endl;
//    cout<<(root.get("encoding","UTF-8").asString())<<endl;
//    string a = root["encoding"].asString();
    Json::Reader reader;

    if (!reader.parse(json, json + strlen(json), root, false)) {
        return -1;
    }
    cout<<(root.get("encoding","UTF-7").asString())<<endl;
    string a = root["encoding"].asString();
    root["big"] = "new";
    Json::Value child = root;
    root["child"] = child;
    Json::StyledWriter sw;
    cout<<sw.write(root)<<endl;

    //read from file
    ifstream ifs;
    ifs.open("testjson.json");
    assert(ifs.is_open());
    Json::Value root2;
    if (!reader.parse(ifs, root2, false))
    {
        return -1;
    }
    string name = root2["name"].asString();
    cout<<"parse from file ,name is["<<name<<"]"<<endl;
    Json::Value age = root2.get("age", 2);
//    Json::Value age = root.["age"].asInt()
    cout<<"parse from file ,age is["<<age.asInt()<<"]"<<endl;
    cout << root2["name"].asString()<<endl;
    root2["aaa"]="222";
    cout << root2["aaa"].asString()<<endl;
    cout<<sw.write(root2)<<endl;

//    root2["new"] = "hello world!";

    return EXIT_SUCCESS;
}               /* ----------  end of function main  ---------- */
