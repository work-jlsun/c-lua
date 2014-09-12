/**
 * make: gcc -o a.out demo.c  -I/usr/include/lua5.1  -llua5.1
 * brief:  
 */
 
#include <lua.h>       //Lua语言解析器
#include <lualib.h>    //Lua标准库
#include <lauxlib.h>   //Lua辅助工具



int main() {
    lua_State *s = luaL_newstate();
    luaL_openLibs(s);
    lua_dofile(s,"demo3.lua");

    lua_getglobal(s,"show");            
    lua_pushstring(s, "It is from C");
    lua_call(s, 1,1);
}
