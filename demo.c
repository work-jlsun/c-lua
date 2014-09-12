/**
 * make: gcc -o a.out demo.c  -I/usr/include/lua5.1  -llua5.1
 * brief: lua虚拟机直接执行字符串中的lua源代码  
 */
 
#include <lua.h>       //Lua语言解析器
#include <lualib.h>    //Lua标准库
#include <lauxlib.h>   //Lua辅助工具


char *code = "for i=0,5 do print(\"\'Hello, World\'\") end";

int main(int argc, char * argv[]) {
    lua_State *s = luaL_newstate();  //新建lua虚拟机
    luaL_openlibs(s);               //打开lua附加库
    luaL_dostring(s,code);          //执行字符串中的源代码
    lua_close(s);                   //关闭虚拟机
    return 0;
}


